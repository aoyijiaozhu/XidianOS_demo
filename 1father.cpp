#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>

using namespace std;
int main()
{
	// �����ӽ���
	STARTUPINFO sui; //����������Ϣ
	ZeroMemory(&sui, sizeof(sui));//��ʼ�� 
	sui.cb = sizeof(STARTUPINFO);//ָ���ӽ��̴�С 
	PROCESS_INFORMATION pi;//�ӽ��������Ϣ
	// save info
	if (CreateProcess("1child.exe", NULL, NULL, NULL,FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &sui, &pi)) //�����ӽ���
	//·���������в��������̰�ȫ���ԣ��̰߳�ȫ���ԣ��Ƿ�̳и����̾����������־����������������Ŀ¼������ 
	{
		printf("�Ѵ���һ���ӽ���!\n");
		
		int sum = 0, n = 20;
		for (int i = 0; i < n; i++)
		{
			sum += i;
			Sleep(5);
			printf("%d ",sum);
		}
	}
	else
		printf("��������ʧ��\n");
	
	WaitForSingleObject(pi.hProcess, INFINITE);

	//����ӽ���д���ļ�����
	printf("���ļ�д����������:");
	FILE *fp = fopen("test.txt", "r");
	char ch;
	while ((ch = fgetc(fp)) != EOF)
	{
		printf("%c",ch);
	}
	fclose(fp); 
	return 0;
}
