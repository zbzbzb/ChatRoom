//
// Created by zhoubin on 3/1/18.
//

#ifndef CLIENT_CLIENTMES_H
#define CLIENT_CLIENTMES_H

#include<string>
#include <cstring>
#include<memory>

using namespace std;

#define CLIENT_MES_LOGIN 0
#define CLIENT_MES_LOGOUT 1
#define CLIENT_MES_JOINCHAT 2
#define CLIENT_MES_LEAVECHAT 3
#define CLIENT_MES_GETCHATLIST 4
#define CLIETN_MES_CHATMESSAGE 5

class ClientMes {
public:
    int m_command;
    char m_message[120];

};

shared_ptr<ClientMes> BuildClientMes(int command,const string mes);

#endif //CLIENT_CLIENTMES_H
