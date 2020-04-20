#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread(void* arg){
    long a = 20;

    printf("新线程运行:进程号为:%d 线程号为:%ld \n",getpid(),pthread_self());
    printf("传进来的数字为:%ld\n",(long)arg*2);
    printf("%ld\n",a);
    long* c =(long*)&a;
    long* d =(long*)a;
    int e= 110;
    int f=100;
    int* k = &f;
    int* p=&e;
    a=*p;
    printf("e的值:%d\n",*p);
    printf("f的地址值:%d\n",*k);
    printf("ff的地址值:%d\n",f);
    printf("---------------------------\n");

    printf("a的地址值:%ld\n",*c);
    printf("a的值:%ld\n",d);
    pthread_exit((void*)a);

   //int a=20===>(void*)a ====> void* a=20 ==>相当于 int b||&b=20
   //总结  int a = 20;  (void*)a代表 声明一个指针,里面存放a的地址(值),地址映射整数20
}
int main(int argc , char** argv){
    long retval;
    pthread_t tid;
    pthread_create(&tid,NULL,thread,(void*)10);
    printf("主线程运行:进程号为:%d 线程号为:%ld\n",getpid(),pthread_self());
    pthread_join(tid,(void*)&retval);
    //void* retval >> retval=&retval >>&retval = 20 地址相同代表的数也相同
    long* c =(long*)&retval;
    printf("retval的地址值:%ld\n",c);
    printf("retval的值:%ld\n",retval);

    return 0; 
}




//    long a = 20;                              long retval;

// pthread_exit((void*)&a);   -------->>>       pthread_join(tid,(void*)&retval);
                                                        
//                                             printf("retval为:%ld\n",retval);

//                                     老师,我把a的地址赋值给retval的地址,
//                                     但是下面打印出来的是a的地址,为什么呢?








