/* linux/drivers/input/keyboard/s3c-keypad.h 
 *
 * Driver header for Samsung SoC keypad.
 *
 * Kim Kyoungil, Copyright (c) 2006-2009 Samsung Electronics
 *      http://www.samsungsemi.com/
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */


#ifndef _S3C_KEYPAD_H_
#define _S3C_KEYPAD_H_

static void __iomem *key_base;


#if defined (CONFIG_MACH_S5PC110_P1P2)

#define KEYPAD_COLUMNS	14	
#define KEYPAD_ROWS	8
#define MAX_KEYPAD_NR	112

#else

   #define KEYPAD_COLUMNS       6
 #define KEYPAD_ROWS    10
 #define MAX_KEYPAD_NR  60

#endif




int keypad_keycode[] = {

#if defined (CONFIG_MACH_S5PC110_P1P2)
		0,  15,  399,   2,  16,  30,   0,   0,     //7
		0,   0,    0,   0,   0,   0, 100,  56,	  	//15			
		0,   0,   58,   4,  18,  32,  46,  57,	        //23			
		0,   0,    1,   3,  17,  31,  45,  44,	        //31			
		0,   0,    0,   0,   0,   0,   0,   0,	        //39			
		34,  20,   6,   5,  19,  33,  47,  48,	        //47			
		35,  21,   7,   8,  22,  36,  50,  49,          //55				
		56,   0,   0,  10,  24,  38,  52, 108,         //63			
		0,    0,   0,   0,  54,  42,   0,   0,	        //71			
		105,  0,   0,   9,  23,  37,  51,   0,	        //79			
		0,   97,  29,   0,   0,   0,   0,   0,	        //87			
		0,    0,   0, 150,  0,    0,   0,   0,	        //95			
		12,  106, 11,  25,  26,  39,  53, 103,      //103				
		14,  106,  3,  14,  27,  43,  40,  28,      //111			

#else
1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,
21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,
41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,


//#elif defined (CONFIG_MACH_S5PC110_ARIES)
//              50,0,0,0,58,42,

#endif
};


#ifdef CONFIG_CPU_S3C6410
#define KEYPAD_ROW_GPIOCON      S3C64XX_GPKCON
#define KEYPAD_ROW_GPIOPUD      S3C64XX_GPKPUD
#define KEYPAD_COL_GPIOCON      S3C64XX_GPLCON
#define KEYPAD_COL_GPIOPUD      S3C64XX_GPLPUD
#elif defined( CONFIG_CPU_S5PC100 )
#define KEYPAD_ROW_GPIOCON      S5PC1XX_GPH3CON
#define KEYPAD_ROW_GPIOPUD      S5PC1XX_GPH3PUD
#define KEYPAD_COL_GPIOCON      S5PC1XX_GPH2CON
#define KEYPAD_COL_GPIOPUD      S5PC1XX_GPH2PUD
#elif defined( CONFIG_CPU_S5PC110 ) || defined (CONFIG_CPU_S5PV210 )
#define KEYPAD_ROW_GPIOCON      S5PV210_GPH3CON
#define KEYPAD_ROW_GPIOPUD      S5PV210_GPH3PUD
#define KEYPAD_COL_GPIOCON      S5PV210_GPH2CON
#define KEYPAD_COL_GPIOPUD      S5PV210_GPH2PUD
#endif

#if defined(CONFIG_CPU_S3C6410)
#define KEYPAD_DELAY		(50)
#elif defined(CONFIG_CPU_S5PC100) || defined(CONFIG_CPU_S5PC110) || defined(CONFIG_CPU_S5PV210)
#define KEYPAD_DELAY		(300)  //600
#endif

#define	KEYIFCOL_CLEAR		(readl(key_base+S3C_KEYIFCOL) & ~0xffff)
#define	KEYIFCON_CLEAR		(readl(key_base+S3C_KEYIFCON) & ~0x1f)
#define KEYIFFC_DIV		(readl(key_base+S3C_KEYIFFC) | 0x1)

#define KEYCODE_UNKNOWN 10 

struct s3c_keypad {
	struct input_dev *dev;
	int nr_rows;	
	int no_cols;
	int total_keys; 
	int keycodes[MAX_KEYPAD_NR];
};


/*
 *   OK   : 0
 *   DOWN : 4
 *   UP   : 5
 */
#define KEY_ONE 0       /*OK KEY*/
#define KEY_TWO	5       /*UP KEY*/


extern void s3c_setup_keypad_cfg_gpio(int rows, int columns);

#endif				/* _S3C_KEYIF_H_ */