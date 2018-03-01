//
// Created by zhoubin on 2/16/18.
//

#include "ThreadPool.h"
#include<glog/logging.h>
void ThreadPool::Init(ssize_t num) {
    if(pthread_mutex_init(&m_mutex,NULL)!=0)
    {
        LOG(FATAL)<<"mutex init fail";
        throw runtime_error("mutex init fail");
    }

    if(pthread_cond_init(&m_cond,NULL)!=0)
    {
        LOG(FATAL)<<"cond init fail";
        throw runtime_error("cond init fail");
    }
    pthread_t pid;
    for(int i=0;i<num;i++)
    {
        pthread_create(&pid,NULL,ThreadPoolWorker,this);
        m_threadId.push_back(pid);
    }

    m_shutdown=false;
    m_threadNum=num;


}

void* ThreadPool::ThreadPoolWorker(void *arg) {

    ThreadPool *pool= static_cast<ThreadPool *>(arg);
    while(!(pool->m_shutdown))
    {
        cout<<"thread "<<pthread_self()<<"is wait for task"<<endl;
        pthread_mutex_lock(&(pool->m_mutex));

        while(pool->m_task.size()==0&&!(pool->m_shutdown))
        {
            pthread_cond_wait(&pool->m_cond,&(pool->m_mutex));
        }

        if(pool->m_task.size()==0)
        {
            pthread_mutex_unlock(&(pool->m_mutex));
            if(pool->m_shutdown)
                return NULL;
            continue;
        }

        Task curTask=pool->m_task.front();
        pool->m_task.pop();
        pthread_mutex_unlock(&pool->m_mutex);
        cout<<"thread "<<pthread_self()<<" get a work"<<endl;
        curTask.Run();

    }




}


void ThreadPool::Close()
{
    if(m_shutdown)
        return;

    pthread_cond_broadcast(&m_cond);
    for(int i=0;i<m_threadNum;i++)
    {
        pthread_join(m_threadId[i],NULL);
        cout<<"回收了一个线程"<<endl;
    }

    pthread_mutex_destroy(&m_mutex);
    pthread_cond_destroy(&m_cond);
    m_shutdown=true;
}

void ThreadPool::AddTask(const Handler &handler, const int fd, const vector<int> &v) {
    pthread_mutex_lock(&m_mutex);
    Task task(handler,fd,v);
    ThreadPool::m_task.push(task);
    pthread_mutex_unlock(&m_mutex);
    pthread_cond_signal(&m_cond);

}
