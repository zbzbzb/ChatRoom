//
// Created by zhoubin on 2/14/18.
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include<vector>
#include<string>
#include "Handler.h"
#include<sys/socket.h>
#include<sys/types.h>
#include<sys/fcntl.h>
#include<netinet/in.h>


using namespace std;


class Server {
public:
    int Bind(sockaddr_in addr);
    int Listen();
    void Run();

private:
    int m_listenFd;
    vector<int> m_connFd;
    Handler *m_handler;
    int m_epollFd;

};


#endif //SERVER_SERVER_H
