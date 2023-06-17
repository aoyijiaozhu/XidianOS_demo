#include <process.h>
#include<stdio.h>
#include<stdlib.h>
#include <windows.h>
#include <iostream>
int main( )
{
	STARTUPINFO si;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(STARTUPINFO);
	PROCESS_INFORMATION pi;
	bool success = CreateProcess("3_child.exe", NULL, NULL, NULL, false, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);//创建子进程
	//路径，命令行参数，进程安全属性，线程安全属性，是否继承父进程句柄，创建标志，环境变量，工作目录，，， 
	if(!success) 
	{
		printf("创建子进程失败!"); 
		return 0;
	}
	HANDLE hEvent = CreateEvent(NULL, FALSE, TRUE, "myEvent");
	//安全属性，初始状态（非终止），可否被继承，事件名 
	ResetEvent(hEvent); // 清除事件信号
	
	printf("Wait for event.\n");
	DWORD flag=WaitForSingleObject(hEvent, INFINITE);//无限等待事件信号
    
	if(WAIT_FAILED == flag)
	{
		printf("等待事件信号失败！");
		system("pause");
		return 0;
	}
	else if(WAIT_OBJECT_0  == flag)
	{
		printf("Get the event.\n");
		system("pause");
		return 0;
	}
	else if(WAIT_TIMEOUT  == flag)
	{
		printf("超时\n");
		system("pause");
		return 0;
	}
	
	//printf("Get the event.");
	/*打印"Get the event"*/
}
