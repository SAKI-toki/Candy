@echo off
set FONTCREATETEXTURE_PATH=D:\Candy\Tool\Font\CreateFontTexture.exe
set TARGET_TEXTURE=D:\Candy\RawData\Font\%1
set FONT_TEXTURE_PATH=D:\Candy\RawData\Font\Texture\%2.bmp
set OUTPUT_PATH=D:\Candy\Data\Win\Font\

echo font create texture start
%FONTCREATETEXTURE_PATH% %TARGET_TEXTURE% %FONT_TEXTURE_PATH% %OUTPUT_PATH%%2.bin
echo font create texture end
echo font texture convert start
D:\Candy\Tool\Texture\texconv.exe -ft dds -w 4096 -h 4096 -m 1 -f BC3_UNORM -y -o %OUTPUT_PATH%  %FONT_TEXTURE_PATH%
echo font texture convert end