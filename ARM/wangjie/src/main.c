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

	ARMTargetInit();	//�������ʼ��
	LCD_Init();	//LCD��ʼ��
	
    rADCCON = (1<<14)|(1<<0)|(49<<6);//����A/Dǰ������������ʼA/Dת�� �����������λ������͸��ֲ
    
    Dianwei1 = rADCDAT0;
    
    
    
    while(1){
    
    	while((rADCCON&(1<<15))==0);
    	Dianwei1 = rADCDAT0&0x3FF;//��ͨ�� AIN3 �ĵ�λֵ����Dianwei1
    	dw1=Dianwei1/4;//ȷ��<255
    	rADCCON |= (0<<3);
    	rADCCON |=1;
    	Uart_Printf(0,"��ɫɫ��ɫֵΪ��%d   ",dw1);
    
    	
    	while((rADCCON&(1<<15))==0);
    	Dianwei2 = rADCDAT0&0x3FF;
    	dw2=Dianwei2/4;//ȷ��<255
    	rADCCON &=~(7<<3);//��ͨ�� AIN3 AIN4 AIN5 ���㣬��111����3λ���������룩
    	rADCCON |= (1<<3);//ѡ��ͨ�� AIN1 (100����3λ)
   	    rADCCON |= 1;
   	    Uart_Printf(0,"��ɫ��ɫֵΪ��%d   ",dw2);
   	    
   	    
   	    while((rADCCON&(1<<15))==0);
    	Dianwei3 = rADCDAT0&0x3FF;//��ͨ�� AIN5 �ĵ�λֵ����Dianwei3
    	dw3=Dianwei3/4;
    	rADCCON &=~(7<<3);//��ͨ�� AIN3 AIN4 AIN5 ���㣬��111����3λ���������룩
    	rADCCON |= (2<<3);//ѡ��ͨ�� AIN2 ��101����3λ��
    	rADCCON |= 1;                  
    	Uart_Printf(0,"��ɫ��ɫֵΪ��%d   \n",dw3);
    	
    	
    	hudelay(50);
    	rADCCON &=~(7<<3);
        jcolor=((Dianwei1&0x3ff)<<16)|((Dianwei2&0x3ff)<<8)|(Dianwei3&0x3ff);   
		//����ֵ�ֱ�ΪR,G B��ֵ,��24λ,��ʮ�����Ʊ�ʾΪ0x00000000,����λ��ʾR,G,B,����Ҫ��������ת��Ϊʮ�����ƣ�Ȼ��ƴ�ӣ��ֱ�����16λ������8λ������λ��ʵ��ƴ�ӡ�
		Uart_Printf(0,"��Ļ��ʾ��ֵΪ��ɫֵΪ��%d\n\n\n",jcolor);
		for(i=0;i<480;i++){
			for(j=0;j<640;j++){
				LCDBufferII2[i][j]=jcolor;
				
			}
		}
		LCD_Refresh() ; //��Ļ����
   
    }
  }
    
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
   // hudelay(5000);
    

 // for (i=0;i<9;i++)
    // {  switch (i)
     //   {  case 0: jcolor=0x00000000;  //RGB��Ϊ0   ��ɫ
   //                break;
   //        case 1: jcolor=0x000000f8;  //R   ��ɫ
   //                break;
    //       case 2: jcolor=0x0000f0f8;  //R  and G ��ɫ
   //                break;
    //       case 3: jcolor=0x0000fcf8;   //R  and G ��
    //               break;
    //       case 4: jcolor=0x0000fc00;  //G  ��ɫ
    //               break;
    //       case 5: jcolor=0x00f8fc00;  //G  B   ��ɫ
    //               break;
     //      case 6: jcolor=0x00f80000;  //B    ��ɫ
     //              break;
     //      case 7: jcolor=0x00f800f8;  //R  and B   ��ɫ
      //             break;
      //     case 8: jcolor=0x00f8fcf8;  //RGB   ��ɫ
      //             break;   
      //   }
       
     // for (k=0;k<480;k++)
     //   for (j=i*64;j<i*64+64;j++) 
      //    LCDBufferII2[k][j]=jcolor; 
     // }

  //jcolor=0x000000ff;
  //for (i=0;i<480;i++)
   //   {if (i==160||i==320)
   //      jcolor<<=8;
   //    for (j=576;j<640;j++)  
  //        LCDBufferII2[i][j]=jcolor;
    //   }

   // LCD_Refresh() ; 
    //Uart_Printf(0,"\nrLCDCON1 is %x",rLCDCON1);    
   // while(1);
	//return 0;
	
	
	
//}