//
// Created by zhoubin on 2/16/18.
//

#ifndef SERVER_THREADPOOL_H
#define SERVER_THREADPOOL_H

#include<pthread.h>
#include"Task.h"
#include<iostream>
#include<queue>


class ThreadPool {
private:
    ssize_t m_threadNum;
    pthread_mutex_t m_mutex;
    pthread_cond_t m_cond;
    bool m_shutdown;
    queue<Task> m_task;
    vector<pthread_t> m_threadId;
public:
    void Init(ssize_t num);
    void AddTask(const Handler &handler,const int fd,const vector<int> &v);
    static void * ThreadPoolWorker(void *arg);


    void Close();
};


#endif //SERVER_THREADPOOL_H
