#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char* argv[]){
	char buff[10240];
	char srcfile[200];
	char destfile[200];
	int type;
	FILE *file1;
	FILE *file2;
	printf("请输入源文件名:\n");
	fgets(srcfile,200,stdin);
    if (srcfile[strlen(srcfile)-1] == '\n'){
        srcfile[strlen(srcfile)-1] = '\0'; 
    }
	if(srcfile==NULL){
		printf("源文件名错误!程序退出!");
		return -1;		
	}
	while(1){
		file1 = fopen(srcfile,"r+");
		if(file1==NULL){
			printf("打开源文件失败,请重新输入正确的源文件名:\n");
			fgets(srcfile,200,stdin);
            if (srcfile[strlen(srcfile)-1] == '\n'){
                    srcfile[strlen(srcfile)-1] = '\0'; 
            }
			if(srcfile==NULL){
				printf("源文件名错误!程序退出!");
				return -1;				
			}
			continue;
		}
		break;
	}
	printf("请输入目标文件的名字:\n");
	fgets(destfile,200,stdin);
    if (destfile[strlen(destfile)-1] == '\n'){
        destfile[strlen(destfile)-1] = '\0'; 
    }
	if(destfile==NULL){
		printf("目标文件名错误!程序退出!");
		exit(1);		
	}
    file2 = fopen(destfile,"r+");
	fseek(file1,0,SEEK_END);
	long lenth = ftell(file1);
	printf("请输入您想复制的类型号:1 、复制前一半 2 、复制后一半 3 、全部复制\n");
	type = getchar();
	while(1){
		if(type == 49){
			fseek(file1,0,SEEK_SET);
			fgets(buff,lenth/2,file1);
			fputs(buff,file2);
			break;
		}else if(type == 50){
			fseek(file1,-lenth/2,SEEK_END);
			fgets(buff,10240,file1);
			fputs(buff,file2);
			break;
		}else if(type == 51){	
			fseek(file1,0,SEEK_SET);
			fgets(buff,10240,file1);
			fputs(buff,file2);
			break;
		}else{
			printf("号码输入错误,请重新输入:\n");
			type = getchar();
			continue;
		}
		break;
	}
	printf("文件复制完成!\n");
	fclose(file1);
	fclose(file2);
	return 0;	
}

