#include "../inc/drivers.h"
#include "../inc/lib.h"
#include <string.h>
#include <stdio.h>
#include "inc/lcd320.h"
#include "inc/macro.h"
#include  "inc/reg2410.h"
#pragma import(__use_no_semihosting_swi)  // ensure no functions that use semihosting 

void  ARMTargetInit(void); 
extern U32 LCDBufferII2[480][640];
#define rADCCON		(*(volatile unsigned *)0x58000000)
#define rADCDAT0	(*(volatile unsigned *)0x5800000C)

int main(void)
{   
	
	int i,j,k;
	int Dianwei1,Dianwei2,Dianwei3;
	int dw1,dw2,dw3;
    U32 jcolor;

	ARMTargetInit();	//开发版初始化
	LCD_Init();	//LCD初始化
	
    rADCCON = (1<<14)|(1<<0)|(49<<6);//设置A/D前置器启动，开始A/D转换 启动后清除该位，设置透视植
    
    Dianwei1 = rADCDAT0;
    
    
    
    while(1){
    
    	while((rADCCON&(1<<15))==0);
    	Dianwei1 = rADCDAT0&0x3FF;//将通道 AIN3 的电位值赋给Dianwei1
    	dw1=Dianwei1/4;//确保<255
    	rADCCON |= (0<<3);
    	rADCCON |=1;
    	Uart_Printf(0,"蓝色色颜色值为：%d   ",dw1);
    
    	
    	while((rADCCON&(1<<15))==0);
    	Dianwei2 = rADCDAT0&0x3FF;
    	dw2=Dianwei2/4;//确保<255
    	rADCCON &=~(7<<3);//将通道 AIN3 AIN4 AIN5 清零，（111左移3位，反码相与）
    	rADCCON |= (1<<3);//选择通道 AIN1 (100左移3位)
   	    rADCCON |= 1;
   	    Uart_Printf(0,"绿色颜色值为：%d   ",dw2);
   	    
   	    
   	    while((rADCCON&(1<<15))==0);
    	Dianwei3 = rADCDAT0&0x3FF;//将通道 AIN5 的电位值赋给Dianwei3
    	dw3=Dianwei3/4;
    	rADCCON &=~(7<<3);//将通道 AIN3 AIN4 AIN5 清零，（111左移3位，反码相与）
    	rADCCON |= (2<<3);//选择通道 AIN2 （101左移3位）
    	rADCCON |= 1;                  
    	Uart_Printf(0,"红色颜色值为：%d   \n",dw3);
    	
    	
    	hudelay(50);
    	rADCCON &=~(7<<3);
        jcolor=((Dianwei1&0x3ff)<<16)|((Dianwei2&0x3ff)<<8)|(Dianwei3&0x3ff);   
		//三个值分别为R,G B的值,共24位,用十六进制表示为0x00000000,后六位表示R,G,B,所以要将三个数转换为十六进制，然后拼接，分别左移16位，左移8位，不移位，实现拼接。
		Uart_Printf(0,"屏幕显示的值为颜色值为：%d\n\n\n",jcolor);
		for(i=0;i<480;i++){
			for(j=0;j<640;j++){
				LCDBufferII2[i][j]=jcolor;
				
			}
		}
		LCD_Refresh() ; 
   
    }
  }
	
