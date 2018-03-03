//
// Created by zhoubin on 3/2/18.
//

#include "Db.h"


using namespace std;
 Db & Db::Instance() {
    if(m_instance==NULL)
    {
        m_instance=new Db();



    }

    return *m_instance;
}

void Db::Init()
{

    m_conn=new MYSQL();

    m_res=new MYSQL_RES();
    m_row=new MYSQL_ROW();
    mysql_init(m_conn);
    if(!mysql_real_connect(m_conn,Config::Instance().get("mysql_host").c_str(),Config::Instance().get("mysql_user").c_str(),
    Config::Instance().get("mysql_password").c_str(),Config::Instance().get("mysql_db").c_str(),0,NULL,CLIENT_FOUND_ROWS))
    {
        throw runtime_error(mysql_error(m_conn));
    }








}

bool Db::Check(const string userName,const string userPw)
{

    char sql[150];

    sprintf(sql,"select * from user where user_name='%s' and user_pw='%s'",userName.c_str(),userPw.c_str());

    int res=mysql_query(m_conn,sql);

    if(res!=0)
    {
        throw runtime_error(mysql_error(m_conn));
    }



    m_res=mysql_store_result(m_conn);

    if(m_res==NULL)
    {
        throw runtime_error(mysql_error(m_conn));
    }

    long long i=mysql_num_rows(m_res);

    if(i==1)
        return true;
    else
        return false;

}

Db::Db()
{
    Init();
}

Db::~Db() {
    delete m_res;
    delete m_conn;
    delete m_row;
    m_conn=NULL;
    m_res=NULL;
    m_row=NULL;
    delete m_instance;
    m_instance=NULL;


}
