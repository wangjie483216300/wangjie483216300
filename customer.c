#include <unistd.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "set_lock.c"
/**消费(打印出)myfifo文件中前need个字符*/
int customing(int need){
    char buff[1];
    int count = 0 ;
    int fd ;    
    if((fd = open("myfifo.txt",O_RDONLY))<0){
        printf("消费者打开文件失败!");
    } 
    lseek(fd,SEEK_SET,0);
    while(need>count){
        while((read(fd,buff,1)==1)&&(count<need)){            
            printf("消费者消费了文件中的第%d个元素: %s\n ",count+1,buff);
            count++;
        }
    }
    close(fd);
    return 0 ;
}
/**复制字符到temp*/
int myfilecopy(int copycount){//偏移量,要复制的字符个数
    int in_file,out_file;
    int count = 0 ;
    char buff[10];
    char tempbuff[10];
    if((in_file = open("myfifo.txt",O_RDWR))<0){
        printf("消费者->复制文件部分->打开源文件部分:失败!");
        return -1;    
    }
    if((out_file = open("temp.txt",O_CREAT|O_RDWR,0644))<0){
        printf("消费者->复制文件部分->打开目标文件部分:失败!");
        return -1;    
    }
    lseek(in_file,copycount,SEEK_SET);//设置源文件指针偏移
    while((read(in_file,buff,1)==1)&&(count<copycount)){//从源文件读 myfifo.txt
        write(out_file,buff,1);//写到目标文件   
        printf("消费者将 %s      从myfifo.txt写入到temp.txt中\n",buff);
        count++;    
    }
    sleep(1);
    lseek(out_file,0,SEEK_SET);//设置目标文件指针偏移

    lseek(in_file,0,SEEK_SET);
    char mebuff[100];
    memset(mebuff,0,100);
    write(in_file,mebuff,100);
    lseek(in_file,0,SEEK_SET);

    while((read(out_file,tempbuff,1)==1)){//从目标文件读 
        write(in_file,tempbuff,1);//写回源文件
        printf("消费者将 %s      从temp.txt写入到myfifo.txt中\n",tempbuff);    
    }
    printf("文件平移完成!\n");
    close(in_file);
    close(out_file);
    return 0;
}

/**组合实现消费者模式*/
int customer(int need){
    int fd;
    //消费myfifo中的数据  need个
    customing(need);
    if((fd=open("myfifo.txt",O_RDWR))<0){
        printf("customer -> 打开 myfifo.txt 文件失败!");
        return -1;
    }
    set_lock(fd, F_WRLCK);//写入锁
    //temp数据替换myfifo中的数据,假装消费了    
    myfilecopy(need);
    set_lock(fd, F_UNLCK); /* 给文件解锁 */
//     unlink("temp.txt");//删除temp文件
  
    close(fd);
}

int main(int argc , char* argv[]){
    int need;
    if(argc>1){//第一个参数,指定要消费的资源数目
        sscanf(argv[1],"%d",&need);
        
    }
    printf("......消费者消费myfifo.txt中的元素\n");
    if(need>0){
        customer(need);
    }
     
    exit(EXIT_SUCCESS);
}