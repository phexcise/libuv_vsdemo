// vsdemo.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "uv_task.h"

uv_loop_t *loop;
int main()
{
	printf("select what task to run:\n");
	printf("1.hello world\n");
	printf("2.idle - basic\n");
	printf("3.uvcat\n");
	printf("4.file change\n");
	printf("5.thread create\n");
	printf("6.read write locks\n");
	printf("7.queue work\n");
	printf("8.queue cancel\n");
	printf("9.progress\n");
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
	case '5':
		threadcreate();
		break;
	case '6':
		rwlocks();
		break;
	case '7':
		queuework();
		break;
	case '8':
		queuecancel();
		break;
	case '9':
		progress();
		break;
	default:
		break;
	}

	printf("\ngetchar to end\n");
	getchar();
	getchar();
    return 0;
}

