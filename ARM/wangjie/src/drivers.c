/***************************************************************************\
	Copyright (c) 2004-2007 threewater@up-tech.com, All rights reserved.
	by threewter	2004.4.26
\***************************************************************************/
	

/***************************************************************************\
    #˵��: ����������
	----------------------------------  Bug  --------------------------------------

	----------------------------------  TODO list  --------------------------------------

	----------------------------------����--------------------------------------
	2004-4-26	��Ӵ�����������s3c2410_serialx_driver

\***************************************************************************/

#include "../inc/macro.h"
#include "../inc/drivers.h"
//#include "../inc/sys/sysdrv.h"
#include "uhal/uart.h"

/***************************************************************************\
	for serial drivers
\***************************************************************************/
extern serial_driver_t s3c2410_serial0_driver, s3c2410_serial1_driver, 
		s3c2410_serial2_driver;
serial_driver_t* serial_drv[]={&s3c2410_serial0_driver, &s3c2410_serial1_driver, 
		&s3c2410_serial2_driver};
int NumberOfUartDrv=NumberOfArray(serial_drv);
//struct_Uart_Buffer	Uart_Buffer[NumberOfArray(serial_drv)];




