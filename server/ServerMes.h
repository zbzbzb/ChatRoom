//
// Created by zhoubin on 3/1/18.
//

#ifndef SERVER_SERVERMES_H
#define SERVER_SERVERMES_H
#include<string>
#include<memory>
#include<unistd.h>

using namespace std;

#define SERVER_MES_SIZE 124


#define MES_SERVER_LOGFAIL 0
#define MES_SERVER_LOGSUCCESS 1
#define MES_SERVER_CHATROOMMES 3
#define MES_SERVER_JOINCHATSUCCESS 4
#define MES_SERVER_JOINCHATFAIL 5

#define MES_SERVER_CHATLIST 6



class ServerMes {
public:
    int m_command;
    char m_message[120];

public:
    ServerMes()
    {
        memset(m_message,'\0',120);
    }


};


shared_ptr<ServerMes> BuildServerMes(int command,const string mes);

bool SendServerMes(int fd,int command,const string & message="");


#endif //SERVER_SERVERMES_H
