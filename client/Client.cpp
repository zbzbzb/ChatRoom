//
// Created by zhoubin on 3/2/18.
//


#include <cstring>
#include "Client.h"
#include<memory>
#include"ClientMes.h"

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

    //cout<<loginMes.m_mes<<endl;





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
    cout<<"1.Join ChatRoom"<<endl;
    cout<<"2.Quit"<<endl;
}

vector<string> Client::GetChatList()
{
    shared_ptr<ClientMes> sendMes=BuildClientMes(CLIENT_MES_GETCHATLIST,"");
    write(m_connFd,sendMes.get(),CLIENT_MES_SIZE);

    ServerMes recvMes;

    read(m_connFd,&recvMes,SERVER_MES_SIZE);




}

void Client::JoinChat()
{
    shared_ptr<ClientMes> sendMes=BuildClientMes(CLIENT_MES_JOINCHAT,"");
    write(m_connFd,sendMes.get(),CLIENT_MES_SIZE);

}


