//
// Created by zhoubin on 3/1/18.
//

#ifndef CLIENT_CLIENTMES_H
#define CLIENT_CLIENTMES_H

#define MES_Login 0
#define MES_Logout 1
#define MES_JoinInChatRoom 2
#define MES_LeaveChatRoom 3
#define MES_AskForRoomList 4
#define MES_ChatRoomMes 5


class ClientMes {
public:
    int m_command;
    char m_mes[120];
};


#endif //CLIENT_CLIENTMES_H
