#include <iostream>

#include "Functools.h"
#include"Config.h"
using namespace std;


Config* Config::instance=NULL;
int main() {

    cout<<Config::Instance().get("host")<<endl;
    return 0;

}