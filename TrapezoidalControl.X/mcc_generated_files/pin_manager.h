/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F47K42
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set ADC_chan aliases
#define ADC_chan_TRIS                 TRISAbits.TRISA0
#define ADC_chan_LAT                  LATAbits.LATA0
#define ADC_chan_PORT                 PORTAbits.RA0
#define ADC_chan_WPU                  WPUAbits.WPUA0
#define ADC_chan_OD                   ODCONAbits.ODCA0
#define ADC_chan_ANS                  ANSELAbits.ANSELA0
#define ADC_chan_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define ADC_chan_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define ADC_chan_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define ADC_chan_GetValue()           PORTAbits.RA0
#define ADC_chan_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define ADC_chan_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define ADC_chan_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define ADC_chan_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define ADC_chan_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define ADC_chan_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define ADC_chan_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define ADC_chan_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set ADC_CS aliases
#define ADC_CS_TRIS                 TRISAbits.TRISA1
#define ADC_CS_LAT                  LATAbits.LATA1
#define ADC_CS_PORT                 PORTAbits.RA1
#define ADC_CS_WPU                  WPUAbits.WPUA1
#define ADC_CS_OD                   ODCONAbits.ODCA1
#define ADC_CS_ANS                  ANSELAbits.ANSELA1
#define ADC_CS_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define ADC_CS_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define ADC_CS_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define ADC_CS_GetValue()           PORTAbits.RA1
#define ADC_CS_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define ADC_CS_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define ADC_CS_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define ADC_CS_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define ADC_CS_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define ADC_CS_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define ADC_CS_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define ADC_CS_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set nSLEEP_RA4 aliases
#define nSLEEP_RA4_TRIS                 TRISAbits.TRISA4
#define nSLEEP_RA4_LAT                  LATAbits.LATA4
#define nSLEEP_RA4_PORT                 PORTAbits.RA4
#define nSLEEP_RA4_WPU                  WPUAbits.WPUA4
#define nSLEEP_RA4_OD                   ODCONAbits.ODCA4
#define nSLEEP_RA4_ANS                  ANSELAbits.ANSELA4
#define nSLEEP_RA4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define nSLEEP_RA4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define nSLEEP_RA4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define nSLEEP_RA4_GetValue()           PORTAbits.RA4
#define nSLEEP_RA4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define nSLEEP_RA4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define nSLEEP_RA4_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define nSLEEP_RA4_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define nSLEEP_RA4_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define nSLEEP_RA4_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define nSLEEP_RA4_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define nSLEEP_RA4_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set DRIVOFF_RA5 aliases
#define DRIVOFF_RA5_TRIS                 TRISAbits.TRISA5
#define DRIVOFF_RA5_LAT                  LATAbits.LATA5
#define DRIVOFF_RA5_PORT                 PORTAbits.RA5
#define DRIVOFF_RA5_WPU                  WPUAbits.WPUA5
#define DRIVOFF_RA5_OD                   ODCONAbits.ODCA5
#define DRIVOFF_RA5_ANS                  ANSELAbits.ANSELA5
#define DRIVOFF_RA5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define DRIVOFF_RA5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define DRIVOFF_RA5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define DRIVOFF_RA5_GetValue()           PORTAbits.RA5
#define DRIVOFF_RA5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define DRIVOFF_RA5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define DRIVOFF_RA5_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define DRIVOFF_RA5_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define DRIVOFF_RA5_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define DRIVOFF_RA5_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define DRIVOFF_RA5_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define DRIVOFF_RA5_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set channel_ANA6 aliases
#define channel_ANA6_TRIS                 TRISAbits.TRISA6
#define channel_ANA6_LAT                  LATAbits.LATA6
#define channel_ANA6_PORT                 PORTAbits.RA6
#define channel_ANA6_WPU                  WPUAbits.WPUA6
#define channel_ANA6_OD                   ODCONAbits.ODCA6
#define channel_ANA6_ANS                  ANSELAbits.ANSELA6
#define channel_ANA6_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define channel_ANA6_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define channel_ANA6_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define channel_ANA6_GetValue()           PORTAbits.RA6
#define channel_ANA6_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define channel_ANA6_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define channel_ANA6_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define channel_ANA6_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define channel_ANA6_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define channel_ANA6_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define channel_ANA6_SetAnalogMode()      do { ANSELAbits.ANSELA6 = 1; } while(0)
#define channel_ANA6_SetDigitalMode()     do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set channel_ANA7 aliases
#define channel_ANA7_TRIS                 TRISAbits.TRISA7
#define channel_ANA7_LAT                  LATAbits.LATA7
#define channel_ANA7_PORT                 PORTAbits.RA7
#define channel_ANA7_WPU                  WPUAbits.WPUA7
#define channel_ANA7_OD                   ODCONAbits.ODCA7
#define channel_ANA7_ANS                  ANSELAbits.ANSELA7
#define channel_ANA7_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define channel_ANA7_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define channel_ANA7_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define channel_ANA7_GetValue()           PORTAbits.RA7
#define channel_ANA7_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define channel_ANA7_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define channel_ANA7_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define channel_ANA7_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define channel_ANA7_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define channel_ANA7_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define channel_ANA7_SetAnalogMode()      do { ANSELAbits.ANSELA7 = 1; } while(0)
#define channel_ANA7_SetDigitalMode()     do { ANSELAbits.ANSELA7 = 0; } while(0)

