#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <windows.h>
#include <iostream>


int main()
{
	printf("�ӽ��̿�ʼ��������\n");
	const char *str1 = "test_aaa111.";
	const char *str2 = "\ntest_bbb222.";
	FILE *fp = fopen("test.txt", "w+");
	if (fp) // 
	{
		printf("�ļ��򿪳ɹ�\n");
		fwrite(str1, strlen(str1),1,fp);
	
		fwrite(str2, strlen(str2),1,fp); 

		printf("д��ɹ�!\n");

		fclose(fp); 
		
		//output content
		fp = fopen("test.txt", "r"); 
		printf("�ļ��������£�\n");
		char ch = fgetc(fp); // get first char
		while (ch != EOF) 
		{
			putchar(ch); 
			ch = fgetc(fp); // get next char
		}
		fclose(fp); 
	}
	else
		printf("�����ļ�ʧ��\n");
	system("pause");
	return 0;
}
