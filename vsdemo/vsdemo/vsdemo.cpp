// vsdemo.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "uv_task.h"

int main()
{
	printf("select what task to run:\n");
	printf("1.hello world\n");
	printf("2.idle - basic\n");
	printf("3.uvcat\n");
	printf("4.file change\n");
	char c = getchar();
	
	switch (c)
	{
	case '1':
		helloworld();
		break;
	case '2':
		idlebasic();
		break;
	case '3':
		uvcat();
		break;
	case '4':
		filechange();
		break;
	default:
		break;
	}

	printf("\ngetchar to end\n");
	getchar();
	getchar();
    return 0;
}

