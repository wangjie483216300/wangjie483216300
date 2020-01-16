/***************************************************************************\
	Copyright (c) 2004-2007 threewater@up-tech.com, All rights reserved.
	by threewter	2005.2.24
\***************************************************************************/
	

/***************************************************************************\
    #˵��: s3c2410 cpu ʱ������
	----------------------------------  Bug  --------------------------------------

	----------------------------------  TODO list  --------------------------------------

	----------------------------------����--------------------------------------
	2005-2-24	����

\***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "../inc/reg2410.h"
#include "../inc/serial.h"
//#include "../inc/io.h"
#include "../inc/lib.h"
#include "inc/bitfield.h"

/* Externl clock frequency used by CPU */
#define FIN	12000000

static __inline unsigned long
cal_bus_clk(unsigned long cpu_clk, unsigned long ratio, int who)
{
	if (!who) {	/* PCLK */
		switch (ratio) {
			case 0:
				return (cpu_clk);
			case 1:
			case 2:
				return (cpu_clk/2);
			case 3:
				return (cpu_clk/4);
			default:
				return 0;
		}
	} else {	/* HCLK */
		switch (ratio) {
			case 0:
			case 1:
				return (cpu_clk);
			case 2:
			case 3:
				return (cpu_clk/2);
			default:
				return 0;
		}
	}
}


/*
 * cpu clock = (((mdiv + 8) * FIN) / ((pdiv + 2) * (1 << sdiv)))
 *  FIN = Input Frequency (to CPU)
 */
unsigned long s3c2410_get_cpu_clk(void)
{
	unsigned long val = rMPLLCON;
	return (((GET_MDIV(val) + 8) * FIN) / \
		((GET_PDIV(val) + 2) * (1 << GET_SDIV(val))));
}

unsigned long s3c2410_get_bus_clk(int who)
{
	unsigned long cpu_clk = s3c2410_get_cpu_clk();
	unsigned long ratio = rCLKDIVN;
	return (cal_bus_clk(cpu_clk, ratio, who));
}

#define MEGA	(1000 * 1000)
int s3c2410_cpu_init(void)
{
	FCLK = s3c2410_get_cpu_clk();
	HCLK = s3c2410_get_bus_clk(GET_HCLK);
	PCLK = s3c2410_get_bus_clk(GET_PCLK);

	printk("CPU clock = %d.%03d Mhz,", FCLK / MEGA, FCLK % MEGA);
	hudelay(0);
	printk(" HCLK = %d.%03d Mhz,", HCLK / MEGA, HCLK % MEGA);
	hudelay(0);
	printk(" PCLK = %d.%03d Mhz\n", PCLK / MEGA, PCLK % MEGA);
	hudelay(0);

	return 0;
}

