#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
int a= 100;
int main(void)
{
        pid_t result;
        result = fork();
        if(result == -1){
                perror("fork");
                return -1;
        }
	    if(result == 0){
		    a=a+1;
                printf("return value=%d,a=%d \n",result,a);
                printf(" 这是子进程, my PID =%d .\n" ,getpid() );
        }
        else
        {
		sleep(2);
              
		printf("return value=%d ,a=%d\n",result,a);
                printf("这是父进程, my PID = %d .\n",getpid());
        }
	    return 0;
}
