#include <iostream>

#include "Functools.h"
#include"Config.h"
#include "ThreadPool.h"
#include<exception>
#include<glog/logging.h>
#include"Task.h"
#include "Handler.h"
#include "Server.h"
#include<pthread.h>


using namespace std;

void task_handler(vector<string> arg)
{
    sleep(3);
    cout<<arg[0]<<endl;
}






Config* Config::instance=NULL;
int main() {

    google::InitGoogleLogging("./logfile");

    Handler h;

    Server s(1000,h);

    s.Run();




    return 0;

}