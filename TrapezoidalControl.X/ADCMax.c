#include "ADCMax.h"
#include "mcc_generated_files/mcc.h"

uint8_t highByte = 0, lowByte = 0; //Almacena lo que llega del ADC 
uint16_t highByte_16 = 0, lowByte_16 = 0; //Almacena lo que llega del ADC en uint16
uint16_t extern ValorADC; //Guarda el dato del ADC completo
uint16_t extern preValorADC; //Valor de ADC previo para ver si cambia
bool extern cambioValorADC; // Bandera que indica que hubo cambio en el valor ADC
bool extern canal_eleccion; // Bandera que indica que hubo cambio en el valor ADC
void SPI_ADCext_completeValue() {

    SPI1_Close(); //Aseguro de que el puerto este apagado
    Alternar_channel_ADC(); //Alterna el canal cambia ADC_chan
    ADC_CS_SetHigh(); //Inicio de conversion ADC
    ADC_CS_SetLow(); //Inicio de conversion ADC
    SPI1_Open_config_adcMAX1666(); //Configur el puerto y abro el puerto SPI
    PIE2bits.SPI1RXIE = 1; //habilito bandera
    SPI1TCNTL = 0x02;

    while (!SPI1STATUSbits.RXBF);
    SPI1STATUSbits.RXBF = 0;
    //PIR2bits.SPI1RXIF = 0;
    highByte = SPI1RXB;
    lowByte = SPI1RXB;

    /*
        while (!PIR2bits.SPI1RXIF);
        PIR2bits.SPI1RXIF = 0;
        highByte = SPI1RXB;
        while (!PIR2bits.SPI1RXIF);
        PIR2bits.SPI1RXIF = 0;
        lowByte = SPI1RXB;
     */

    LATEbits.LATE1 = 1; // Desactivar ADC_CS seleccionando con CS alto
    SPI1_Close(); //Aseguro de que el puerto este apagado
    highByte_16 = (uint16_t) highByte;
    lowByte_16 = (uint16_t) lowByte;
    //ValorADC = (((highByte_16 & 0b0000000000111111) << 6) | ((lowByte_16 & 0b0000000011111100) >> 2));
    ValorADC = ((highByte  << 7)| lowByte) >> 2;
    if(ValorADC != preValorADC) {
        preValorADC = ValorADC;
        cambioValorADC = 1; 
    }

}

void Alternar_channel_ADC() {
    if (canal_eleccion == false) {
        ADC_chan_SetLow();
    } else {
        ADC_chan_SetHigh();
    }
}

void SPI1_Open_config_adcMAX1666() {
    if (!SPI1CON0bits.EN) {
        SPI1CON0 = 0x02; //solo especifica que la pic es master
        //SPI1CON1 = 0x40; //modo 3, middle smp, ssp,sdip y sdop active - high SKE 1 SKP = 0
        //SPI1CON1bits.CKE = 0;
        //SPI1CON1bits.CKP = 1;
        SPI1CON1bits.CKE = 0;
        SPI1CON1bits.CKP = 1;
        SPI1CON0bits.SPI1BMODE = 0;
        //SPI1CON2 = 0x00; //ONLY READ
        SPI1BAUD = 0x07; //4MHZ

        SPI1CON2bits.TXR = 0; //Transmit Data-Required Bit;
        SPI1CON2bits.RXR = 1; // Receive FIFO Space-Required Bit;
        // SPI1TCNT = 1; // Load SPI Transfer Counter;

        // Configurar los pines de salida
        TRISCbits.TRISC3 = 0; // SCK1 (Pin SCK como salida)
        TRISCbits.TRISC4 = 1; // SDI1 (Pin SDI como entrada)
        TRISCbits.TRISC5 = 0; // SDO1 (Pin SDO como salida)
        //Habilita el puerto SPI
        SPI1CON0bits.EN = 1;

    }
}

void SPI_init1(char RelojSCK, char BaudeRSCK, char SPMRegistro, char modo, int enableInterrupt) {
    SPI1CON0bits.EN = 0; // Deshabilitar el módulo SPI
    SPI1CON0bits.SPI1BMODE = 0;
    SPI1CLK = RelojSCK; // Seleccionar HFINTOSC como fuente de reloj
    SPI1BAUD = BaudeRSCK; //Divide el clock HFINTOSC hasta obtener 6.4mhz


    SPI1CON0bits.MST = 1; // Configurar como modo Master
    SPI1CON0bits.LSBF = 0; // transmite el bit mas significativo primero
    //SPI1CON2 = 0x00;

    // Configurar los pines de salida
    TRISCbits.TRISC3 = 0; // SCK1 (Pin SCK como salida)
    TRISCbits.TRISC4 = 1; // SDI1 (Pin SDI como entrada)
    TRISCbits.TRISC5 = 0; // SDO1 (Pin SDO como salida)

    SPI1CON1bits.SMP = SPMRegistro; // Muestra los datos en la mitad del tiempo de salida
    if (modo == '0') {
        SPI1CON1bits.CKE = 1;
        SPI1CON1bits.CKP = 1;
    } else if (modo == '1') {
        SPI1CON1bits.CKE = 0;
        SPI1CON1bits.CKP = 1;
    } else if (modo == '2') {
        SPI1CON1bits.CKE = 1;
        SPI1CON1bits.CKP = 0;
    } else if (modo == '3') {
        SPI1CON1bits.CKE = 0;
        SPI1CON1bits.CKP = 0;
    }
    if (enableInterrupt == 1) {
        PIR2bits.SPI1RXIF = 0; // Limpia la bandera de interrupción de recepción SPI
        PIE2bits.SPI1RXIE = 1; // Habilita la interrupción de recepción SPI
    } else {
        PIR2bits.SPI1RXIF = 0; // Limpia la bandera de interrupción de recepción SPI
        PIE2bits.SPI1RXIE = 0; // DesHabilita la interrupción de recepción SPI
    }
    //SPI1CON0bits.EN = 1; // Habilitar el módulo SPI
}
