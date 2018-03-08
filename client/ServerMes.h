//
// Created by zhoubin on 3/2/18.
//

#ifndef CLIENT_SERVERMES_H
#define CLIENT_SERVERMES_H

#include<string>
#include<memory>

using namespace std;

#define MES_SERVER_LOGFAIL 0
#define MES_SERVER_LOGSUCCESS 1
#define MES_SERVER_CHATROOMMES 3



class ServerMes {
public:
    int m_command;
    char m_message[120];

public:


};


shared_ptr<ServerMes> BuildServerMes(int command,const string mes);

#endif //CLIENT_SERVERMES_H
