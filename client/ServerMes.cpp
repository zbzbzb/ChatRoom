//
// Created by zhoubin on 3/2/18.
//

#include "ServerMes.h"

shared_ptr<ServerMes> BuildServerMes(int command,const string mes)
{
    shared_ptr<ServerMes> c_mes(new ServerMes());
    c_mes->m_command=command;
    strcpy(c_mes->m_message,mes.c_str());

    return c_mes;


}