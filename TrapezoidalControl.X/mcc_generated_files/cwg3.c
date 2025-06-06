/**
   CWG3 Generated Driver File
 
   @Company
     Microchip Technology Inc.
 
   @File Name
     cwg3.c
 
   @Summary
     This is the generated driver implementation file for the CWG3 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs
 
   @Description
     This source file provides implementations for driver APIs for CWG3.
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
#include "cwg3.h"

/**
  Section: CWG3 APIs
*/

void CWG3_Initialize(void)
{
    // Set the CWG3 to the options selected in PIC10 / PIC12 / PIC16 / PIC18 MCUs

	// CWG3POLA non inverted; CWG3POLC non inverted; CWG3POLB non inverted; CWG3POLD non inverted; 
	CWG3CON1 = 0x00;

	// CWG3DBR 0; 
	CWG3DBR = 0x00;

	// CWG3DBF 0; 
	CWG3DBF = 0x00;

	// CWG3SHUTDOWN No Auto-shutdown; CWG3REN disabled; CWG3LSBD tri-stated; CWG3LSAC tri-stated; 
	CWG3AS0 = 0x14;

	// AS1E disabled; AS0E disabled; AS3E disabled; AS2E disabled; AS5E disabled; AS4E disabled; AS6E disabled; 
	CWG3AS1 = 0x00;

	// CWG3CS FOSC; 
	CWG3CLKCON = 0x00;

	// CWG3STRD disabled; CWG3STRB disabled; CWG3STRC disabled; CWG3STRA disabled; CWG3OVRD low; CWG3OVRA low; CWG3OVRB low; CWG3OVRC low; 
	CWG3STR = 0x00;

	// IS PWM6_OUT; 
	CWG3ISM = 0x06;

	// CWG3LD Buffer_not_loaded; CWG3EN enabled; CWG3MODE Sync Steering mode; 
	CWG3CON0 = 0x81;

}


void CWG3_AutoShutdownEventSet()
{
//    CWG3AS0bits.CWG3SHUTDOWN = 1;
}

void CWG3_AutoShutdownEventClear()
{
//    CWG3AS0bits.CWG3SHUTDOWN = 0;
}


/**
 End of File
*/