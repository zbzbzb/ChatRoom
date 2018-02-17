//
// Created by zhoubin on 2/14/18.
//

#include "Server.h"
#include"Config.h"
#include<string>
using namespace std;
int Server::Bind(sockaddr_in addr) {
    if((m_listenFd=socket(AF_INET,SOCK_STREAM,0))==-1)
    {
        throw runtime_error(strerror(errno));
    }

    sockaddr_in servAddr;
    ssize_t serverAddrLen;
    servAddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servAddr.sin_port=htons(stoi(Config::Instance().get("port")));
    servAddr.sin_family=AF_INET;
    bind(m_listenFd,(sockaddr *)&servAddr,sizeof(servAddr));

}

int Server::Listen() {
    listen(m_listenFd,stoi(Config::Instance().get("backlog")));
}
