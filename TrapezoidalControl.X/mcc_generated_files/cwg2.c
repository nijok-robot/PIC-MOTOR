/**
   CWG2 Generated Driver File
 
   @Company
     Microchip Technology Inc.
 
   @File Name
     cwg2.c
 
   @Summary
     This is the generated driver implementation file for the CWG2 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs
 
   @Description
     This source file provides implementations for driver APIs for CWG2.
     Generation Information :
         Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
         Device            :  PIC18F47K42
         Driver Version    :  2.11
     The generated drivers are tested against the following:
         Compiler          :  XC8 2.36 and above or later
         MPLAB             :  MPLAB X 6.00
 */ 

 /*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/
 
 /**
   Section: Included Files
 */

#include <xc.h>
#include "cwg2.h"

/**
  Section: CWG2 APIs
*/

void CWG2_Initialize(void)
{
    // Set the CWG2 to the options selected in PIC10 / PIC12 / PIC16 / PIC18 MCUs

	// CWG2POLA non inverted; CWG2POLC non inverted; CWG2POLB non inverted; CWG2POLD non inverted; 
	CWG2CON1 = 0x00;

	// CWG2DBR 0; 
	CWG2DBR = 0x00;

	// CWG2DBF 0; 
	CWG2DBF = 0x00;

	// CWG2SHUTDOWN No Auto-shutdown; CWG2REN disabled; CWG2LSBD tri-stated; CWG2LSAC tri-stated; 
	CWG2AS0 = 0x14;

	// AS1E disabled; AS0E disabled; AS3E disabled; AS2E disabled; AS5E disabled; AS4E disabled; AS6E disabled; 
	CWG2AS1 = 0x00;

	// CWG2CS FOSC; 
	CWG2CLKCON = 0x00;

	// CWG2STRD disabled; CWG2STRB disabled; CWG2STRC disabled; CWG2STRA disabled; CWG2OVRD low; CWG2OVRA low; CWG2OVRB low; CWG2OVRC low; 
	CWG2STR = 0x00;

	// IS PWM6_OUT; 
	CWG2ISM = 0x06;

	// CWG2LD Buffer_not_loaded; CWG2EN enabled; CWG2MODE Sync Steering mode; 
	CWG2CON0 = 0x81;

}


void CWG2_AutoShutdownEventSet()
{
 //   CWG2AS0bits.CWG2SHUTDOWN = 1;
}

void CWG2_AutoShutdownEventClear()
{
 //   CWG2AS0bits.CWG2SHUTDOWN = 0;
}


/**
 End of File
*/