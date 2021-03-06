/*
 * terninal.c
 *
 *  Created on: 13 Jan 2017
 *      Author: Samsung
 */

//*****************************************************************************
//
//! Application startup display on UART
//!
//! \param  none
//!
//! \return none
//!
//*****************
#include "../includes/std_inc.h"
#include "../includes/inc.h"
#include "../includes/ex_common.h"
#include "../includes/driverlib.h"

void DisplayBanner(char * AppName)
{
	UART_PRINT("\n\n\n\r");
	UART_PRINT("\t\t *************************************************\n\r");
	UART_PRINT("\t\t      CC3200 %s Application       \n\r", AppName);
	UART_PRINT("\t\t *************************************************\n\r");
	UART_PRINT("\n\n\n\r");
	UART_PRINT("\33[H\33[2J");
	UART_PRINT(__TIME__);
	UART_PRINT(" ");
	UART_PRINT(__DATE__);
	UART_PRINT("\n\r");
	UART_PRINT("\n\rREADY...\n\r");
}

