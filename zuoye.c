#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
void myalarm(int i){
    if(i == SIGALRM){
        sleep(0.5);
        printf("\n闹钟响了!\n\n");
        sleep(0.5);
        printf("叮铃铃,叮铃铃!!叮铃铃,叮铃铃!!叮铃铃,叮铃铃!!\n\n");
    }
}
int main(){
    printf("程序开始运行(输出1-10的数,间隔1s)!\n");
    //捕捉alarm信号量
    signal(SIGALRM,myalarm);
    //开启alarm信号量,定义为5s
    alarm(5);
    int i=1;
    while(i<11){
            printf("程序正在运行, time = %d\n",i);   
            sleep(1);            
            i = i + 1 ;    
    }
    sleep(0.5);
    printf("时间到了,程序执行完毕!\n");
    exit(0);
}
