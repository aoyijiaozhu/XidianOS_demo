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
	bool success = CreateProcess("3_child.exe", NULL, NULL, NULL, false, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);//�����ӽ���
	//·���������в��������̰�ȫ���ԣ��̰߳�ȫ���ԣ��Ƿ�̳и����̾����������־����������������Ŀ¼������ 
	if(!success) 
	{
		printf("�����ӽ���ʧ��!"); 
		return 0;
	}
	HANDLE hEvent = CreateEvent(NULL, FALSE, TRUE, "myEvent");
	//��ȫ���ԣ���ʼ״̬������ֹ�����ɷ񱻼̳У��¼��� 
	ResetEvent(hEvent); // ����¼��ź�
	
	printf("Wait for event.\n");
	DWORD flag=WaitForSingleObject(hEvent, INFINITE);//���޵ȴ��¼��ź�
    
	if(WAIT_FAILED == flag)
	{
		printf("�ȴ��¼��ź�ʧ�ܣ�");
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
		printf("��ʱ\n");
		system("pause");
		return 0;
	}
	
	//printf("Get the event.");
	/*��ӡ"Get the event"*/
}
