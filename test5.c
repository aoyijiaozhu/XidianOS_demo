#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define M 80

int main() {
    const char *pipeName = "my_pipe";
    int fd;
    char buf[M];
    // 创建命名管道
    if (mkfifo(pipeName, 0666) == -1) {
        printf("管道创建失败\n");
        return 0;
    }
    printf("命名管道创建成功!\n");
    int pid = fork();

	if (pid == 0)	//子进程 
	{        
        fd = open(pipeName, O_WRONLY);
        if (fd == -1) {
            printf("管道打开失败\n");
            return 0;
          }

        printf("子进程开始写入：‘test___aaabbb111’\n");
        write(fd, "test___aaabbb111", M);

        close(fd);
        exit(1);
    	} 
	
	else // 父进程
	{
        
        fd = open(pipeName, O_RDONLY);
        if (fd == -1) {
            printf("管道打开失败\n");
            return 0;
        }
        printf("父进程开始读取\n");
        read(fd, buf, sizeof(buf));
        printf("成功读取: %s\n", buf);
	  close(fd);
	
        // 删除命名管道
        printf("正在删除命名管道......\n");
        if (unlink(pipeName) == -1) {
            printf("管道删除失败\n");
            return 0;
        }
        printf("命名管道删除成功\n");
    }

    return 0;
}
