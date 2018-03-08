#include <iostream>

#include "Functools.h"
#include"Config.h"
#include "ThreadPool.h"
#include<exception>
#include<glog/logging.h>
#include"Task.h"
#include "Handler.h"
#include "Server.h"
#include "Db.h"
#include<pthread.h>
#include"md5.h"


using namespace std;

Db * Db::m_instance=NULL;


Config* Config::instance=NULL;
int main() {

    google::InitGoogleLogging("./logfile");


    Handler h;

    Server s(1000,h);

    s.Run();




    return 0;

}