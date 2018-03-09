//
// Created by zhoubin on 2/14/18.
//

#include "Server.h"
#include"Config.h"
#include <glog/logging.h>
#include<algorithm>
#include<functional>


using namespace std;

pthread_mutex_t inRoomFd_mutex=PTHREAD_MUTEX_INITIALIZER;

pthread_mutex_t delFd_mutex=PTHREAD_MUTEX_INITIALIZER;


vector<int> delFd;

map<int,int> user_room;

vector<int> inRoomFd;
vector<User> user;
map<int,string> roomName;
pthread_mutex_t userFdSortByRoom_mutex=PTHREAD_MUTEX_INITIALIZER;
vector<vector<int> > userFdSortByRoom;


Server::Server(int fdNum,const Handler handler):m_ep(EPOLL_MAX)
{
    m_fdNum=fdNum;
    m_handler=handler;
}

void Server::ClearDelFd()
{

    pthread_mutex_lock(&delFd_mutex);
    for(auto it=delFd.begin();it!=delFd.end();++it)
    {
        cout<<"Fd "<<*it<<"delete "<<endl;
        m_connFd.erase(find(m_connFd.begin(),m_connFd.end(),*it));
        m_ep.Delete(*it);
        close(*it);
    }
    delFd.clear();
    pthread_mutex_unlock(&delFd_mutex);
}

int Server::Bind() {
    if((m_listenFd=socket(AF_INET,SOCK_STREAM,0))==-1)
    {
        throw runtime_error(strerror(errno));
    }

    int opt=1;

    setsockopt(m_listenFd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));

    setsockopt(m_listenFd,SOL_SOCKET,SO_REUSEPORT,&opt,sizeof(opt));

    sockaddr_in servAddr;

    servAddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servAddr.sin_port=htons(8090);
    servAddr.sin_family=AF_INET;

    if(bind(m_listenFd,(sockaddr *)&servAddr,sizeof(servAddr))==-1)
        throw runtime_error(strerror(errno));

}

int Server::Listen() {
    if((listen(m_listenFd,10))==-1)
        throw runtime_error(strerror(errno));
}

void Server::CurConnFd()
{
    for(auto it=m_connFd.begin();it!=m_connFd.end();++it)
        cout<<*it<<ends;
    cout<<endl;
}


void Server::Run() {
    Bind();
    Listen();

    int roomNum=stoi(Config::Instance().get("roomNum"));
    vector<int> tmp;
    for(int i=0;i<roomNum;i++)
    {
        string room=string("room")+to_string(i+1);
        roomName[i]=Config::Instance().get(room);
        userFdSortByRoom.push_back(tmp);
    }

    /*for(auto it=roomName.begin();it!=roomName.end();++it)
    {
        cout<<(*it).first<<ends<<(*it).second<<endl;
    }
    exit(0);*/
    ThreadPool tp;
    tp.Init(5);
    int nready;
    int connfd;
    sockaddr_in cliaddr;
    socklen_t cliaddr_len=sizeof(cliaddr);


    m_ep.Add(m_listenFd);

    while(1)
    {
        ClearDelFd();
        nready=m_ep.Wait();
        if(nready==-1)
        {
            throw runtime_error(strerror(errno));
        }

        for(int i=0;i<nready;i++)
        {
            if(!(m_ep.m_events[i].events&EPOLLIN))
            {
                continue;
            }
            if(m_ep.m_events[i].data.fd==m_listenFd)
            {
                connfd=accept(m_listenFd,(struct sockaddr *)&cliaddr,&cliaddr_len);
                if(connfd==-1)
                    cout<<strerror(errno)<<endl;
                cout<<"get a connect,the fd is"<<connfd<<endl;


                if(m_connFd.size()>=m_fdNum)
                {
                    LOG(WARNING)<<"TOO MANY FD";
                    cout<<"add fail"<<endl;
                }
                else
                {
                    m_connFd.push_back(connfd);
                    m_ep.AddConnFd(connfd);
                    cout<<"add success"<<endl;
                }
                CurConnFd();

            }
            else
            {
                tp.AddTask(m_handler,m_ep.m_events[i].data.fd,m_connFd);
            }


        }


    }





}