// get/set INDEX_CHC_RB0 aliases
#define INDEX_CHC_RB0_TRIS                 TRISBbits.TRISB0
#define INDEX_CHC_RB0_LAT                  LATBbits.LATB0
#define INDEX_CHC_RB0_PORT                 PORTBbits.RB0
#define INDEX_CHC_RB0_WPU                  WPUBbits.WPUB0
#define INDEX_CHC_RB0_OD                   ODCONBbits.ODCB0
#define INDEX_CHC_RB0_ANS                  ANSELBbits.ANSELB0
#define INDEX_CHC_RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define INDEX_CHC_RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define INDEX_CHC_RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define INDEX_CHC_RB0_GetValue()           PORTBbits.RB0
#define INDEX_CHC_RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define INDEX_CHC_RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define INDEX_CHC_RB0_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define INDEX_CHC_RB0_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define INDEX_CHC_RB0_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define INDEX_CHC_RB0_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define INDEX_CHC_RB0_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define INDEX_CHC_RB0_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()              PORTBbits.RB1
#define RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()             do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()           do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode()         do { ANSELBbits.ANSELB1 = 1; } while(0)
#define RB1_SetDigitalMode()        do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set RB2 procedures
#define RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RB2_GetValue()              PORTBbits.RB2
#define RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define RB2_SetPullup()             do { WPUBbits.WPUB2 = 1; } while(0)
#define RB2_ResetPullup()           do { WPUBbits.WPUB2 = 0; } while(0)
#define RB2_SetAnalogMode()         do { ANSELBbits.ANSELB2 = 1; } while(0)
#define RB2_SetDigitalMode()        do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set RB3 procedures
#define RB3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define RB3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define RB3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define RB3_GetValue()              PORTBbits.RB3
#define RB3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define RB3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define RB3_SetPullup()             do { WPUBbits.WPUB3 = 1; } while(0)
#define RB3_ResetPullup()           do { WPUBbits.WPUB3 = 0; } while(0)
#define RB3_SetAnalogMode()         do { ANSELBbits.ANSELB3 = 1; } while(0)
#define RB3_SetDigitalMode()        do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSELB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RB5 procedures
#define RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()              PORTBbits.RB5
#define RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()             do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()           do { WPUBbits.WPUB5 = 0; } while(0)
#define RB5_SetAnalogMode()         do { ANSELBbits.ANSELB5 = 1; } while(0)
#define RB5_SetDigitalMode()        do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set channel_ANC0 aliases
#define channel_ANC0_TRIS                 TRISCbits.TRISC0
#define channel_ANC0_LAT                  LATCbits.LATC0
#define channel_ANC0_PORT                 PORTCbits.RC0
#define channel_ANC0_WPU                  WPUCbits.WPUC0
#define channel_ANC0_OD                   ODCONCbits.ODCC0
#define channel_ANC0_ANS                  ANSELCbits.ANSELC0
#define channel_ANC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define channel_ANC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define channel_ANC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define channel_ANC0_GetValue()           PORTCbits.RC0
#define channel_ANC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define channel_ANC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define channel_ANC0_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define channel_ANC0_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define channel_ANC0_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define channel_ANC0_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define channel_ANC0_SetAnalogMode()      do { ANSELCbits.ANSELC0 = 1; } while(0)
#define channel_ANC0_SetDigitalMode()     do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSELC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSELC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()              PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RC5_SetPullup()             do { WPUCbits.WPUC5 = 1; } while(0)
#define RC5_ResetPullup()           do { WPUCbits.WPUC5 = 0; } while(0)
#define RC5_SetAnalogMode()         do { ANSELCbits.ANSELC5 = 1; } while(0)
#define RC5_SetDigitalMode()        do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set CHA_RC6 aliases
#define CHA_RC6_TRIS                 TRISCbits.TRISC6
#define CHA_RC6_LAT                  LATCbits.LATC6
#define CHA_RC6_PORT                 PORTCbits.RC6
#define CHA_RC6_WPU                  WPUCbits.WPUC6
#define CHA_RC6_OD                   ODCONCbits.ODCC6
#define CHA_RC6_ANS                  ANSELCbits.ANSELC6
#define CHA_RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define CHA_RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define CHA_RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define CHA_RC6_GetValue()           PORTCbits.RC6
#define CHA_RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define CHA_RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define CHA_RC6_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define CHA_RC6_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define CHA_RC6_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define CHA_RC6_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define CHA_RC6_SetAnalogMode()      do { ANSELCbits.ANSELC6 = 1; } while(0)
#define CHA_RC6_SetDigitalMode()     do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set RD0 procedures
#define RD0_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define RD0_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define RD0_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define RD0_GetValue()              PORTDbits.RD0
#define RD0_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define RD0_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define RD0_SetPullup()             do { WPUDbits.WPUD0 = 1; } while(0)
#define RD0_ResetPullup()           do { WPUDbits.WPUD0 = 0; } while(0)
#define RD0_SetAnalogMode()         do { ANSELDbits.ANSELD0 = 1; } while(0)
#define RD0_SetDigitalMode()        do { ANSELDbits.ANSELD0 = 0; } while(0)

