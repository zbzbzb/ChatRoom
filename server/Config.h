//
// Created by zhoubin on 2/15/18.
//

#ifndef SERVER_CONFIG_H
#define SERVER_CONFIG_H

#include<map>
#include<string>
#include<vector>

using namespace std;

class Config {
private:
    map<string,string> m_config;
    Config();
public:
    string get(const string &configName);
    void set(const string &configName,const string &configValue);
    static Config *instance;

    static Config & Instance();

    void Init();

    void All();
};


#endif //SERVER_CONFIG_H
