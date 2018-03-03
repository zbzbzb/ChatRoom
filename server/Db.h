//
// Created by zhoubin on 3/2/18.
//

#ifndef SERVER_DB_H
#define SERVER_DB_H
#include<mysql/mysql.h>
#include"Config.h"
#include<iostream>





class Db {
public:

    Db();

    static Db & Instance();

    void Init();

    ~Db();

    bool Check(const string userName,const string userPw);
private:
    MYSQL *m_conn;
    MYSQL_RES *m_res;
    MYSQL_ROW *m_row;
    static Db *m_instance;



};


#endif //SERVER_DB_H