// get/set RD1 procedures
#define RD1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define RD1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define RD1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define RD1_GetValue()              PORTDbits.RD1
#define RD1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define RD1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define RD1_SetPullup()             do { WPUDbits.WPUD1 = 1; } while(0)
#define RD1_ResetPullup()           do { WPUDbits.WPUD1 = 0; } while(0)
#define RD1_SetAnalogMode()         do { ANSELDbits.ANSELD1 = 1; } while(0)
#define RD1_SetDigitalMode()        do { ANSELDbits.ANSELD1 = 0; } while(0)

// get/set CHB_RD3 aliases
#define CHB_RD3_TRIS                 TRISDbits.TRISD3
#define CHB_RD3_LAT                  LATDbits.LATD3
#define CHB_RD3_PORT                 PORTDbits.RD3
#define CHB_RD3_WPU                  WPUDbits.WPUD3
#define CHB_RD3_OD                   ODCONDbits.ODCD3
#define CHB_RD3_ANS                  ANSELDbits.ANSELD3
#define CHB_RD3_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define CHB_RD3_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define CHB_RD3_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define CHB_RD3_GetValue()           PORTDbits.RD3
#define CHB_RD3_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define CHB_RD3_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define CHB_RD3_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define CHB_RD3_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define CHB_RD3_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define CHB_RD3_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define CHB_RD3_SetAnalogMode()      do { ANSELDbits.ANSELD3 = 1; } while(0)
#define CHB_RD3_SetDigitalMode()     do { ANSELDbits.ANSELD3 = 0; } while(0)

// get/set HallC_RD4 aliases
#define HallC_RD4_TRIS                 TRISDbits.TRISD4
#define HallC_RD4_LAT                  LATDbits.LATD4
#define HallC_RD4_PORT                 PORTDbits.RD4
#define HallC_RD4_WPU                  WPUDbits.WPUD4
#define HallC_RD4_OD                   ODCONDbits.ODCD4
#define HallC_RD4_ANS                  ANSELDbits.ANSELD4
#define HallC_RD4_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define HallC_RD4_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define HallC_RD4_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define HallC_RD4_GetValue()           PORTDbits.RD4
#define HallC_RD4_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define HallC_RD4_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define HallC_RD4_SetPullup()          do { WPUDbits.WPUD4 = 1; } while(0)
#define HallC_RD4_ResetPullup()        do { WPUDbits.WPUD4 = 0; } while(0)
#define HallC_RD4_SetPushPull()        do { ODCONDbits.ODCD4 = 0; } while(0)
#define HallC_RD4_SetOpenDrain()       do { ODCONDbits.ODCD4 = 1; } while(0)
#define HallC_RD4_SetAnalogMode()      do { ANSELDbits.ANSELD4 = 1; } while(0)
#define HallC_RD4_SetDigitalMode()     do { ANSELDbits.ANSELD4 = 0; } while(0)

