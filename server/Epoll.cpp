//
// Created by zhoubin on 2/22/18.
//

#include <glog/logging.h>
#include "Epoll.h"

Epoll::Epoll(int fdNum) {
    m_epfd=epoll_create(fdNum);
    m_fdNum=fdNum;
    if(m_epfd==-1)
    {
        LOG(FATAL)<<strerror(errno);

    }
    m_curFdNum=0;
    m_events=(epoll_event *)malloc(sizeof(epoll_event)*m_fdNum);


}
Epoll::~Epoll() {
    delete m_events;
}

void Epoll::Add(int fd) {
    epoll_event tmp;
    tmp.events=EPOLLIN;
    tmp.data.fd=fd;
    epoll_ctl(m_epfd,EPOLL_CTL_ADD,fd,&tmp);
    m_curFdNum++;

}

void Epoll::Delete(int fd) {
    epoll_ctl(m_epfd,EPOLL_CTL_DEL,fd,NULL);
}

int  Epoll::Wait() {
    return epoll_wait(m_epfd,m_events,m_fdNum,-1);
}

void Epoll::AddConnFd(int fd) {
    epoll_event tmp;
    tmp.events=EPOLLIN|EPOLLET;
    tmp.data.fd=fd;
    epoll_ctl(m_epfd,EPOLL_CTL_ADD,fd,&tmp);
    m_curFdNum++;

}
