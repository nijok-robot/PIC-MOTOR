/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F47K42
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include "DirCCW.h"
#include "DirCW.h"
#include "ADCMax.h"
#include "UART.h"
#include "Joystick.h"

int dir = -1; // 1= CW 0=Stop -1=CCW
int prevdir = 0; // 1= CW 0=Stop -1=CCW
int porcent = 10;
int duty;
int cont;

//---------------------------
uint16_t ValorADC; //Guarda el dato del ADC completo
uint16_t preValorADC = 0; //Valor de ADC previo para ver si cambia
bool cambioValorADC = 0; // Bandera que indica que hubo cambio en el valor ADC
bool canal_eleccion = 0;

char digitos[28]; //array transmission
volatile char* digito_ptr; // Puntero al dígito actual que se va a transmitir

bool prevHallA;
bool prevHallB;
bool prevHallC;

/*Variables lectura y transmision de corrientes*/
bool index = 0;
int contConm = -1;
uint16_t corriente[8];
uint16_t send_data[4];
uint16_t promedio;
bool timer6 = 0;
bool calcPromedio = 0;
bool empezoTimer = 0;
bool ascii = 0;
int i = 0;
uint32_t sumatoriaCorriente = 0;
bool enviado = 1;

/*Variables lectura de comandos recibidos por UART*/
uint8_t leidos[4];
volatile int leidos_ptr;

uint16_t velocidad;
bool cambioVelocidad = 0;
bool extern acelerando;

uint8_t tiempoC_80;
volatile uint32_t pulse_count = 0;
volatile uint16_t rps = 0; // Stores calculated RPM
volatile uint8_t measuring = 0; // 1 = Measuring time, 0 = Ready for new measurement

bool RC6_Previo = 0;

//Pruebas corriete
//borrar
int prueba_current = 0;
int conteo_preuba = 0;

//Nuevas variables para calcular w y I solo en estado estable
uint16_t rps_anterior = 0;
uint8_t contador_estabilidad = 0;
const uint8_t umbral_estabilidad = 5;
int validacion_c = 0;
uint16_t extern adc_meas;

/*
                         Main application
 */
void main(void) {
    // Initialize the device
    SYSTEM_Initialize();
    nSLEEP_RA4_SetHigh();
    DRIVOFF_RA5_SetLow();
    cont = 0; //CONTEO PARA EL ESTADO TRANSITORIO
    digito_ptr = digitos;
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:



    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    prevHallA = 0;
    prevHallB = 0;
    prevHallC = 0;

    duty = 310; //(valor_recibido*599/255)--> Velocidad  en realidad nos da 3600rpm

    //PWM6_LoadDutyValue(duty);

    //Colocar comas y final de linea a cadena envada por uart
    digitos[3] = 0x2C; //0x2F
    digitos[7] = 0x2C; //Caracter coma
    digitos[11] = 0x2C;
    digitos[15] = 0x0A;
    digitos[19] = 0x2C;
    digitos[23] = 0x2C;
    digitos[27] = 0x0A; //Final de linea

    leidos[0] = 0x2E; //Caracter punto final
    actualizarDir();
    cambioValorADC = 0;
    leidos_ptr = 0;
    PIE3bits.U1TXIE = 0; // Iniciar la interrupción de UART deshabilitada
    PIE4bits.TMR1IE = 0; //Inicio cuenta 1 segundo deshabiltada
    PIE9bits.TMR6IE = 0; //inico conteo corriente desahbilitada
    PIE0bits.IOCIE = 1; //Habilito interrupcion de index
    // PIE8bits.TMR5IE = 0;

    //enviado = 1;

    empezoTimer = 0; //¿inicio timer 6?
    calcPromedio = 0;
    FVRCONbits.TSEN = 1; // Activar el sensor de temperatura
    FVRCONbits.TSRNG = 1; // Rango alto (recomendado para VDD ? 2.5 V)



    while (1) {
        

        //************Prioridad para escuchar como esclavo a su ESP master******************
        if (leidos[0] == 0x56 && cambioVelocidad) {//0x56 es el carater v
            //Funcion encargada de cambiar cambiar DUTY segun la velocidad
            //PIE9bits.TMR6IE = 0; //deshabilito timer para cacular 80%
            velocidad = (leidos[1] << 8) +(leidos[2] << 4) + leidos[3];
            duty = (int) (velocidad); //obtengo nuevo duty
            PWM6_LoadDutyValue(duty);
            ascii = 0;
            cambioVelocidad = 0; //bandera que verifica si se recibido un caracter V tras 3 char mas
            //leidos[0] = 0x4E;
        }


        //************Prioridad para escuchar como esclavo a su ESP master******************


        if (ascii) convertirASCII(); //Función ir enviando por uart

        if (calcPromedio) {//135us
            //Calculo corriente de consumo del motor
            //CHB_RD3_SetHigh();//cada revolucion se toma una corriente 
            calcPromedio = 0;
            sumatoriaCorriente = 0;
            sumatoriaCorriente += (uint32_t) (corriente[0]);
            sumatoriaCorriente += (uint32_t) (corriente[1]);
            sumatoriaCorriente += (uint32_t) (corriente[2]);
            sumatoriaCorriente += (uint32_t) (corriente[3]);
            sumatoriaCorriente += (uint32_t) (corriente[4]);
            sumatoriaCorriente += (uint32_t) (corriente[5]);
            promedio = (uint16_t) ((int) (sumatoriaCorriente * 0.166666666667));
            corriente[6] = promedio;
            send_data[1] = promedio;
            
            i = 0;
            //ascii = 1;//Bandera para saber que la medicion de corriente es la apropiada 
        }
//        if(leidos[0] == 0x2E)
//        {
//            send_data[0] = 0;//w
//            send_data[1] = 0;//I
//            Temp();
//            send_data[2] = adc_meas;
//            send_data[3] = duty;
//            ascii = 1;
//            
//        }
        
    }
}
/**
 End of File
 */

