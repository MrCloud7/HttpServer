#ifndef SERVER_H 
#define  SERVER_H

int initListenFd(unsigned short port);
int epollRun(unsigned short port);
// �Ϳͻ��˽���������
int acceptConn(int lfd, int epfd);
// ���տͻ��˵�http������Ϣ
int recvHttpRequest(int cfd, int epfd);
// ����������
int parseRequestLine(int cfd, const char* reqLine);
// ������ͷ��Ϣ (״̬�� + ��Ϣ��ͷ + ����)
int sendHeadMsg(int cfd, int status, const char* descr, const char* type, int length);
// ���ļ�����, ������
int sendFile(int cfd, const char* fileName);
// ����Ŀ¼���ݸ��ͻ���
int sendDir(int cfd, const char* dirName);
// �Ϳͻ��˶Ͽ�����
int disConnect(int cfd, int epfd);
// ͨ���ļ����õ��ļ���content-type
const char* getFileType(const char* name);
int hexit(char c);
void decodeMsg(char* to, char* from);

#endif