#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
 
int main()
{
	HANDLE hEvent=OpenEvent(EVENT_ALL_ACCESS,TRUE,"myEvent");//�������¼�
	//OpenEvent��һ����������������ִ�з����¼�����ľ��
	Sleep(1000);
	printf("�Ƿ��򸸼������¼��ź�?[Y\\N]:");
	char ch;
	scanf("%c", &ch);//�����ַ� 
	if(ch=='Y'||ch=='y')
	{
		SetEvent(hEvent); //���¼���Ϊ���ź�״̬
		printf("������Ϊ�ź�״̬\n");
	}
	else
	{
		printf("�˳�\n");
		Sleep(5000); 
		return 0;  //�˳� 
	}
	//Sleep(5000);  //����һ��ʱ��
	system("pause");
	return 0;
}
