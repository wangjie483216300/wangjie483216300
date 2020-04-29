#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h> 

void* clientthread(void* arg);

int main(int argc,char** argv){
char* clientname =(char*)argv[1];
    if(sizeof(clientname)==0){
        clientname = "无名氏";
    }
    char* connetc1 ="上线了";
    char* Message ="说: ";
    char* close1 = "童鞋离开了群聊!";
    char* clientnameconnetc1 =(char *) malloc(strlen(clientname) + strlen(connetc1));
    char* clientnameMessage =(char *) malloc(strlen(clientname) + strlen(Message));
    char* clientnameClose =(char *) malloc(strlen(clientname) + strlen(close1));
    strcpy(clientnameconnetc1, clientname);
    strcat(clientnameconnetc1, connetc1);
    strcpy(clientnameMessage, clientname);
    strcat(clientnameMessage, Message);
    strcpy(clientnameClose, clientname);
    strcat(clientnameClose, close1);
   
    char buff[100];
    //声明客户端套接字
    int clientSocket1;
    clientSocket1=socket(AF_INET,SOCK_STREAM,0);


    struct sockaddr_in serveraddr; 
    memset(&serveraddr,0,sizeof(struct sockaddr_in));    
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(9999);
//     inet_pton(AF_INET,"127.0.0.1",&(serveraddr.sin_addr.s_addr));
    inet_pton(AF_INET,"118.31.22.96",&(serveraddr.sin_addr.s_addr));


    if(connect(clientSocket1,(struct sockaddr*)&serveraddr,sizeof(serveraddr))==-1){
        perror("连接:");
        return -1;    
    }else{
        send(clientSocket1,clientnameconnetc1,sizeof(buff),0);
    }
    pthread_t tid1;
    pthread_create(&tid1,NULL,clientthread,(void*)clientSocket1);
    while(1){
            memset(buff,0,100);    
            fgets(buff,200,stdin);
            if (buff[strlen(buff)-1] == '\n'){
                buff[strlen(buff)-1] = '\0'; 
             }
            if(strncmp(buff,"over",4)==0){
               send(clientSocket1,clientnameClose,100,0);  
			    break;                         
            }
            send(clientSocket1,clientnameMessage,sizeof(buff),0);
            send(clientSocket1,buff,sizeof(buff),0);
     }
    close(clientSocket1);
    return 0;
    
}
void* clientthread(void* arg){
    char buff[100];
     int clientSocket1 = (int)arg;
     while(1){
        memset(buff,0,100);
        recv(clientSocket1,buff,100,0);
        if(buff[0]!=0){
             printf("%s\n",buff);
        }
       
    }
}
