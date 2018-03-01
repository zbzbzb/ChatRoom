//
// Created by zhoubin on 2/22/18.
//

#ifndef SERVER_EPOLL_H
#define SERVER_EPOLL_H

#include<sys/epoll.h>
#include<sys/select.h>
#include<iostream>
#include<exception>
#include"Exception.h"



class Epoll {
private:
    int m_epfd;
    int m_fdNum;
    int m_curFdNum;

public:
    epoll_event *m_events;
    Epoll(int fdNum);
    ~Epoll();
    void Add(int fd);
    void AddConnFd(int fd);
    void Delete(int fd);
    int Wait();


};


#endif //SERVER_EPOLL_H
