#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>

using namespace std;
int main()
{
	// 创建子进程
	STARTUPINFO sui; //进程启动信息
	ZeroMemory(&sui, sizeof(sui));//初始化 
	sui.cb = sizeof(STARTUPINFO);//指定子进程大小 
	PROCESS_INFORMATION pi;//子进程相关信息
	// save info
	if (CreateProcess("1child.exe", NULL, NULL, NULL,FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &sui, &pi)) //创建子进程
	//路径，命令行参数，进程安全属性，线程安全属性，是否继承父进程句柄，创建标志，环境变量，工作目录，，， 
	{
		printf("已创建一个子进程!\n");
		
		int sum = 0, n = 20;
		for (int i = 0; i < n; i++)
		{
			sum += i;
			Sleep(5);
			printf("%d ",sum);
		}
	}
	else
		printf("创建进程失败\n");
	
	WaitForSingleObject(pi.hProcess, INFINITE);

	//输出子进程写入文件内容
	printf("子文件写入内容如下:");
	FILE *fp = fopen("test.txt", "r");
	char ch;
	while ((ch = fgetc(fp)) != EOF)
	{
		printf("%c",ch);
	}
	fclose(fp); 
	return 0;
}
