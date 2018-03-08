//
// Created by zhoubin on 3/1/18.
//

#ifndef SERVER_SERVERMES_H
#define SERVER_SERVERMES_H
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

#endif //SERVER_SERVERMES_H
