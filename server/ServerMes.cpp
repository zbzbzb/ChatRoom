    //
// Created by zhoubin on 3/1/18.
//

#include <cstring>
#include "ServerMes.h"

shared_ptr<ServerMes> BuildServerMes(int command,const string mes)
{
    shared_ptr<ServerMes> c_mes(new ServerMes());
    c_mes->m_command=command;
    strcpy(c_mes->m_message,mes.c_str());

    return c_mes;


}
    bool SendServerMes(int fd,int command,const string & message)
    {
        ServerMes sendMes;
        sendMes.m_command=command;
        strcpy(sendMes.m_message,message.c_str());

        write(fd,&sendMes,SERVER_MES_SIZE);

    }
