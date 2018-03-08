//
// Created by zhoubin on 2/14/18.
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H
#include<memory>
#include<string>
#include<vector>
#include<string>
#include "Handler.h"
#include<sys/socket.h>
#include<sys/types.h>
#include<sys/fcntl.h>
#include<netinet/in.h>
#include<iostream>
#include<error.h>
#include"ThreadPool.h"
#include<string.h>
#include<sys/epoll.h>
#include<sys/select.h>
#include<cstring>
#include"Epoll.h"
#include "User.h"
#include<cstdio>



using namespace std;


#define EPOLL_MAX 100

using namespace std;



class Server {
public:
    Server(int fdNum,const Handler handler);

    int Bind();
    int Listen();
    void Run();

private:
    int m_listenFd;
    vector<int> m_connFd;
    Handler m_handler;
    Epoll m_ep;
    int m_fdNum;


    void ClearDelFd();

    void CurConnFd();
};


#endif //SERVER_SERVER_H
