//
// Created by zhoubin on 3/2/18.
//

#ifndef CLIENT_SERVERMES_H
#define CLIENT_SERVERMES_H

#define MES_SERV_LOGFAIL 0
#define MES_SERV_LOGSUCCESS 1
#define MES_SERV_CHATROOMMES 3

class ServerMes {
public:
    int m_command;
    char m_message[120];
};


#endif //CLIENT_SERVERMES_H
