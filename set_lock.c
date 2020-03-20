#include <unistd.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
int set_lock(int fd,int type){
	struct flock lock;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_type = type;
	lock.l_pid = -1;
	/**判断文件是否能够上锁*/
	fcntl(fd, F_GETLK, &lock);
	if (lock.l_type != F_UNLCK)
	{
       		 /* 判断文件不能上锁的原因 */
 		if (lock.l_type == F_RDLCK) /* 该文件已有读取锁 */	  
       		{
			printf("读取锁已被线程 %d 部署 \n", lock.l_pid);
		}else if (lock.l_type == F_WRLCK)/**该文件已有写入锁*/ 
		{
			printf("写入锁已被线程 %d 部署\n", lock.l_pid);
		}					
	}
	lock.l_type = type;
    /**设置阻塞锁*/
	if ((fcntl(fd, F_SETLKW, &lock)) < 0)
	{
		printf("上锁失败:类型为 = %d\n", lock.l_type);
		return 1;
	}	
	switch(lock.l_type){
		case F_RDLCK:
			printf("线程: %d 设置读取锁\n", getpid());
			break;
		case F_WRLCK:
			printf("线程: %d 设置写入锁\n", getpid());
			break;
		case F_UNLCK:		
			printf("线程: %d 解除锁\n", getpid());
            break;
		default:
			break;
	}
	return 0;
}
