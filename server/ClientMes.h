//
// Created by zhoubin on 3/1/18.
//

#ifndef SERVER_CLIENTMES_H
#define SERVER_CLIENTMES_H

#define Login 0
#define Logout 1
#define JoinInChatRoom 2
#define LeaveChatRoom 3
#define AskForRoomList 4
#define ChatRoomMes 5

class ClientMes {
public:
    int m_command;
    char m_mes[120];

};


#endif //SERVER_CLIENTMES_H
