/* 
 * File:   Joystick.h
 * Author: aulasingenieria
 *
 * Created on December 6, 2024, 3:21 PM
 */

#ifndef JOYSTICK_H
#define	JOYSTICK_H
/*Señal SKYDROID
 * Frecuencia 50Hz - 49.97Hz
 * Porcentaje PWM Joystick Y1 Arriba 10% = 320mV
 * Porcentaje PWM Joystick Y1 Abajo 5% = 165mV
 *
 */
#define umbralCentral 27 //(ValoresADC/(RangoSeñalSkydroid)=(4096/(320mV-165mV)
#define limiteInferior (1024 - umbralCentral)
#define limiteSuperior (1024 + umbralCentral)

//VALORES EXTRAIDOS DEL DIA PARA EL CALCULO DE TEMPERATURA
#define ADCDIA     2489     // leído de TSHR2 (por ejemplo)
#define FVR2AX_mV  2038     // leído de 0x3F0032
#define MV_mV_C   -3.684    // tomado de tabla 44-26
#define ADC_RESOLUTION 4095  // para 10 bits (2^12 - 1)

void actualizarDir();
void actualizarEstadoMotor();
void velocidadTransitorio();
void current(int current);
void Temp();


#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* JOYSTICK_H */

