//
// Created by zhoubin on 3/1/18.
//

#ifndef SERVER_CLIENTMES_H
#define SERVER_CLIENTMES_H

#include<string>
#include <cstring>
#include<memory>

using namespace std;

#define CLIENT_MES_SIZE 124

#define MES_CLIENT_LOGIN 0
#define MES_CLIENT_LOGOUT 1
#define MES_CLIENT_JOINCHAT 2
#define MES_CLIENT_LEAVECHAT 3
#define MES_CLIENT_GETCHATLIST 4
#define MES_CLIETN_CHATMESSAGE 5



class ClientMes {
public:
    int m_command;
    char m_message[120];

    ClientMes()
    {
        memset(m_message,'\0',120);
    }

};

shared_ptr<ClientMes> BuildClientMes(int command,const string mes);

ClientMes RecvClientMes(int fd);


#endif //SERVER_CLIENTMES_H
