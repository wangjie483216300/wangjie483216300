#include "sem_com.h"//信号量,pv以及各种库

/**老师好,我的想法是: 2个程序
        创建2个共享内存(shmid1,shmid2)
        shmid1: A 用来写数据  B  用来读数据
        shmid2: A 用来读数据  B  用来写数据

        通过 p v 操作 和 sleep() 实现互斥 A先写,B再读,接着B写,A再读  
        循环下去  -->直到一方输入 over 双方程序结束
*/

int main (){    
   
    int sem_id;//信号量标识符
    //获取信号量
    sem_id = getsem();
    //对信号量初始化
    init_sem(sem_id,0);
   /**----------------准备操作-----------------start-----*/
        char buff1[1024];//缓冲区1
        char buff2[1024];//缓冲区2
        int shmid1,shmid2;//共享内存标识符
        char* shm_addr1;//映射共享内存1
        char* shm_addr2;//映射共享内存2
        //创建共享内存--shmid为共享内存标识符
        shmid1 = shmget(ftok(".",'a'),1024,0666);//1写
        //映射共享内存
        shm_addr1 = shmat(shmid1,0,0);
          //创建共享内存--shmid为共享内存标识符
        shmid2 = shmget(ftok(".",'b'),1024,0666);//2读
        //映射共享内存
        shm_addr2 = shmat(shmid2,0,0); 
 /**----------------准备操作-----------------end-----*/  
    while(1){

 /**----------------发送数据---------start-----*/ 
  /**写*/memset(buff1,0,1024);//清空缓冲区
        printf("请您输入:\n");
        fgets(buff1,1023,stdin);
        strncpy(shm_addr1,buff1,1024);//2共享内存复制到shm_addr1
        //判断内容
        if(strncmp(buff1,"over",5)==0){
            //写入完毕,v操作,打开B的读取        
            sem_v(sem_id);
            printf("关闭聊天!\n");
            exit(-1);        
        }else{
             //写入完毕,v操作,打开B的读取        
             sem_v(sem_id);
             sleep(0.1);//睡0.1秒,确保B能使用到资源
             memset(buff1,0,1024);//清空缓冲区             
        }      
 /**----------------发送数据---------end-----*/  
 


 /**----------------接受数据---------start-----*/               
        sem_p(sem_id);//等待b读完释放资源
 /**读*/memset(buff2,0,1024);//清空缓冲区
        strncpy(buff2,shm_addr2,1024);//2共享内存复制到buff
        //判断内容
        if(strncmp(buff2,"over",5)==0){
            printf("对方不想理你了,并关闭了聊天!\n");
            exit(-1);        
        }else{
             printf("小姐姐B对你说:%s\n",buff2); 
             memset(buff2,0,1024);//清空缓冲区            
        }  
 /**----------------接受数据---------end-----*/ 




    memset(shm_addr1,0,1024);
    memset(shm_addr2,0,1024);


     }



    /**----------------结束操作--------------*/ 
        shmdt(shm_addr1);//解除映射
        shmdt(shm_addr2);//解除映射
        shmctl(shmid1,IPC_RMID,NULL);//删除共享内存
        shmctl(shmid2,IPC_RMID,NULL);//删除共享内存
    return 0;
}
























