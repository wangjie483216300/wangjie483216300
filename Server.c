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

int clients[50];

void* clientconnect(void* arg);


int main(int argc,char** argv){
    char buff[100];
    //声明服务端,客户端套接字
    int serverSocket;
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
    listen(serverSocket,50);//设置为5个
      pthread_t tid1,tid2,tid3,tid4,tid5,tid6,tid7,tid8,tid9,tid10,tid11,tid12,tid13,tid14,tid15,tid16,tid17,tid18,tid19,tid20,tid21,tid22,tid23,tid24,tid25,tid26,tid27,tid28,tid29,tid30,tid31,tid32,tid33,tid34,tid35,tid36,tid37,tid38,tid39,tid40,tid41,tid42,tid43,tid44,tid45,tid46,tid47,tid48,tid49,tid50;

    pthread_create(&tid1,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid2,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid3,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid4,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid5,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid6,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid7,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid8,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid9,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid10,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid11,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid12,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid13,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid14,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid15,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid16,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid17,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid18,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid19,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid20,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid21,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid22,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid23,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid24,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid25,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid26,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid27,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid28,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid29,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid30,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid31,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid32,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid33,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid34,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid35,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid36,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid37,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid38,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid39,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid40,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid41,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid42,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid43,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid44,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid45,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid46,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid47,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid48,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid49,NULL,clientconnect,(void*)serverSocket);
    pthread_create(&tid50,NULL,clientconnect,(void*)serverSocket);
    
    

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    pthread_join(tid3,NULL);
    pthread_join(tid4,NULL);
    pthread_join(tid5,NULL);
    pthread_join(tid6,NULL);
    pthread_join(tid7,NULL);
    pthread_join(tid8,NULL);
    pthread_join(tid9,NULL);
    pthread_join(tid10,NULL);
    pthread_join(tid11,NULL);
    pthread_join(tid12,NULL);
    pthread_join(tid13,NULL);
    pthread_join(tid14,NULL);
    pthread_join(tid15,NULL);
    pthread_join(tid16,NULL);
    pthread_join(tid17,NULL);
    pthread_join(tid18,NULL);
    pthread_join(tid19,NULL);
    pthread_join(tid20,NULL);
    pthread_join(tid21,NULL);
    pthread_join(tid22,NULL);
    pthread_join(tid23,NULL);
    pthread_join(tid24,NULL);
    pthread_join(tid25,NULL);
    pthread_join(tid26,NULL);
    pthread_join(tid27,NULL);
    pthread_join(tid28,NULL);
    pthread_join(tid29,NULL);
    pthread_join(tid30,NULL);
    pthread_join(tid31,NULL);
    pthread_join(tid32,NULL);
    pthread_join(tid33,NULL);
    pthread_join(tid34,NULL);
    pthread_join(tid35,NULL);
    pthread_join(tid36,NULL);
    pthread_join(tid37,NULL);
    pthread_join(tid38,NULL);
    pthread_join(tid39,NULL);
    pthread_join(tid40,NULL);
    pthread_join(tid41,NULL);
    pthread_join(tid42,NULL);
    pthread_join(tid43,NULL);
    pthread_join(tid44,NULL);
    pthread_join(tid45,NULL);
    pthread_join(tid46,NULL);
    pthread_join(tid47,NULL);
    pthread_join(tid48,NULL);
    pthread_join(tid49,NULL);
    pthread_join(tid50,NULL);

    return 0 ;
}









void* clientconnect(void* arg){
     char buff[100];
     int serverSocket = (int)arg;
     int clientaddrlen; 
     struct sockaddr_in clientaddr;
     int clientSocket = accept(serverSocket,(struct sockaddr*)&clientaddr,&clientaddrlen);
     for(int i = 0 ; i<50 ; i++ ){
        if(clients[i] == 0){
            clients[i] = clientSocket;
            break;
         }
     }
     while(1){
            if( clientSocket!=-1){
                //接受客户端传过来的信息  
                recv(clientSocket,buff,100,0);
                if(buff[0]!=0){
                     printf("%s\n",buff);
                     for(int i= 0  ; i < 50 ; i++ ){
                          if(clients[i]!=0&&clients[i]!=clientSocket){
                             send(clients[i],buff,100,0);                           
                          }
                     }
                }                               
                memset(buff,0,100);  
            }else{
                perror("连接");
                exit(-1);                
            }
        }
    close(clientSocket);
    close(serverSocket); 
    pthread_exit(NULL);   
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

