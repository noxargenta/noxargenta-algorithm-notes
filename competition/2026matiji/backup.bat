@echo off
setlocal enabledelayedexpansion

:: 设置输出文件名
set "output_file=all_code_backup.txt"

:: 如果旧的备份文件已存在，先删除它，避免重复合并
if exist "%output_file%" del "%output_file%"

echo 正在合并代码...

:: 遍历所有 cpp 文件
set "found=0"
for %%f in (*.cpp) do (
    set "found=1"
    echo ------------------------------------------ >> "%output_file%"
    echo 文件名: %%f >> "%output_file%"
    echo ------------------------------------------ >> "%output_file%"
    echo. >> "%output_file%"
    
    :: 将当前 cpp 文件内容追加到目标文件
    type "%%f" >> "%output_file%"
    
    echo. >> "%output_file%"
    echo. >> "%output_file%"
    echo 已处理: %%f
)

if %found%==0 (
    echo ? 错误：当前目录没找到 .cpp 文件
) else (
    echo.
    echo ? 完成！所有代码已合并至: %output_file%
)

pause
