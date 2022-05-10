@echo off
set TEXCONV_PATH=D:\Candy\Tool\Texture\texconv.exe
set TARGET_TEXTURE=D:\Candy\RowData\Texture\%1
set OUTPUT_PATH=D:\Candy\Data\Win\Texture\

echo texconv start
%TEXCONV_PATH% -ft dds -w %2 -h %3 -m 1 -f %4 -y -o %OUTPUT_PATH% %TARGET_TEXTURE%
echo texconv end