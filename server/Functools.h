//
// Created by zhoubin on 2/15/18.
//

#ifndef SERVER_FUNCTOOLS_H
#define SERVER_FUNCTOOLS_H

#include<string>
#include<vector>
#include<map>

using namespace std;

class Functools {
public:
    static void Split(std::string& s,std::string& delim,std::vector<std::string> & ret);
    static void PrintVector(const vector<string> &v);
};


#endif //SERVER_FUNCTOOLS_H
