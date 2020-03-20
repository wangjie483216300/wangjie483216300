#include <unistd.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include "set_lock.c"
int main(void){
	int fd;	
	fd = open("hello", O_RDWR | O_CREAT, 0644);
	if(fd < 0){
		printf("打开文件失败\n");			
    		exit(1);
	}
        /* 给文件上写入锁 */
	set_lock(fd, F_WRLCK);
    getchar();
     /* 给文件解锁 */
    set_lock(fd, F_UNLCK);	
	getchar();
    close(fd);
	return 0;
}			




