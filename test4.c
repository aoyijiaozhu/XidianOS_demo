#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define M 80	//设置缓冲区大小

int main()
{
	int fd[2]; // 创建用于管道通信的文件描述符数组
	if (pipe(fd) == -1) // 创建管道，若失败则输出错误信息
	{
		printf("管道创建失败");
		return 0;
	}
	printf("管道创建成功\n");
	int pid = fork(); // 创建子进程
	if (pid == 0) // 子进程代码
	{
		close(fd[1]); // 子进程关闭写入端
		printf("process ID %d: 关闭写入端!\n", getpid());
		sleep(1); // 睡眠1秒钟，等待父进程写入数据
		char buf[M]; // 用于存储从管道读取的数据的缓冲区
		read(fd[0], buf, M); // 从管道读取数据到缓冲区
		printf("process ID %d: 成功读取:%s\n", getpid(),buf);
		close(fd[0]); // 子进程关闭读取端
		printf("process ID %d: 关闭读取端!\n", getpid());
		exit(1); // 子进程退出
	}
	else // 父进程代码
	{
		close(fd[0]); // 父进程关闭读取端
		printf("process ID %d: 关闭读取端!\n", getpid());
		char buf[M] = "---test aaaaaaaaaabbbbbbb111111---"; // 待写入管道的数据
		write(fd[1], buf, sizeof(buf)); // 将数据写入管道
		printf("process ID %d: 成功写入: %s\n", getpid(),buf);
		close(fd[1]); // 父进程关闭写入端
		printf("process ID %d: 关闭写入端!\n", getpid());
		sleep(2); // 睡眠2秒钟，等待子进程读取数据并退出
	}
	return 0;
}

