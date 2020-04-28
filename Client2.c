#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>

int main(int argc,char** argv){
    char buff[100] = "2222222222222";
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
        

    close(clientSocket1);
    return 0;
    
}
