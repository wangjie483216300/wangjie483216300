/***************************************************************************\
	Copyright (c) 2004-2007 threewater@up-tech.com, All rights reserved.
	by threewter	2004.5.12
\***************************************************************************/
/***************************************************************************\
    #˵��: �ж�ע����غ�������
	----------------------------------  Bug  --------------------------------------

	----------------------------------  TODO list  --------------------------------------

	----------------------------------����--------------------------------------

	2004-5-12	��ֲ

\***************************************************************************/

#ifndef __ISR_H__
#define __ISR_H__


#define NORMAL_IRQ_OFFSET	32


#define EXT_IRQ_OFFSET		(20 +NORMAL_IRQ_OFFSET)


#define IRQ_RXD0		(0 +EXT_IRQ_OFFSET)

#define IRQ_RXD1		(3 +EXT_IRQ_OFFSET)

#define IRQ_RXD2		(6 +EXT_IRQ_OFFSET)

void ISR_IrqHandler(void);


#endif	 //#ifndef __ISR_H__