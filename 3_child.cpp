#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
 
int main()
{
	HANDLE hEvent=OpenEvent(EVENT_ALL_ACCESS,TRUE,"myEvent");//打开命名事件
	//OpenEvent是一个函数，可以用来执行返回事件对象的句柄
	Sleep(1000);
	printf("是否向父级发出事件信号?[Y\\N]:");
	char ch;
	scanf("%c", &ch);//接收字符 
	if(ch=='Y'||ch=='y')
	{
		SetEvent(hEvent); //将事件置为有信号状态
		printf("已设置为信号状态\n");
	}
	else
	{
		printf("退出\n");
		Sleep(5000); 
		return 0;  //退出 
	}
	//Sleep(5000);  //休眠一段时间
	system("pause");
	return 0;
}