// get/set HallB_RD5 aliases
#define HallB_RD5_TRIS                 TRISDbits.TRISD5
#define HallB_RD5_LAT                  LATDbits.LATD5
#define HallB_RD5_PORT                 PORTDbits.RD5
#define HallB_RD5_WPU                  WPUDbits.WPUD5
#define HallB_RD5_OD                   ODCONDbits.ODCD5
#define HallB_RD5_ANS                  ANSELDbits.ANSELD5
#define HallB_RD5_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define HallB_RD5_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define HallB_RD5_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define HallB_RD5_GetValue()           PORTDbits.RD5
#define HallB_RD5_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define HallB_RD5_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define HallB_RD5_SetPullup()          do { WPUDbits.WPUD5 = 1; } while(0)
#define HallB_RD5_ResetPullup()        do { WPUDbits.WPUD5 = 0; } while(0)
#define HallB_RD5_SetPushPull()        do { ODCONDbits.ODCD5 = 0; } while(0)
#define HallB_RD5_SetOpenDrain()       do { ODCONDbits.ODCD5 = 1; } while(0)
#define HallB_RD5_SetAnalogMode()      do { ANSELDbits.ANSELD5 = 1; } while(0)
#define HallB_RD5_SetDigitalMode()     do { ANSELDbits.ANSELD5 = 0; } while(0)

// get/set HallA_RD6 aliases
#define HallA_RD6_TRIS                 TRISDbits.TRISD6
#define HallA_RD6_LAT                  LATDbits.LATD6
#define HallA_RD6_PORT                 PORTDbits.RD6
#define HallA_RD6_WPU                  WPUDbits.WPUD6
#define HallA_RD6_OD                   ODCONDbits.ODCD6
#define HallA_RD6_ANS                  ANSELDbits.ANSELD6
#define HallA_RD6_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define HallA_RD6_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define HallA_RD6_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define HallA_RD6_GetValue()           PORTDbits.RD6
#define HallA_RD6_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define HallA_RD6_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define HallA_RD6_SetPullup()          do { WPUDbits.WPUD6 = 1; } while(0)
#define HallA_RD6_ResetPullup()        do { WPUDbits.WPUD6 = 0; } while(0)
#define HallA_RD6_SetPushPull()        do { ODCONDbits.ODCD6 = 0; } while(0)
#define HallA_RD6_SetOpenDrain()       do { ODCONDbits.ODCD6 = 1; } while(0)
#define HallA_RD6_SetAnalogMode()      do { ANSELDbits.ANSELD6 = 1; } while(0)
#define HallA_RD6_SetDigitalMode()     do { ANSELDbits.ANSELD6 = 0; } while(0)

// get/set RE0 procedures
#define RE0_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define RE0_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define RE0_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define RE0_GetValue()              PORTEbits.RE0
#define RE0_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define RE0_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define RE0_SetPullup()             do { WPUEbits.WPUE0 = 1; } while(0)
#define RE0_ResetPullup()           do { WPUEbits.WPUE0 = 0; } while(0)
#define RE0_SetAnalogMode()         do { ANSELEbits.ANSELE0 = 1; } while(0)
#define RE0_SetDigitalMode()        do { ANSELEbits.ANSELE0 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF0 pin functionality
 * @Example
    IOCBF0_ISR();
 */
void IOCBF0_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF0 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF0 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF0_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF0_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF0 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF0_SetInterruptHandler() method.
    This handler is called every time the IOCBF0 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF0_SetInterruptHandler(IOCBF0_InterruptHandler);

*/
extern void (*IOCBF0_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF0 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF0_SetInterruptHandler() method.
    This handler is called every time the IOCBF0 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF0_SetInterruptHandler(IOCBF0_DefaultInterruptHandler);

*/
void IOCBF0_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/