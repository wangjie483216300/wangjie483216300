#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX(a,b) ((a>b)?(a):(b))
 
int main(){
    int fd[3];
    int maxfd;
    char buff[1024];
    struct timeval tv;
    fd_set inset,tmp_inset;
    
    int i,res,real_read;

    fd[0]=0;

    if(access("in1", F_OK) == -1)
	{
		mkfifo("in1", 0666);
	}
    if(access("in2", F_OK) == -1)
	{
		mkfifo("in2", 0666);
	}
    fd[0] = open("in1", O_RDONLY|O_NONBLOCK);
    if(fd[0] == -1)	{
		perror("打开管道文件fd1失败!\n");
		exit(-1);
	}
    fd[1] = open("in2", O_RDONLY|O_NONBLOCK);
    if(fd[1] == -1)	{
		perror("打开管道文件fd2失败!\n");
		exit(-1);
	}

    maxfd = MAX(MAX(fd[0],fd[1]),fd[2]);
    FD_ZERO(&inset);
    for(i=0;i<3;i++){
        FD_SET(fd[i],&inset);
    }
    tv.tv_sec=300;
    tv.tv_usec=0;

    while(1){
        tmp_inset = inset;
        res = select(maxfd+1,&tmp_inset,NULL,NULL,&tv);
        switch(res){
            case -1:
                printf("Select error\n");
                return 1;
            case 0:
                printf("Time out\n");
                return 1;
            default:
                for(i=0;i<3;i++){
                    if(FD_ISSET(fd[i],&tmp_inset)){
                        memset(buff,0,1024);
                        real_read=read(fd[i],buff,1024);
                        if(real_read>0){
                            if((buff[0]=='q')||(buff[0]=='Q'))
                                {   return -1;  }
                             else{
                                    buff[real_read]='\0';
                                    printf("%s",buff);                                                           
                                }  
                        }                       
                                            
                    }

             }        
        }
        
    }
   
}