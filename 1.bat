@echo off
:: 确保在后台运行时，系统能找准这个文件夹的位置
cd /d "%~dp0"

:: 添加、提交、推送
git add .
git commit -m "Auto Sync: %date% %time%"
git push origin main