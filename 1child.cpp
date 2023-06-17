#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <windows.h>
#include <iostream>


int main()
{
	printf("子进程开始。。。。\n");
	const char *str1 = "test_aaa111.";
	const char *str2 = "\ntest_bbb222.";
	FILE *fp = fopen("test.txt", "w+");
	if (fp) // 
	{
		printf("文件打开成功\n");
		fwrite(str1, strlen(str1),1,fp);
	
		fwrite(str2, strlen(str2),1,fp); 

		printf("写入成功!\n");

		fclose(fp); 
		
		//output content
		fp = fopen("test.txt", "r"); 
		printf("文件内容如下：\n");
		char ch = fgetc(fp); // get first char
		while (ch != EOF) 
		{
			putchar(ch); 
			ch = fgetc(fp); // get next char
		}
		fclose(fp); 
	}
	else
		printf("创建文件失败\n");
	system("pause");
	return 0;
}
