@echo off
set CONVEXE_PATH=D:\Candy\Tool\Model\ConvertGltf.exe

if "%2" == "" (
set OUT_NAME=%1
) else (
set OUT_NAME=%2
)
set IN_PATH=D:\Candy\RawData\Model\%1.gltf
set OUT_PATH=D:\Candy\Data\Win\Model\%OUT_NAME%.bin

echo model convert start
%CONVEXE_PATH% -i %IN_PATH% -o %OUT_PATH%
echo model convert end