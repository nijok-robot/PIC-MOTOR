/**
  Generated Interrupt Manager Source File

  @Company:
    Microchip Technology Inc.

  @File Name:
    interrupt_manager.c

  @Summary:
    This is the Interrupt Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description:
    This header file provides implementations for global interrupt handling.
    For individual peripheral handlers please see the peripheral driver for
    all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F47K42
        Driver Version    :  2.04
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above or later
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

#include "interrupt_manager.h"
#include "mcc.h"
#include "../UART.h"
#include "../ADCMax.h"
#include "../DirCW.h"
#include "../DirCCW.h"
#include "../Joystick.h"
//#include "tmr5.h"

bool extern prevHallA;
bool extern prevHallB;
bool extern prevHallC;
bool extern timer6;
bool extern ascii;
bool extern index;
bool extern enviado;
bool extern calcPromedio;
int extern contConm;
int extern i;
uint32_t extern sumatoriaCorriente;
uint8_t extern leidos[4];
volatile int extern leidos_ptr;
uint8_t dato;
int extern duty;
volatile extern uint32_t pulse_count;
volatile extern uint16_t rps; // Stores calculated RPM
volatile extern uint8_t measuring;
uint16_t extern send_data[4];
uint16_t extern adc_meas;
//volatile uint16_t extern timer5ReloadVal;

void INTERRUPT_Initialize(void) {
    // Disable Interrupt Priority Vectors (16CXXX Compatibility Mode)
    INTCON0bits.IPEN = 0;
}

void __interrupt() INTERRUPT_InterruptManager(void) {
    // interrupt handler
    /*
     * E Enable 
     * F Flag -> 1 Terminó,  0 Está libre
     * Siempre se debe bajar antes y luego si se ejecuta nuestro codigo
     */

    if (PIE3bits.U1RXIE == 1 && PIR3bits.U1RXIF == 1) {

        //Prioridad recepcion comandos
        PIR3bits.U1RXIF = 0;
        UART1_Receive();
    }
    if (PIE8bits.TMR5IE == 1 && PIR8bits.TMR5IF == 1) {
        PIR8bits.TMR5IF = 0;
        T5CONbits.TMR5ON = 0;
        //INTERRUMPE CADA 500ms
        if (leidos[0] == 0x44) {//0x56 es el carater D
            if (duty > 0) {
                duty--;
                PWM6_LoadDutyValue(duty);
            }
        }

        if (leidos[0] == 0x55) {//0x56 es el carater U
            if (duty < 599) {
                duty++;
                PWM6_LoadDutyValue(duty);
            }
        }
        PIE8bits.TMR5IE = 0;
        

    }

    if (PIE7bits.TMR4IE == 1 && PIR7bits.TMR4IF == 1) {
        //INTERRUMPE CADA 42US DURA 11.7us
        //CHA_RC6_SetHigh();
        PIR7bits.TMR4IF = 0;
                
        /*
         * 1. Revisar los estados actuales de los Hall
         * 2. Comparar estados actuales con los previos
         * 3. Si hubo un cambio ejecutar la función respectiva
         */
        actualizarEstadoMotor();
        if (contConm == 6) {
            PIE9bits.TMR6IE = 0;
            contConm = -1;
            index = 0;
            calcPromedio = 1;
            // Llamar funcion convertir ascii y enviar uart 
        }
//        Temp();
//        send_data[2] = adc_meas;
//        ascii = 1;
       
    }

    if (PIE9bits.TMR6IE == 1 && PIR9bits.TMR6IF == 1)//Timer que lleva la cuenta del 80% del tiempo q tarda la conmut
    {
        PIR9bits.TMR6IF = 0; // Limpia la bandera de interrupción
        T6CONbits.TMR6ON = 0; // Apaga el Timer 6
        timer6 = 1;
    }

    if (PIE4bits.TMR1IE == 1 && PIR4bits.TMR1IF == 1) {
        //este timer cuenta 1 segundo
        PIR4bits.TMR1IF = 0;
        T1CONbits.TMR1ON = 0; // Stop Timer1
        measuring = 0;
        rps = (uint16_t) (pulse_count); //pq esto ya da pusos en 1 segundo
        send_data[0] = rps;
        T6PR = (int) (8354.35 / rps); //por qué
        pulse_count = 0; // Reset counter for next measurement
        Temp();
        send_data[2] = adc_meas;
        send_data[3] = duty;
        PIE4bits.TMR1IE = 0;
        ascii = 1;
    }

    if (PIE0bits.IOCIE == 1 && PIR0bits.IOCIF == 1) {

        if (IOCBFbits.IOCBF0 == 1) {
            IOCBFbits.IOCBF0 = 0;
            index = 1;
            sumatoriaCorriente = 0;
            if (measuring == 0) {
                // First pulse: Start Timer1
                measuring = 1;
                pulse_count = 0;
                TMR1H = 0;
                TMR1L = 0;
                PIE4bits.TMR1IE = 1;
                PIR4bits.TMR1IF = 0;
                T1CONbits.TMR1ON = 1; // Start Timer1
                PIE8bits.TMR5IE = 1;
                PIR8bits.TMR5IF = 0;
                T5CONbits.TMR5ON = 1; // Start Timer1
            } else if (measuring == 1) {//!(LATCbits.LATC6 == ~LATCbits.LATC6)){
                pulse_count++; //por qué
            }
        }
    }
    if (PIE3bits.U1TXIE == 1 && PIR3bits.U1TXIF == 1) {
        PIR3bits.U1TXIF = 0;
        RutinaTransmicionUSART_ASCII();
    } else {
        //Unhandled Interrupt
    }

}
/**
 End of File
 */
