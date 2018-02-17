#include <iostream>

#include "Functools.h"
#include"Config.h"
#include<exception>
using namespace std;


Config* Config::instance=NULL;
int main() {

    cout<<1888<<endl;
    try{
        throw exception("hfald");
    }catch (exception &r)
    {
        cout<<1111111<<endl;
        throw;
    }
    return 0;

}