//
// Created by zhoubin on 2/14/18.
//

#include "Handler.h"
#include "User.h"
#include "ClientMes.h"
#include "ServerMes.h"

using namespace std;

extern map<int,int> user_room;
extern pthread_mutex_t userFdSortByRoom_mutex;
extern vector<vector<int> > userFdSortByRoom;
extern vector<int> delFd;
extern map<int,string> roomName;
extern pthread_mutex_t delFd_mutex;
extern pthread_mutex_t inRoomFd_mutex;
extern vector<int > inRoomFd;
extern vector<User> user;
void Handler::handle(const int fd,const vector<int> &v) {
    int clientMesSize=sizeof(ClientMes);
    int serverMesSize=sizeof(ServerMes);
    ClientMes c_mes;
    int n=read(fd,&c_mes,sizeof(c_mes));
    if(n==0)
    {
        pthread_mutex_lock(&delFd_mutex);
        delFd.push_back(fd);
        pthread_mutex_unlock(&delFd_mutex);
        return;

    }
    else if(n==clientMesSize) {
        switch(c_mes.m_command) {
            case MES_CLIENT_LOGIN: {
                string str(c_mes.m_message);
                auto it = str.find('=');
                string userName(str.begin(), str.begin() + it);
                string pw(str.begin() + it + 1, str.end());

                cout << "User:" << userName << endl;
                cout << "Pw:" << pw << endl;

                if (Db::Instance().Check(userName, pw)) {
                    shared_ptr<ServerMes> sendMes = BuildServerMes(MES_SERVER_LOGSUCCESS, "hello,you log success");
                    write(fd, sendMes.get(), serverMesSize);

                } else {
                    shared_ptr<ServerMes> sendMes = BuildServerMes(MES_SERVER_LOGFAIL, "sorry that you log fail");
                    write(fd, sendMes.get(), serverMesSize);

                }
            }
            break;
            case MES_CLIENT_GETCHATLIST:
            {
                string roomNameList;
                for(auto it=roomName.begin();it!=roomName.end();++it)
                {
                    roomNameList+=(*it).second+"=";

                }
                string roomList(roomNameList.begin(),roomNameList.end()-1);
                SendServerMes(fd,MES_SERVER_CHATLIST,roomList);
            }break;

            case MES_CLIENT_JOINCHAT:
            {

                /*for(int i=0;i<10;i++)
                {
                    cout<<c_mes.m_message[i]<<endl;
                }*/
                int roomId=stoi(string(c_mes.m_message));
                roomId-=1;

                cout<<"ROOMID:"<<roomId<<endl;



                pthread_mutex_lock(&userFdSortByRoom_mutex);
                userFdSortByRoom[roomId].push_back(fd);
                user_room[fd]=roomId;
                pthread_mutex_unlock(&userFdSortByRoom_mutex);

                SendServerMes(fd,MES_SERVER_JOINCHATSUCCESS);
            }break;

            case MES_CLIETN_CHATMESSAGE:
            {

                pthread_mutex_lock(&userFdSortByRoom_mutex);

                vector<int> v(userFdSortByRoom[user_room[fd]]);
                pthread_mutex_unlock(&userFdSortByRoom_mutex);

                SendPublicMessage(fd,v,c_mes.m_message);


            }
            break;

        }

    }
}

void SendPublicMessage(int fd,vector<int> v,char *src)
{
    cout<<"GET A MESSAGE"<<src<<endl;
    ServerMes sendMes;
    sendMes.m_command=MES_SERVER_CHATROOMMES;
    strcpy(sendMes.m_message,src);

    for(auto it=v.begin();it!=v.end();++it)
    {
        write(*it,&sendMes,SERVER_MES_SIZE);
    }
}
