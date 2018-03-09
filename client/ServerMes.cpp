//
// Created by zhoubin on 3/2/18.
//

#include <cstring>
#include "ServerMes.h"
#include<unistd.h>

shared_ptr<ServerMes> BuildServerMes(int command,const string mes)
{
    shared_ptr<ServerMes> c_mes(new ServerMes());
    c_mes->m_command=command;
    strcpy(c_mes->m_message,mes.c_str());

    return c_mes;


}

ServerMes RecvServerMes(int fd)
{
    ServerMes recvMes;
    int n=read(fd,&recvMes,SERVER_MES_SIZE);

    return recvMes;
}