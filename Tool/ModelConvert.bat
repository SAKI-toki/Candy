@echo off
set FBXCONV_PATH=D:\Candy\Tool\Model\ConvertFbx.exe

if "%2" == "" (
set OUT_NAME=%1
) else (
set OUT_NAME=%2
)
set IN_PATH=D:\Candy\RawData\Model\%1.fbx
set OUT_PATH=D:\Candy\Data\Win\Model\%OUT_NAME%.bin

echo fbx convert start
%FBXCONV_PATH% -i %IN_PATH% -o %OUT_PATH%
echo fbx convert end