#include <unistd.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "set_lock.c"
/**生产者:随机生成一个大写字符,并写入myfifo文件*/
int producer(){
    int filesize;
    /**打开文件,并写入一个字符到文件中*/
    int fd;	
    fd = open("myfifo.txt", O_RDWR | O_CREAT | O_APPEND, 0644);
    if(fd < 0){
    	printf("打开文件失败\n");			
    	exit(1);
    }
    int zm;
    srand(time(0));//随机
    zm = rand()%26;//生成0-25的随机数
    zm+='A';//转为大写

    char buff[10] = {zm};
    set_lock(fd, F_WRLCK);//给文件上写入锁    
    if((filesize=write(fd,buff,strlen(buff)))<0){//写一个字符到文件中
        printf("生产者写入字符失败......\n");
        return -1;    
    }else{
        printf("生产者向myfifo文件中写入了  %s\n",buff);        
    }
    set_lock(fd, F_UNLCK); /* 给文件解锁 */
    return 0;
}
int main(int argc , char* argv[]){
       
      int time ;
      int count ;
      if(argc > 1){//第一个参数,生产周期
            sscanf(argv[1],"%d",&time);
       }
      if(argc > 2){
            sscanf(argv[2],"%d",&count);  
      }
        printf("......生产者生产开始,向myfifo.txt生产%d个字符\n",count);
      while(count>0){
        if(producer()<0){
            break;        
        }
        sleep(time);
        count--;
    }
    return 0;  
}