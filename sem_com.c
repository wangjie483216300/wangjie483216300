#include "sem_com.h"
//获取信号量
int getsem(){
    int sem_id;
    sem_id=semget(ftok(".",'a'),1,0666|IPC_CREAT);
    return sem_id;
}
//初始化
int init_sem(int sem_id,int init_value){
    union semun sem_union;
    int ret;    
    sem_union.val=init_value;
    //semctl对信号量初始化的函数
    ret = semctl(sem_id,0,SETVAL,sem_union);
    if(ret<0){
        perror("初始化");
        return -1;
    }
    return 0;
}
//p操作
int sem_p(int sem_id){
    struct sembuf sem_buff;
    sem_buff.sem_num = 0; //信号量编号,使用单个信号量时,通常设为0
    sem_buff.sem_op =-1 ; //p操作
    sem_buff.sem_flg = SEM_UNDO;
    //semop对信号量进行操作的函数
    if(semop(sem_id,&sem_buff,1)<0){
        perror("p操作");
        return -1;
    }
    return 0;
}
//v操作
int sem_v(int sem_id){
    struct sembuf sem_buff;
    sem_buff.sem_num = 0; //信号量编号,使用单个信号量时,通常设为0
    sem_buff.sem_op = 1; //v操作
    sem_buff.sem_flg = SEM_UNDO;
    //semop对信号量进行操作的函数
    if(semop(sem_id,&sem_buff,1)<0){
        perror("v操作");
        return -1;
    }
    return 0;
}
//删除操作
int del_sem(int sem_id){
    if(semctl(sem_id,0,IPC_RMID)<0){
        perror("删除信号量");
        return -1;
    }
    return 0;
}


