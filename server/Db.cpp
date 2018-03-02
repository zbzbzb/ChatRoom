//
// Created by zhoubin on 3/2/18.
//

#include "Db.h"


using namespace std;
 Db & Db::Instance() {
    if(m_instance==NULL)
    {
        m_instance=new Db();
        m_instance->Init();


    }

    return *m_instance;
}

void Db::Init()
{

    m_conn=new MYSQL();

    m_res=new MYSQL_RES();
    m_row=new MYSQL_ROW();
    mysql_init(m_conn);
    if(mysql_real_connect(m_conn,Config::Instance().get("mysql_host").c_str(),Config::Instance().get("mysql_user").c_str(),
    Config::Instance().get("mysql_password").c_str(),Config::Instance().get("mysql_db").c_str(),0,NULL,CLIENT_FOUND_ROWS))
    {

    }
    else
    {
        throw runtime_error(mysql_error(m_conn));
    }








}

bool Db::Check(const string userName,const string userPw)
{

    char sql[150];

    sprintf(sql,"select * from user where user_name='%s' and userPw='%s",userName.c_str(),userPw.c_str());

    mysql_query(m_conn,sql);

    m_res=mysql_store_result(m_conn);

    int i=mysql_num_rows(m_res);

    if(i==1)
        return true;
    else
        return false;





}