//
// Created by zhoubin on 3/1/18.
//

#ifndef SERVER_SERVERMES_H
#define SERVER_SERVERMES_H


#define MES_SERV_LogFail 0
#define MES_SERV_LogSuccess 1
#define MES_SERV_ChatRoomMes 3

class ServerMes {
public:
    int m_command;
    char m_message[120];

};


#endif //SERVER_SERVERMES_H
