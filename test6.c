#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define BUFFER_SIZE 1024

int main() 
{
    int shm_id;
    char *shm_ptr;

    // 创建共享内存
    key_t key = ftok(".", 'R'); // 生成一个唯一的key
    shm_id = shmget(key, BUFFER_SIZE, IPC_CREAT | 0666); // 创建共享内存段(标志参数IPC_CREAT表示如果共享内存不存在则创建它，0666是权限标志)
    if (shm_id < 0) 
	{
        printf("创建共享内存失败\n");
        return 0; 
    }
	printf("已创建共享内存\n");
    // 附加共享内存
    shm_ptr = (char *) shmat(shm_id, NULL, 0); // 返回共享内存段的指针
    if (shm_ptr == (char *) -1)
	{
        printf("附加共享内存失败\n");
        return 0; 
    }
	printf("已附加共享内存\n");
    
    sprintf(shm_ptr, "test_aaaaaabbbbbb1111");// 写者进程写入数据
	printf("向共享内存写入数据：'test_aaaaaabbbbbb1111'\n");
    
    pid_t pid = fork();// 创建子进程
    if (pid < 0) 
	{
        printf("子进程创建失败\n");
        return 0;
    }
    if (pid == 0) 
	{
        
        printf("子进程: 从共享内存读取到数据: %s\n", shm_ptr);// 子进程作为读者进程
        
        if (shmdt(shm_ptr) == -1) // 断开共享内存连接 
		{
            printf("断开共享内存连接失败\n");
            return 0;
        }
        printf("已断开共享内存连接\n");
    } 
	else 
	{
        
        wait(NULL);// 父进程等待子进程终止
        
        if (shmctl(shm_id, IPC_RMID, NULL) == -1)// 删除共享内存
		{
            printf("删除共享内存失败\n");
            return 0;
        }
        printf("已删除共享内存\n");
    }
    return 0;
}
