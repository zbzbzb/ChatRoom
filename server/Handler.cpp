//
// Created by zhoubin on 2/14/18.
//

#include "Handler.h"
#include "User.h"

extern vector<int> delFd;
extern pthread_mutex_t delFd_mutex;
extern pthread_mutex_t inRoomFd_mutex;
extern vector<vector<int> > inRoomFd;
extern vector<User> user;
void Handler::handle(const int fd,const vector<int> &v) {







    /*//cout<<"the fd:"<<fd<<endl;
    char buff[20];
    int n=read(fd,buff,20);
    if(n==0)
    {
        pthread_mutex_lock(&delFd_mutex);
        delFd.push_back(fd);
        pthread_mutex_unlock(&delFd_mutex);
        return;
    }

    for(int i=0;i<v.size();i++)
        write(v[i],buff,n);*/





}
