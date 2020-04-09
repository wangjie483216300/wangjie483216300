#include "sem_com.h"//信号量,pv以及各种库


int main (){    
   
    int sem_id;//信号量标识符
    //获取信号量
    sem_id = getsem();
    //对信号量初始化
    init_sem(sem_id,0);
   /**----------------准备操作-----------------start-----*/
        char buff1[1024];//缓冲区
        char buff2[1024];//缓冲区
        int shmid1,shmid2;//共享内存标识符
        char* shm_addr1;//映射共享内存
        char* shm_addr2;//映射共享内存
        //创建共享内存--shmid为共享内存标识符
        shmid1 = shmget(ftok(".",'a'),1024,0666);//读
        //映射共享内存
        shm_addr1 = shmat(shmid1,0,0);
          //创建共享内存--shmid为共享内存标识符
        shmid2 = shmget(ftok(".",'b'),1024,0666);//写
        //映射共享内存
        shm_addr2 = shmat(shmid2,0,0); 
 /**----------------准备操作-----------------end-----*/ 
   



 while(1){
 /**----------------接受数据---------start-----*/  
        //p操作--等待A写入之后读取
 /**读*/sem_p(sem_id); 
        memset(buff1,0,1024);//清空缓冲区
        strncpy(buff1,shm_addr1,1024);//2共享内存复制到buff
        //判断内容
        if(strncmp(buff1,"over",5)==0){

            printf("对方不想理你了,并关闭了聊天!\n");
            exit(-1);        
        }else{
            
             printf("小哥哥A对你说:%s\n",buff1); 
             memset(buff1,0,1024);//清空缓冲区            
        }
 /**----------------接受数据---------end-----*/ 



/**----------------发送数据---------start-----*/  
 /**写*/memset(buff2,0,1024);//清空缓冲区
        printf("请您输入:\n");
        fgets(buff2,1024,stdin);//控制台输入  
        strncpy(shm_addr2,buff2,1024);//2共享内存复制到shmid2
   
        //判断内容
        if(strncmp(buff2,"over",5)==0){
             sleep(0.1);
             sem_v(sem_id);//打开v操作,让A执行
            printf("关闭聊天!\n");
            exit(-1);        
        }else{
             sleep(0.1);
             sem_v(sem_id);//打开v操作,让A执行
             memset(buff2,0,1024);//清空缓冲区             
        }
/**----------------发送数据---------end-----*/
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
























