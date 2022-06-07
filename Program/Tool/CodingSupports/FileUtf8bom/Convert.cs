using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace FileUtf8bom
{
    static class Convert
    {
        static void Main(string[] _args)
        {
            try
            {
                App(_args);
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }

        static void App(string[] _args)
        {
            foreach (var arg in _args)
            {
                RecursiveDirectory(arg);
            }
        }

        static void RecursiveDirectory(string _dir)
        {
            foreach (var dir in Directory.EnumerateDirectories(_dir))
            {
                RecursiveDirectory(dir);
            }

            foreach (var file in Directory.EnumerateFiles(_dir))
            {
                byte[] bytes;
                using (var fs = new FileStream(file, FileMode.Open, FileAccess.Read))
                {
                    bytes = new byte[fs.Length];
                    fs.Read(bytes, 0, bytes.Length);
                }
                var encoding = DetectEncodingFromBOM(bytes);
                if (encoding == Encoding.UTF8) continue;
                if (encoding == null) encoding = Encoding.GetEncoding("shift_jis");
                using (var sw = new StreamWriter(file, false, Encoding.UTF8))
                {
                    sw.Write(Encoding.UTF8.GetString(Encoding.UTF8.GetBytes(encoding.GetString(bytes))));
                }
            }
        }

        static Encoding DetectEncodingFromBOM(byte[] bytes)
        {
            if (bytes.Length < 2)
            {
                return null;
            }
            if ((bytes[0] == 0xfe) && (bytes[1] == 0xff))
            {
                //UTF-16 BE
                return new UnicodeEncoding(true, true);
            }
            if ((bytes[0] == 0xff) && (bytes[1] == 0xfe))
            {
                if ((4 <= bytes.Length) &&
                    (bytes[2] == 0x00) && (bytes[3] == 0x00))
                {
                    //UTF-32 LE
                    return new UTF32Encoding(false, true);
                }
                //UTF-16 LE
                return new UnicodeEncoding(false, true);
            }
            if (bytes.Length < 3)
            {
                return null;
            }
            if ((bytes[0] == 0xef) && (bytes[1] == 0xbb) && (bytes[2] == 0xbf))
            {
                //UTF-8
                return Encoding.UTF8;
            }
            if (bytes.Length < 4)
            {
                return null;
            }
            if ((bytes[0] == 0x00) && (bytes[1] == 0x00) &&
                (bytes[2] == 0xfe) && (bytes[3] == 0xff))
            {
                //UTF-32 BE
                return new System.Text.UTF32Encoding(true, true);
            }

            return null;
        }
    }
}
