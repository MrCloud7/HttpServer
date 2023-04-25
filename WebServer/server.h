#ifndef SERVER_H 
#define  SERVER_H

int initListenFd(unsigned short port);
int epollRun(unsigned short port);
// 和客户端建立新连接
int acceptConn(int lfd, int epfd);
// 解收客户端的http请求消息
int recvHttpRequest(int cfd, int epfd);
// 解析请求行
int parseRequestLine(int cfd, const char* reqLine);
// 发送送头信息 (状态行 + 消息报头 + 空行)
int sendHeadMsg(int cfd, int status, const char* descr, const char* type, int length);
// 读文件内容, 并发送
int sendFile(int cfd, const char* fileName);
// 发送目录内容给客户端
int sendDir(int cfd, const char* dirName);
// 和客户端断开连接
int disConnect(int cfd, int epfd);
// 通过文件名得到文件的content-type
const char* getFileType(const char* name);
int hexit(char c);
void decodeMsg(char* to, char* from);

#endif