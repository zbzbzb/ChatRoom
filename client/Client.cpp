//
// Created by zhoubin on 3/2/18.
//


#include <cstring>
#include "Client.h"
#include"ClientMes.h"
#include"ServerMes.h"
#include"Functools.h"
#include<stdio.h>

#define CLIENT_MES_SIZE 124
#define SERVER_MES_SIZE 124



using namespace std;

void Client::Connect() {
    if(connect(m_connFd,(sockaddr *)&m_servAddr,sizeof(m_servAddr))==-1)
    {
        throw runtime_error(strerror(errno));
    }

}

int Client::Socket() {
    m_connFd=socket(AF_INET,SOCK_STREAM,0);
    if(m_connFd==-1)
    {
        throw runtime_error(strerror(errno));
    }

    return m_connFd;
}
 
void Client::MainMenu()
{
    int choose;
  startup:  cout<<"1:Login"<<endl;
    cout<<"2:Register"<<endl;
    cout<<"3:Quit"<<endl;
    
    cin>>choose;
    
    switch(choose)
    {
        case 1:
        {
            if(Login())
            {
                SecondaryMenu();
            } else
            {
                goto startup;
            }
        }break;
        case 2:
        {
            
        }break;
        case 3:
        {
            
        }
            
    }
}




void Client::Run() {
    MainMenu();
}

bool Client::Login(){

    Socket();
    Connect();

    cout<<"输入用户名:"<<endl;
    string userName;
    string userPw;
    cin>>userName;
    cout<<"输入密码:"<<endl;
    cin>>userPw;

    ClientMes loginMes;
    loginMes.m_command=0;

    string tmp=userName+"="+MD5(userPw).toStr();

    strcpy(loginMes.m_message,tmp.c_str());

    write(m_connFd,&loginMes,sizeof(loginMes));

    ServerMes loginResult;

    int n=read(m_connFd,&loginResult,sizeof(loginResult));

    if(loginResult.m_command==MES_SERVER_LOGSUCCESS)
    {
        cout<<loginResult.m_message<<endl;
        return true;
    }
    else
    {
        cout<<loginResult.m_message<<endl;
        close(m_connFd);
        return false;
    }
}

Client::~Client() {

}

Client::Client() {
    m_servAddr.sin_family=AF_INET;
    m_servAddr.sin_port=htons(8090);
    inet_pton(AF_INET,"127.0.0.1",&m_servAddr.sin_addr);

    m_isLogin=false;
    m_inRoom=false;
    m_roomId=-1;



}

void Client::SecondaryMenu() {

    Sstartup:
    cout<<"1.Get ChatRoomList"<<endl;
    cout<<"2.Quit"<<endl;

    int choose;
    cin>>choose;

    switch(choose)
    {
        case(1):
        {
            vector<string> chatroom_list;
            GetChatRoomList(chatroom_list);
            
            int chatroom_id=ChooseChatRoom(chatroom_list);

            if(JoinChatRoom(chatroom_id))
            {
                StartChat();
                goto Sstartup;
            } else
            {
                cout<<"Join chatroom fail!"<<endl;
                goto Sstartup;
            }


            
            
        }
    }
}

void Client::GetChatRoomList(vector<string> &chatList)
{
    SendClientMes(m_connFd,MES_CLIENT_GETCHATLIST,"");
    ServerMes recvMes=RecvServerMes(m_connFd);
    
    string message(recvMes.m_message);
    string del("=");
    Functools::Split(message,del,chatList);

}

bool Client::JoinChatRoom(int chatRoomId)
{
    string chatroom_id=to_string(chatRoomId);
    SendClientMes(m_connFd,MES_CLIENT_JOINCHAT,chatroom_id);

    ServerMes recvMes;

    recvMes=RecvServerMes(m_connFd);

    if(recvMes.m_command==MES_SERVER_JOINCHATSUCCESS)
    {
        return true;
    } 
    else
    {
        return false;
    }
}

void Client::StartChat()
{
    int epfd;

    epfd=epoll_create(2);

    epoll_event std_in,net_in;

    epoll_event result[2];

    std_in.data.fd=fileno(stdin);
    std_in.events=EPOLLIN;

    net_in.data.fd=m_connFd;
    net_in.events=EPOLLIN;

    epoll_ctl(epfd,EPOLL_CTL_ADD,fileno(stdin),&std_in);
    epoll_ctl(epfd,EPOLL_CTL_ADD,m_connFd,&net_in);

    int nready=0;

    while(true)
    {
        nready=epoll_wait(epfd,result,2,-1);

        for(int i=0;i<nready;i++)
        {
            if(!(result[i].events&EPOLLIN))
                continue;
            if(result[i].data.fd==fileno(stdin))
            {
                if(!HandleStdInput())
                    return;

            }
            else if(result[i].data.fd==m_connFd)
            {
                ServerMes recvMes2=RecvServerMes(m_connFd);;

                if(recvMes2.m_command==MES_SERVER_CHATROOMMES)
                {
                    cout<<"RECEIVE A MESSAGE"<<endl;
                    PutOutMessage(recvMes2.m_message);
                }
            }
        }
    }
}

void Client::PutOutMessage(char *src) {
    string mes(src);
    auto pos=mes.find('=');
    string userName(mes.begin(),mes.begin()+pos);
    string message(mes.begin()+pos+1,mes.end());
    cout<<userName<<":"<<message<<endl;
}

bool Client::HandleStdInput() {

    char std_mes[STD_INPUT_SIZE];
    int nSize=read(fileno(stdin),std_mes,STD_INPUT_SIZE);
    std_mes[nSize-1]='\0';
    if(strcmp(std_mes,"exit")==0)
    {
        cout<<"Exit The Chat"<<endl;
        LeaveChatRoom();
        return false;
        
    } else
    {
        SendClientMes(m_connFd,MES_CLIENT_CHATMESSAGE,std_mes);
        return true;
    }

}

void Client::LeaveChatRoom()
{
    ClientMes sendMes;
    SendClientMes(m_connFd,MES_CLIENT_LEAVECHAT);
}

int Client::ChooseChatRoom(const vector<string> &chatRoomList)
{
    int chatroom_num=chatRoomList.size();

    for(int i=0;i<chatroom_num;i++)
    {
        cout<<i+1<<":"<<chatRoomList[i]<<endl;
    }

    int choose;
    cin>>choose;
    return choose;
}


