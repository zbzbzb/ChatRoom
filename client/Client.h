//
// Created by zhoubin on 3/2/18.
//

#ifndef CLIENT_CLIENT_H
#define CLIENT_CLIENT_H

#include<string>
#include<vector>
#include<iostream>

#include<sys/socket.h>
#include<sys/select.h>
#include<sys/epoll.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/fcntl.h>
#include <netinet/in.h>
#include<arpa/inet.h>
#include<exception>
#include"ClientMes.h"
#include"ServerMes.h"
#include"md5.h"

using namespace std;
class Client {
private:
    int m_connFd;
    bool m_inRoom;
    int m_roomId;
    bool m_isLogin;
    string m_name;
    sockaddr_in m_servAddr;
public:
    int Socket();
    void Connect();
    void Run();
    void Pro();
    bool Login();

    Client();
    ~Client();

    int StartUp();
};


#endif //CLIENT_CLIENT_H
