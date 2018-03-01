//
// Created by zhoubin on 2/17/18.
//

#ifndef SERVER_TASK_H
#define SERVER_TASK_H
#include<string>
#include<vector>
#include"Handler.h"
using namespace std;

class Task {
private:
    Handler m_handler;
    int m_taskFd;
    vector<int> m_taskConnFd;
public:
    Task(const Handler &handler,const int argFd,const vector<int> &argV);
    void Run();
};


#endif //SERVER_TASK_H
