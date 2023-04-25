#include <stdio.h>
#include "server.h"

// 原则: main函数只是逻辑函调用, 具体的内容不会写在这里边
// 功能函数: 功能要尽可能单一, 一个函数的代码一般最多也就写几十行
int main(int argc, char* argv[])
{
	// a.out port path(服务器提供的资源根目录)
	if (argc < 3)
	{
		printf("./a.out port respath\n");
		exit(0);
	}
	// 资源根目录存储到 argv[2], 假设: /home/robin/luffy
	// 将当前服务器的进程工作目录切换到资源根目录中
	chdir(argv[2]);
	// 启动服务器 -> 基于epoll
	unsigned short port = atoi(argv[1]);
	epollRun(port);

	return 0;
}