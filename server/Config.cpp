//
// Created by zhoubin on 2/15/18.
//

#include "Config.h"
#include<fstream>
#include <iostream>
#include"Functools.h"

using namespace std;



void Config::set(const string &configName, const string &configValue) {
    m_config[configName]=configValue;
}

void Config::Init()
{
    vector<string> v;
    string del("=");
    fstream fConfig("server.config");
    string keyValue;
    while(getline(fConfig,keyValue))
    {
        //cout<<keyValue<<endl;
        Functools::Split(keyValue,del,v);
        m_config[v[0]]=v[1];
        v.clear();
    }

}

string Config::get(const string &configName) {
    if(m_config.count(configName))
        return m_config[configName];
    else
        return string();
}



Config::Config() {

}

Config &Config::Instance() {
    if(instance==NULL)
    {
        instance=new Config();
        instance->Init();
    }

    return *instance;
}

void Config::All()
{
    for(auto v=m_config.begin();v!=m_config.end();++v)
    {
        cout<<(*v).first<<"="<<(*v).second<<endl;
    }
}



