//
// Created by zhoubin on 2/14/18.
//

#include "Handler.h"
#include "ClientMes.h"
#include "ServerMes.h"

using namespace std;

map<int,string> userfd_name;
pthread_mutex_t userfd_name_mutex=PTHREAD_MUTEX_INITIALIZER;

extern map<int,int> userfd_room;
extern vector<vector<int> > userfd_sort_by_room;
extern pthread_mutex_t userfd_sort_by_room_mutex;

extern vector<int> fd_to_delete;
extern pthread_mutex_t fd_to_delete_mutex;

extern map<int,string> room_name;

void Handler::handle(const int fd,const vector<int> &v) {
    int clientMesSize=sizeof(ClientMes);
    int serverMesSize=sizeof(ServerMes);
    ClientMes c_mes;
    int n=read(fd,&c_mes,sizeof(c_mes));
    if(n==0)
    {
        pthread_mutex_lock(&fd_to_delete_mutex);
        fd_to_delete.push_back(fd);
        pthread_mutex_unlock(&fd_to_delete_mutex);
        return;

    }
    else if(n==clientMesSize) {
        switch(c_mes.m_command) {
            case MES_CLIENT_LOGIN: {
                string str(c_mes.m_message);
                auto it = str.find('=');
                string tmp_userName(str.begin(), str.begin() + it);
                string pw(str.begin() + it + 1, str.end());

                cout << "User:" << tmp_userName << endl;
                cout << "Pw:" << pw << endl;

                if (Db::Instance().Check(tmp_userName, pw)) {
                    shared_ptr<ServerMes> sendMes = BuildServerMes(MES_SERVER_LOGSUCCESS, "hello,you log success");
                    pthread_mutex_lock(&userfd_name_mutex);
                    userfd_name[fd]=tmp_userName;
                    pthread_mutex_unlock(&userfd_name_mutex);
                    write(fd, sendMes.get(), serverMesSize);

                } else {
                    SendServerMes(fd,MES_SERVER_LOGFAIL,"SORRY YOU LOG FAIL");
                }
            }
            break;
            case MES_CLIENT_GETCHATLIST:
            {
                string roomNameList;
                for(auto it=room_name.begin();it!=room_name.end();++it)
                {
                    roomNameList+=(*it).second+"=";

                }
                string roomList(roomNameList.begin(),roomNameList.end()-1);
                SendServerMes(fd,MES_SERVER_CHATLIST,roomList);
            }break;

            case MES_CLIENT_JOINCHAT:
            {
                int roomId=stoi(string(c_mes.m_message));
                roomId-=1;

                cout<<"ROOMID:"<<roomId<<endl;

                pthread_mutex_lock(&userfd_sort_by_room_mutex);
                userfd_sort_by_room[roomId].push_back(fd);
                userfd_room[fd]=roomId;
                pthread_mutex_unlock(&userfd_sort_by_room_mutex);

                SendServerMes(fd,MES_SERVER_JOINCHATSUCCESS);
            }break;

            case MES_CLIETN_CHATMESSAGE:
            {

                pthread_mutex_lock(&userfd_sort_by_room_mutex);

                vector<int> v(userfd_sort_by_room[userfd_room[fd]]);
                pthread_mutex_unlock(&userfd_sort_by_room_mutex);

                SendPublicMessage(fd,v,c_mes.m_message);


            }
            break;
            case MES_CLIENT_LEAVECHAT:
            {
                pthread_mutex_lock(&userfd_sort_by_room_mutex);

                int room_id=userfd_room[fd];
                userfd_sort_by_room[room_id].erase(
                        find(userfd_sort_by_room[room_id].begin(),userfd_sort_by_room[room_id].end(),fd));

                userfd_room.erase(fd);

                pthread_mutex_unlock(&userfd_sort_by_room_mutex);


            }

        }

    }
}

void SendPublicMessage(int fd,vector<int> v,char *src)
{
    string tmp_userName=userfd_name[fd];
    cout<<"GET A MESSAGE"<<src<<endl;
    ServerMes sendMes;
    sendMes.m_command=MES_SERVER_CHATROOMMES;
    string tmp=tmp_userName+"="+string(src);
    strcpy(sendMes.m_message,tmp.c_str());

    for(auto it=v.begin();it!=v.end();++it)
    {
        write(*it,&sendMes,SERVER_MES_SIZE);
    }
}
