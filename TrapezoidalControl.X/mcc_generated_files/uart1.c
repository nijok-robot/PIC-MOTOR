/**
  UART1 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    uart1.c

  @Summary
    This is the generated driver implementation file for the UART1 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides APIs for UART1.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F47K42
        Driver Version    :  2.4.1
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
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
#include "uart1.h"

uint8_t extern leidos[4];
volatile int extern leidos_ptr;
bool extern cambioVelocidad;
uint8_t dato;

uint16_t suma;
/**
  Section: Macro Declarations
 */
#define UART1_TX_BUFFER_SIZE 8


#define UART1_RX_BUFFER_SIZE 8
#define UART1_RX_BUFFER_MASK (UART1_RX_BUFFER_SIZE - 1)
/**
  Section: Global Variables
 */

static volatile uint8_t uart1TxHead = 0;
static volatile uint8_t uart1TxTail = 0;
static volatile uint8_t uart1TxBuffer[UART1_TX_BUFFER_SIZE];
volatile uint8_t uart1TxBufferRemaining;

static volatile uint8_t uart1RxHead = 0;
static volatile uint8_t uart1RxTail = 0;
static volatile uint8_t uart1RxBuffer[UART1_RX_BUFFER_SIZE];
static volatile uart1_status_t uart1RxStatusBuffer[UART1_RX_BUFFER_SIZE];
volatile uint8_t uart1RxCount;
static volatile uart1_status_t uart1RxLastError;

/**
  Section: UART1 APIs
 */
void (*UART1_FramingErrorHandler)(void);
void (*UART1_OverrunErrorHandler)(void);
void (*UART1_ErrorHandler)(void);
static void (*UART1_RxCompleteInterruptHandler)(void);

void UART1_DefaultFramingErrorHandler(void);
void UART1_DefaultOverrunErrorHandler(void);
void UART1_DefaultErrorHandler(void);

void UART1_Initialize(void) {
    // Disable interrupts before changing states
    PIE3bits.U1RXIE = 0;
    UART1_SetRxInterruptHandler(UART1_Receive_ISR);
    PIE3bits.U1TXIE = 0;
    UART1_SetTxInterruptHandler(UART1_Transmit_ISR);

    // Set the UART1 module to the options selected in the user interface.

    // P1L 0; 
    U1P1L = 0x00;

    // P1H 0; 
    U1P1H = 0x00;

    // P2L 0; 
    U1P2L = 0x00;

    // P2H 0; 
    U1P2H = 0x00;

    // P3L 0; 
    U1P3L = 0x00;

    // P3H 0; 
    U1P3H = 0x00;

    // BRGS high speed; MODE Asynchronous 8-bit mode; RXEN enabled; TXEN enabled; ABDEN disabled; 
    U1CON0 = 0xB0;

    // RXBIMD Set RXBKIF on rising RX input; BRKOVR disabled; WUE disabled; SENDB disabled; ON enabled; 
    U1CON1 = 0x80;

    // TXPOL not inverted; FLO off; C0EN Checksum Mode 0; RXPOL not inverted; RUNOVF RX input shifter stops all activity; STP Transmit 1Stop bit, receiver verifies first Stop bit; 
    U1CON2 = 0x00;

    // BRGL 138; 
    U1BRGL = 0x8A;

    // BRGH 0; 
    U1BRGH = 0x00;

    // STPMD in middle of first Stop bit; TXWRE No error; 
    U1FIFO = 0x00;

    // ABDIF Auto-baud not enabled or not complete; WUIF WUE not enabled by software; ABDIE disabled; 
    U1UIR = 0x00;

    // ABDOVF Not overflowed; TXCIF 0; RXBKIF No Break detected; RXFOIF not overflowed; CERIF No Checksum error; 
    U1ERRIR = 0x00;

    // TXCIE disabled; FERIE disabled; TXMTIE disabled; ABDOVE disabled; CERIE disabled; RXFOIE disabled; PERIE disabled; RXBKIE disabled; 
    U1ERRIE = 0x00;


    UART1_SetFramingErrorHandler(UART1_DefaultFramingErrorHandler);
    UART1_SetOverrunErrorHandler(UART1_DefaultOverrunErrorHandler);
    UART1_SetErrorHandler(UART1_DefaultErrorHandler);

    uart1RxLastError.status = 0;

    // initializing the driver state
    uart1TxHead = 0;
    uart1TxTail = 0;
    uart1TxBufferRemaining = sizeof(uart1TxBuffer);
    uart1RxHead = 0;
    uart1RxTail = 0;
    uart1RxCount = 0;

    // enable receive interrupt
    PIE3bits.U1RXIE = 1;
}

bool UART1_is_rx_ready(void) {
    return (uart1RxCount ? true : false);
}

bool UART1_is_tx_ready(void) {
    return (uart1TxBufferRemaining ? true : false);
}

bool UART1_is_tx_done(void) {
    return U1ERRIRbits.TXMTIF;
}

uart1_status_t UART1_get_last_status(void) {
    return uart1RxLastError;
}

