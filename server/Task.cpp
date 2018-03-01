//
// Created by zhoubin on 2/17/18.
//

#include "Task.h"



void Task::Run() {
    m_handler.handle(m_taskFd,m_taskConnFd);
}

Task::Task(const Handler &handler, const int argFd, const vector<int> &argV) {
    m_handler=handler;
    m_taskFd=argFd;
    m_taskConnFd=argV;
}
