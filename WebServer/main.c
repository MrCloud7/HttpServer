#include <stdio.h>
#include "server.h"

// ԭ��: main����ֻ���߼�������, ��������ݲ���д�������
// ���ܺ���: ����Ҫ�����ܵ�һ, һ�������Ĵ���һ�����Ҳ��д��ʮ��
int main(int argc, char* argv[])
{
	// a.out port path(�������ṩ����Դ��Ŀ¼)
	if (argc < 3)
	{
		printf("./a.out port respath\n");
		exit(0);
	}
	// ��Դ��Ŀ¼�洢�� argv[2], ����: /home/robin/luffy
	// ����ǰ�������Ľ��̹���Ŀ¼�л�����Դ��Ŀ¼��
	chdir(argv[2]);
	// ���������� -> ����epoll
	unsigned short port = atoi(argv[1]);
	epollRun(port);

	return 0;
}