快捷键
===============
搜索操作
----------------
	ctrl+r 历史记录 Enter 执行。 ctrl+j 重复
移动操作
----------------
	ctrl+f 右移动一个字符。 -->
	ctrl+b 左移动一个字符.  -->
	ctrl+a   ctrl+e 行首巷尾
删除操作
----------------
	ctrl+d	ritht one ch
	ctrl+h  left one ch
	ctrl+u  left to head
	ctrl+k  right to tail
	ctrl+w  word
命令切换
----------------
	ctrl+p     上一个
	ctrl+n	   下一个
others
----------------
	ctrl+y	插入最近删除的单词
	ctrl+c
	ctrl+d  当前操作转到后台
	ctrl+r 	clear
vim
----------------
vim自动补齐
ctrl+x ctrl+v ctrl+n ctrl+p

shell
----------------
###发现目标并执行操作。
		find Documents -mtime -30 -exec cp "{}" Backup \;

###文件中执行替换
		perl -pi-e 's/Beky/Rebecca/' mydocument.txt

###kill -l
		SIGTREM（15):请求一个进程停止，可以被忽略，用于保存进度，释放资源。
		SIGKILL（9）:立刻停止运行，未保存进度将丢失。

		kill SIGKILL PID  ==> kill -9 PID
		ps us 正在运行的应用。
###PKill
		允许正则表达式等匹配方法。可用进程名杀死进程。
		pkill firefox
###killall 
		同样使用进程名代替PID，
	
