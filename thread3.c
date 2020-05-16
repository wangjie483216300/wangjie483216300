#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int NUMBER = 0 ;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;//互斥量

void* thread1(void* arg);
void* thread2(void* arg);
void* thread3(void* arg);
int main(){
    
//     pthread_mutex_init (&mutex,PTHREAD_MUTEX_INITIALIZER);//初始化为快速互斥锁

    pthread_t tid1;
    pthread_t tid2;
    pthread_t tid3;
    long number = 1;
    for(number = 1;number < 4;number++){
        switch(number){
        case 1:pthread_create(&tid1,NULL,thread1,(void*)number);
//                pthread_join(tid1,NULL);                
               break;
                
        case 2:pthread_create(&tid2,NULL,thread2,(void*)number);
//                pthread_join(tid2,NULL);  
               break;
        case 3:pthread_create(&tid3,NULL,thread3,(void*)number);
//                pthread_join(tid3,NULL);                 
               break;
        default:printf("error\n"); break;
        }    
    } 
 pthread_join(tid1,NULL); 
 pthread_join(tid2,NULL);
 pthread_join(tid3,NULL); 

    return 0;   
}
void* thread1(void* arg){
    pthread_mutex_lock(&mutex);
    long thrd_num = (long)arg;
    int i;
    for(i=0;i<5;i++){
        printf("线程%ld正在运行......%d\n",thrd_num,i+1);
        sleep(1);
    }
    pthread_mutex_unlock(&mutex); /*释放互斥锁*/
    pthread_exit(NULL);
}
void* thread2(void* arg){
    sleep(1);
    pthread_mutex_lock(&mutex);
    long thrd_num = (long)arg;
    int i;
    for(i=0;i<5;i++){
        printf("线程%ld正在运行......%d\n",thrd_num,i+1);
        sleep(1);
    }
    pthread_mutex_unlock(&mutex); /*释放互斥锁*/
    pthread_exit(NULL);
}
void* thread3(void* arg){
    sleep(2);
    pthread_mutex_lock(&mutex);
    long thrd_num = (long)arg;
    int i;
    for(i=0;i<5;i++){
        printf("线程%ld正在运行......%d\n",thrd_num,i+1);
        sleep(1);
    }
    pthread_mutex_unlock(&mutex); /*释放互斥锁*/
    pthread_exit(NULL);
}