/* 
 * File:   ADCMax.h
 * Author: aulasingenieria
 *
 * Created on December 5, 2024, 4:50 PM
 */

#ifndef ADCMAX_H
#define	ADCMAX_H
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#ifdef	__cplusplus
extern "C" {
#endif
    /*
       To initialize in a proper way the SPI protocol (pic as master) it is important
     * to decide de clock off the SCK, the modo and the smp.
     * First configure the clock SCK signal. For this we have to configure Baude and 
     * which clock. 
     */
#define relojSCK_HFINTOSC   0 //Para elejir que el reloj sea el HFINTOSC
#define BAUDERATESCK        7// esta es la fecuencia que tendra la señal SCK 
    /*
     Para BAUDERATESCK la formula de freceuncia es
     * frecuenciaSPI = CLOKseleccionado/(2*BAUDERATE+1)
     * frecuenciaSPI = 64MHZ/(2*(4+1)) = 6.4Mhz y como es menor a 8Mhz es pocible para el adc max16666
     * 
     */


    /*
     Ahora para el registro  SPIxCON1 el regrsitro SPM al estar en 
     * 1 = El dato de entrada SDI se muestrea al final del tiempo de salida de datos.
     * 0 = El dato de entrada SDI se muestrea en el medio del tiempo de salida de datos.
     */
#define SPM_middle      0
#define SPM_NOmiddle    1

    /*
     Ahora los modos (Hay 4)
     */
#define MODO_0  '0'
#define MODO_1  '1'
#define MODO_2  '2'
#define MODO_3  '3' 

    void Alternar_channel_ADC(); //alterna canal adc
    //void SPI_ADCext_completeValue();//:e entrega el valor del adc muestreado en ese momento
    void SPI1_Open_config_adcMAX1666();
    void SPI_ADCext_completeValue();
    void SPI_init1(char RelojSCK, char BaudeRSCK, char SPMRegistro, char modo, int enableInterrupt);
#ifdef	__cplusplus
}
#endif

#endif	/* ADCMAX_H */