void UART1_Receive(void) {
    uint8_t regValue;
    uint8_t tempRxHead;
    // use this default receive interrupt handler code
    uart1RxStatusBuffer[uart1RxHead].status = 0;

    if (U1ERRIRbits.FERIF) {
        uart1RxStatusBuffer[uart1RxHead].ferr = 1;
        if (NULL != UART1_FramingErrorHandler) {
            UART1_FramingErrorHandler();
        }
    }
    if (U1ERRIRbits.RXFOIF) {
        uart1RxStatusBuffer[uart1RxHead].oerr = 1;
        if (NULL != UART1_OverrunErrorHandler) {
            UART1_OverrunErrorHandler();
        }
    }

    regValue = U1RXB;

    tempRxHead = (uart1RxHead + 1) & UART1_RX_BUFFER_MASK;
    if (tempRxHead == uart1RxTail) {
        // ERROR! Receive buffer overflow 
    } else {
        uart1RxBuffer[uart1RxHead] = regValue;
        uart1RxHead = tempRxHead;
        uart1RxCount++;
    }

    if (UART1_RxCompleteInterruptHandler != NULL) {
        (*UART1_RxCompleteInterruptHandler)();
    }

    // Función interrupción para recepción
    dato = UART1_Read();


    if ((dato > 0x2A && dato < 0x30) || (dato == 0x55) || (dato == 0x44) || (dato == 0x4E)) {

        leidos[0] = dato;
        // Reinicia el contador de posición del buffer
        leidos_ptr = 0;

    } else if (dato == 0x56) {
        leidos[0] = dato;
        leidos_ptr++;
    } else {

        if ((dato > 0x2F && dato < 0x3A))leidos[leidos_ptr++] = dato - 48;
        if ((dato > 0x40 && dato < 0x47))leidos[leidos_ptr++] = dato - 55;
        // Gurda el caracter recibido en el buffer

        if (leidos_ptr == 4) {
            cambioVelocidad = 1;
            leidos_ptr = 0;
        }
    }
}

uint8_t UART1_Read(void) {
    uint8_t readValue = 0;
    uint8_t tempRxTail;

    readValue = uart1RxBuffer[uart1RxTail];
    tempRxTail = (uart1RxTail + 1) & UART1_RX_BUFFER_MASK; // Buffer size of RX should be in the 2^n  
    uart1RxTail = tempRxTail;
    PIE3bits.U1RXIE = 0;
    if (uart1RxCount != 0) {
        uart1RxCount--;
    }
    PIE3bits.U1RXIE = 1;
    return readValue;
}

void UART1_Write(uint8_t txData) {
    while (0 == uart1TxBufferRemaining) {
    }

    if (0 == PIE3bits.U1TXIE) {
        U1TXB = txData;
    } else {
        PIE3bits.U1TXIE = 0;
        uart1TxBuffer[uart1TxHead++] = txData;
        if (sizeof (uart1TxBuffer) <= uart1TxHead) {
            uart1TxHead = 0;
        }
        uart1TxBufferRemaining--;
    }
    PIE3bits.U1TXIE = 1;
}

void UART1_Transmit_ISR(void) {
    // use this default transmit interrupt handler code
    if (sizeof (uart1TxBuffer) > uart1TxBufferRemaining) {
        U1TXB = uart1TxBuffer[uart1TxTail++];
        if (sizeof (uart1TxBuffer) <= uart1TxTail) {
            uart1TxTail = 0;
        }
        uart1TxBufferRemaining++;
    } else {
        PIE3bits.U1TXIE = 0;
    }

    // or set custom function using UART1_SetTxInterruptHandler()
}

void UART1_Receive_ISR(void) {
    // use this default receive interrupt handler code
    uart1RxStatusBuffer[uart1RxHead].status = 0;

    if (U1ERRIRbits.FERIF) {
        uart1RxStatusBuffer[uart1RxHead].ferr = 1;
        UART1_FramingErrorHandler();
    }

    if (U1ERRIRbits.RXFOIF) {
        uart1RxStatusBuffer[uart1RxHead].oerr = 1;
        UART1_OverrunErrorHandler();
    }

    if (uart1RxStatusBuffer[uart1RxHead].status) {
        UART1_ErrorHandler();
    } else {
        UART1_RxDataHandler();
    }

    // or set custom function using UART1_SetRxInterruptHandler()
}

void UART1_RxDataHandler(void) {
    // use this default receive interrupt handler code
    uart1RxBuffer[uart1RxHead++] = U1RXB;
    if (sizeof (uart1RxBuffer) <= uart1RxHead) {
        uart1RxHead = 0;
    }
    uart1RxCount++;
}

void UART1_DefaultFramingErrorHandler(void) {
}

void UART1_DefaultOverrunErrorHandler(void) {
}

void UART1_DefaultErrorHandler(void) {
    UART1_RxDataHandler();
}

void UART1_SetFramingErrorHandler(void (* interruptHandler)(void)) {
    UART1_FramingErrorHandler = interruptHandler;
}

void UART1_SetOverrunErrorHandler(void (* interruptHandler)(void)) {
    UART1_OverrunErrorHandler = interruptHandler;
}

void UART1_SetErrorHandler(void (* interruptHandler)(void)) {
    UART1_ErrorHandler = interruptHandler;
}

void UART1_SetRxInterruptHandler(void (* InterruptHandler)(void)) {
    UART1_RxInterruptHandler = InterruptHandler;
}

void UART1_SetTxInterruptHandler(void (* InterruptHandler)(void)) {
    UART1_TxInterruptHandler = InterruptHandler;
}


/**
  End of File
 */
