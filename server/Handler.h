//
// Created by zhoubin on 2/14/18.
//

#ifndef SERVER_HANDLER_H
#define SERVER_HANDLER_H
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<error.h>
#include<unistd.h>
#include<vector>
#include"Db.h"
#include<algorithm>
#include<functional>

using namespace std;

class Handler {
public:
    virtual void handle(const int fd,const vector<int> & v);
};

void SendPublicMessage(int fd,vector<int> v,char *src);
#endif //SERVER_HANDLER_H
