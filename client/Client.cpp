//
// Created by zhoubin on 3/2/18.
//


#include <cstring>
#include "Client.h"
#include<memory>
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

int Client::StartUp()
{
    int choose;
    cout<<"1:Login"<<endl;
    cout<<"2:Register"<<endl;
    cin>>choose;
    return choose;
}




void Client::Run() {
    startup:int choose=StartUp();
    if(choose==1)
    {
        bool loginResult=Login();
        if(loginResult)
        {
            m_isLogin=true;
            Pro();
        }
        else
        {
            goto startup;
        }
    }
    else
    {

    }
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

void Client::Pro() {
    //GetChatList();
    cout<<"1.Get ChatRoomList"<<endl;
    cout<<"2.Quit"<<endl;

    int choose;
    cin>>choose;

    switch(choose)
    {
        case(1):
        {
            GetChatList();


        }
    }
}

vector<string> Client::GetChatList()
{
    SendClientMes(m_connFd,MES_CLIENT_GETCHATLIST,"");
    ServerMes recvMes=RecvServerMes(m_connFd);

    vector<string> roomList;
    string message(recvMes.m_message);
    string del("=");
    Functools::Split(message,del,roomList);

    int roomListNum=roomList.size();

    for(int i=0;i<roomListNum;i++)
    {
        cout<<i+1<<":"<<roomList[i]<<endl;
    }

    int choose;
    cin>>choose;

    SendClientMes(m_connFd,MES_CLIENT_JOINCHAT,to_string(choose));
    ServerMes recvMes2;
    recvMes=RecvServerMes(m_connFd);

    cout<<recvMes.m_message<<endl;
    cout<<recvMes.m_command<<endl;

    if(recvMes.m_command==MES_SERVER_JOINCHATSUCCESS)
    {
        StartChat();
    }




}

bool Client::JoinChat()
{
    shared_ptr<ClientMes> sendMes=BuildClientMes(MES_CLIENT_JOINCHAT,"");
    write(m_connFd,sendMes.get(),CLIENT_MES_SIZE);

    ServerMes recvMes;

    read(m_connFd,&recvMes,SERVER_MES_SIZE);

    if(recvMes.m_command==MES_SERVER_JOINCHATSUCCESS)
    {
        return true;
    } else
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

    char readBuff[41];
    int readSize;

    while(true)
    {
        nready=epoll_wait(epfd,result,2,-1);

        for(int i=0;i<nready;i++)
        {
            if(!(result[i].events&EPOLLIN))
                continue;
            if(result[i].data.fd==fileno(stdin))
            {
                readSize=read(0,readBuff,40);
                readBuff[readSize]='\0';
                SendClientMes(m_connFd,MES_CLIENT_CHATMESSAGE,string(readBuff));

            }
            else if(result[i].data.fd==m_connFd)
            {
                ServerMes recvMes;
                recvMes=RecvServerMes(m_connFd);
                if(recvMes.m_command==MES_SERVER_CHATROOMMES)
                {
                    printf("%s",recvMes.m_message);
                }
            }
        }
    }
}


