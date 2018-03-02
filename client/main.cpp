#include <iostream>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<error.h>
#include<sys/epoll.h>
#include<sys/select.h>
#include<arpa/inet.h>

#include "ClientMes.h"
#include "Client.h"
#include"md5.h"

using namespace std;





int main() {



    Client c;
    c.Run();

    return 0;
   /* sockaddr_in servAddr;

    servAddr.sin_family=AF_INET;
    servAddr.sin_port=htons(8090);
    inet_pton(AF_INET,"127.0.0.1",&servAddr.sin_addr);

    int sockfd=socket(AF_INET,SOCK_STREAM,0);

    connect(sockfd,(sockaddr *)&servAddr,sizeof(servAddr));

    ClientMes c_mes;

    for(int i=0;i<20;i++)
        c_mes.m_mes[i]='a';
    c_mes.m_mes[20]='\0';
    c_mes.m_command=5;

    int n=write(sockfd,&c_mes,sizeof(c_mes));
    cout<<"sizeof(mes):"<<sizeof(ClientMes)<<endl;
    cout<<"write "<<n<<" chars"<<endl;*/






    return 0;
}