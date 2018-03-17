//
// Created by zhoubin on 3/1/18.
//

#ifndef CLIENT_CLIENTMES_H
#define CLIENT_CLIENTMES_H

#include<string>
#include <cstring>
#include<memory>

#define CLIENT_MES_SIZE 124

using namespace std;

#define MES_CLIENT_LOGIN 0
#define MES_CLIENT_LOGOUT 1
#define MES_CLIENT_JOINCHAT 2
#define MES_CLIENT_LEAVECHAT 3
#define MES_CLIENT_GETCHATLIST 4
#define MES_CLIENT_CHATMESSAGE 5

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

bool SendClientMes(int fd,int command,const string & mes="");

#endif //CLIENT_CLIENTMES_H
