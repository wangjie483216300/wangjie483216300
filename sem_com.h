#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <string.h>
//获取信号量
extern int getsem();
union semun{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *__buf;
};
//初始化信号量   sem_id/信号量标识符    sem_value/信号量的值
extern int init_sem(int sem_id,int sem_value);
//定义p操作
extern int sem_p(int sem_id);
//定义v操作
extern int sem_v(int sem_id);
//定义删除操作
extern int del_sem(int sem_id);
//获取共享内存标识符
extern int shmget();


