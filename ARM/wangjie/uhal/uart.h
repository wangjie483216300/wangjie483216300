/*#ifndef __UART_H__
#define __UART_H__



#define UART_REVBUFFER_SIZE		1024

typedef struct{
	U8 Buffer[UART_REVBUFFER_SIZE];
	OS_EVENT *Uart_Rev_mbox;                   //Uart0 receive mail box
	U8 *pUart_rev;	//Uart0 ���ջ�����ָ��
	U8 *pUart_read;	//Uart0 ��������ָ��
	int nRev_Uart;	//�趨��Uart�����ַ���
}struct_Uart_Buffer;




#endif //#ifndef __UART_H__*/

