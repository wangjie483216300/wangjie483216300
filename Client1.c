#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>

int main(int argc,char** argv){
    char buff[100]  = "client1";
    //声明客户端套接字
    int clientSocket1;
    clientSocket1=socket(AF_INET,SOCK_STREAM,0);


    struct sockaddr_in serveraddr; 
    memset(&serveraddr,0,sizeof(struct sockaddr_in));    
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(8989);
    inet_pton(AF_INET,"127.0.0.1",&(serveraddr.sin_addr.s_addr));

 
    if(connect(clientSocket1,(struct sockaddr*)&serveraddr,sizeof(serveraddr))==-1){
        perror("连接:");
        return -1;    
    }
      while(1){
            memset(buff,0,100);    
            fgets(buff,200,stdin);
            send(clientSocket1,buff,sizeof(buff),0);
     }
//  send(clientSocket1,buff,sizeof(buff),0);
        
    close(clientSocket1);
    return 0;
    
}



















//     //地址及数据存储顺序处理(声明服务端地址信息结构体)
//     struct sockaddr_in serveraddr;
//     //每一个socket都用一个网络结构描述{协议、本地地址、本地端口}来表示
//     //socket函数用于建立一个套接字，同时指定协议和类型  
//     serverSocket=socket(AF_INET,SOCK_STREAM,0);
//     //初始化一下地址信息结构体
//     memset(&serveraddr,0,sizeof(struct sockaddr_in));    
//     serveraddr.sin_family = AF_INET;//设置地址族
//     serveraddr.sin_port = htons(8989);//设置服务器端口号(htons()2字节主机字节序转换为网络字节序)
//     //设置地址信息中的IP地址,并格式转化
//     inet_pton(AF_INET,"127.0.0.1",&(serveraddr.sin_addr.s_addr));
//     //serverSocket绑定serveraddr
//     if(bind(serverSocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr))==-1){
//         prror("绑定地址:");
//         return -1;
//     }