@echo off
set COMPILER_PATH=D:\Candy\Tool\Shader\Compiler\dxc.exe
set TARGET_HLSL=D:\Candy\Program\Shader\%1.hlsl
set OUTPUT_PATH=D:\Candy\Data\Win\Shader\

echo vs start
call %COMPILER_PATH% %TARGET_HLSL% -T vs_6_0 -E vsMain -Fo %OUTPUT_PATH%%1.vso
echo vs end
echo ps start
call %COMPILER_PATH% %TARGET_HLSL% -T ps_6_0 -E psMain -Fo %OUTPUT_PATH%%1.pso
echo ps end
