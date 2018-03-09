    //
// Created by zhoubin on 3/1/18.
//

#include "ClientMes.h"

#include<unistd.h>

    shared_ptr<ClientMes> BuildClientMes(int command,const string mes) {
        shared_ptr<ClientMes> c_mes(new ClientMes);
        c_mes->m_command = command;
        strcpy(c_mes->m_message, mes.c_str());

        return c_mes;

    }

    bool SendClientMes(int fd,int command,const string & mes) {
        ClientMes sendMes;
        sendMes.m_command = command;
        strcpy(sendMes.m_message, mes.c_str());

        int n = write(fd, &sendMes, CLIENT_MES_SIZE);

        return true;

    }