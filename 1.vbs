Set ws = CreateObject("WScript.Shell")
' 获取当前文件夹的路径
currentPath = CreateObject("Scripting.FileSystemObject").GetParentFolderName(WScript.ScriptFullName)
batPath = currentPath & "\1.bat"

' 开始无限循环
Do
    ' 运行 bat 文件，0 代表完全隐藏窗口，True 代表等它执行完
    ws.Run "cmd.exe /c """ & batPath & """", 0, True
    
    ' 暂停 10 分钟 (10分钟 * 60秒 * 1000毫秒 = 600000)
    WScript.Sleep 600000
Loop