#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
void* thread(void* arg){
     char buff[100];
     int serverSocket = (int)arg;
     int clientaddrlen; 
     struct sockaddr_in clientaddr;
     int clientSocket = accept(serverSocket,(struct sockaddr*)&clientaddr,&clientaddrlen);
     while(1){
            if( clientSocket!=-1){
                              //接受客户端传过来的信息  
                recv(clientSocket,buff,100,0);
                if(buff[0]!=0){
                     printf("%d客户端消息:%s\n",clientSocket,buff);
                }                               
                 memset(buff,0,100);  
            }
        }
    close(clientSocket);
    close(serverSocket); 
    pthread_exit(NULL);   
}


int main(int argc,char** argv){
    char buff[100];
    //声明服务端,客户端套接字
    int serverSocket;
    int clientaddrlen; 
    int clientSocket1,clientSocket2,clientSocket3,clientSocket4,clientSocket5;
    //地址及数据存储顺序处理(声明服务端地址信息结构体)
    struct sockaddr_in serveraddr,clientaddr;
    //每一个socket都用一个网络结构描述{协议、本地地址、本地端口}来表示
    //socket函数用于建立一个套接字，同时指定协议和类型  
    serverSocket=socket(AF_INET,SOCK_STREAM,0);
    //初始化一下地址信息结构体
    memset(&serveraddr,0,sizeof(struct sockaddr_in));    
    serveraddr.sin_family = AF_INET;//设置地址族
    serveraddr.sin_port = htons(8989);//设置服务器端口号(htons()2字节主机字节序转换为网络字节序)
    //设置地址信息中的IP地址,并格式转化
    inet_pton(AF_INET,"127.0.0.1",&(serveraddr.sin_addr.s_addr));
    //serverSocket绑定serveraddr
    if(bind(serverSocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr))==-1){
        perror("绑定地址:");
        return -1;
    }
    //设置listen监听的长度(客户端的个数)
    listen(serverSocket,5);//设置为5个
    pthread_t tid1,tid2,tid3,tid4,tid5;
    pthread_create(&tid1,NULL,thread,(void*)serverSocket);
    pthread_create(&tid2,NULL,thread,(void*)serverSocket);
    pthread_create(&tid3,NULL,thread,(void*)serverSocket);
    pthread_create(&tid4,NULL,thread,(void*)serverSocket);
    pthread_create(&tid5,NULL,thread,(void*)serverSocket);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    pthread_join(tid3,NULL);
    pthread_join(tid4,NULL);
    pthread_join(tid5,NULL);

    return 0 ;
}












































































// void* connect1(void* arg){
//      char buff[100];
//     //声明服务端,客户端套接字
//     int serverSocket;
//     int clientaddrlen; 
//     int clientSocket1,clientSocket2,clientSocket3,clientSocket4,clientSocket5;
//     //地址及数据存储顺序处理(声明服务端地址信息结构体)
//     struct sockaddr_in serveraddr,clientaddr;
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
//         perror("绑定地址:");
//         exit(1);
//     }
//     //设置listen监听的长度(客户端的个数)
//     listen(serverSocket,5);//设置为5个



//     pthread_t tid1;
//     clientSocket1 = accept(serverSocket,(struct sockaddr*)&clientaddr,&clientaddrlen);
//     while(1){
//         if( clientSocket1!=-1){
               
//                             //接受客户端传过来的信息  
//                 recv(clientSocket1,buff,100,0);
//                 if(buff[0]!=0){
//                      printf("%d客户端消息:%s\n",clientSocket1,buff);
//                 }                               
//                  memset(buff,0,100);
   
//         }else{
//             pthread_t tid1;
//             pthread_create(&tid1,NULL,connect2,NULL);
//             pthread_join(tid1,NULL);
//         }
//     }   
//     close(clientSocket1);
//     close(serverSocket); 
//     pthread_exit(NULL);
// }
// void* connect2(void* arg){
//      char buff[100];
//     //声明服务端,客户端套接字
//     int serverSocket;
//     int clientaddrlen; 
//     int clientSocket1,clientSocket2,clientSocket3,clientSocket4,clientSocket5;
//     //地址及数据存储顺序处理(声明服务端地址信息结构体)
//     struct sockaddr_in serveraddr,clientaddr;
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
//         perror("绑定地址:");
//         exit(1);
//     }
//     //设置listen监听的长度(客户端的个数)
//     listen(serverSocket,5);//设置为5个



//     pthread_t tid1;
//     clientSocket1 = accept(serverSocket,(struct sockaddr*)&clientaddr,&clientaddrlen);
//     while(1){
//         if( clientSocket1!=-1){

               
//                   //接受客户端传过来的信息  
//                 recv(clientSocket1,buff,100,0);
//                 if(buff[0]!=0){
//                      printf("%d客户端消息:%s\n",clientSocket1,buff);
//                 }                               
//                  memset(buff,0,100);
  
//         }else{
//             pthread_t tid1;
//             pthread_create(&tid1,NULL,connect3,NULL);
//             pthread_join(tid1,NULL);
//         }
//     }   
//     close(clientSocket1);
//     close(serverSocket); 
//     pthread_exit(NULL);
// }
// void* connect3(void* arg){
//      char buff[100];
//     //声明服务端,客户端套接字
//     int serverSocket;
//     int clientaddrlen; 
//     int clientSocket1,clientSocket2,clientSocket3,clientSocket4,clientSocket5;
//     //地址及数据存储顺序处理(声明服务端地址信息结构体)
//     struct sockaddr_in serveraddr,clientaddr;
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
//     if(bind(serverSocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr)) while(1){==-1){
//         perror("绑定地址:");
//         exit(1);
//     }
//     //设置listen监听的长度(客户端的个数)
//     listen(serverSocket,5);//设置为5个


//     clientSocket1 = accept(serverSocket,(struct sockaddr*)&clientaddr,&clientaddrlen);
//     pthread_t tid1;
    
//     while(1){
//         if( clientSocket1!=-1){
//                             //接受客户端传过来的信息  
//                 recv(clientSocket1,buff,100,0);
//                 if(buff[0]!=0){
//                      printf("%d客户端消息:%s\n",clientSocket1,buff);
//                 }                               
//                  memset(buff,0,100);
  
//         }else{
//             pthread_t tid1;
//             pthread_create(&tid1,NULL,connect4,NULL);
//             pthread_join(tid1,NULL);
//         }
//     }   
//     close(clientSocket1);
//     close(serverSocket); 
//     pthread_exit(NULL);
// }
// void* connect4(void* arg){
//      char buff[100];
//     //声明服务端,客户端套接字
//     int serverSocket;
//     int clientaddrlen; 
//     int clientSocket1,clientSocket2,clientSocket3,clientSocket4,clientSocket5;
//     //地址及数据存储顺序处理(声明服务端地址信息结构体)
//     struct sockaddr_in serveraddr,clientaddr;
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
//         perror("绑定地址:");
//         exit(1);
//     }
//     //设置listen监听的长度(客户端的个数)
//     listen(serverSocket,5);//设置为5个



//     pthread_t tid1;
//     clientSocket1 = accept(serverSocket,(struct sockaddr*)&clientaddr,&clientaddrlen);
//     while(1){
//         if( clientSocket1!=-1){
//                              //接受客户端传过来的信息  
//                 recv(clientSocket1,buff,100,0);
//                 if(buff[0]!=0){
//                      printf("%d客户端消息:%s\n",clientSocket1,buff);
//                 }                               
//                  memset(buff,0,100);
  
//         }
//     }   
//     close(clientSocket1);
//     close(serverSocket); 
//     pthread_exit(NULL);
// }

