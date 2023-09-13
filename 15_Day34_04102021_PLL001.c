/*
===============================================================================
 Name        : 15_Day34_04102021_PLL001.c

 Description : PLL Demonstration using led blink application

 TODO:  Q1. Find out the MSEL, NSEL, CCLKSEL, PCLKSEL0 and PCLKSEL1 values for the below cases from the excel sheet
 	TODOTESTCASE0: 	 Fcco = 400 MHz, Fin = 12MHz, CCLK = 100 MHz and Peripheral clock = 100/4 =25 MHz
 	TODOTESTCASE1:   Fcco = 384 MHz, Fin = 12MHz, CCLK = 96 MHz and Peripheral clock = 96/4 =24 MHz
 	TODOTESTCASE2:   Fcco = 384 MHz, Fin = 12MHz, CCLK = 48 MHz and Peripheral clock = 96/4 =24 MHz
 	TODOTESTCASE3:   Fcco = 288 MHz, Fin = 12MHz, CCLK = 96 MHz and Peripheral clock = 96/2 =48 MHz
 	TODOTESTCASE4:   Fcco = 288 MHz, Fin = 12MHz, CCLK = 72 MHz and Peripheral clock = 72/2 =36 MHz
 	TODOTESTCASE5:   Fcco = 396 MHz, Fin = 12MHz, CCLK = 12 MHz and Peripheral clock = 12/1 =12 MHz


 Layered Architecture used for this project
 ************************************
 Application layer-15_Day34_04102021_PLL001.c
 ************************************
 Board layer - led.c/.h, configboard.h
 ************************************
 Low level drivers or chip level - pinmux.c/.h, clock.c/.h, powercontrol.h, gpio.c/.h
 ************************************
 Hardware
 ************************************

===============================================================================
*/

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
/* Private includes ----------------------------------------------------------*/
#include "pinmux.h"
#include "clock.h"
#include "led.h"
/* Private typedef -----------------------------------------------------------*/

/* States of the system */
typedef enum {LEDOFF=0,LEDON=1}States_t;
/* Inputs to the system */
typedef enum {NONE=0,BUTTONPRESS=1} Inputs_t;

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

/**
  * @brief  Initialize all the hardware connected
  * @retval none
  */
void vAppHardwareInit(void)
{
	vPinmuxInitialize();
	vClockInitialization();
	vLedInitialize();
}

/**
  * @brief  Crude Delay
  * @retval none
  */
void vAppDelay(uint32_t count)
{
	int i,j;
	for(i=0;i<count;i++)
		for(j=0;j<0xA00;j++);
}


/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* MCU Configuration--------------------------------------------------------*/

  /* Initialize all configured peripherals */
   vAppHardwareInit();

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)  // for(;;)
  {
	      vLedOn(LED_0);
	  	  vAppDelay(1000);
	  	  vLedOff(LED_0);
	  	  vAppDelay(1000);
	  	  vLedOn(LED_1);
	      vAppDelay(1000);
	      vLedOff(LED_1);
	      vAppDelay(1000);

  }
  /* End of Application entry point */
}




