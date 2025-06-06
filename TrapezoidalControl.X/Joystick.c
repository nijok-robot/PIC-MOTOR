#include "Joystick.h"
#include "ADCMax.h"
#include "DirCCW.h"
#include "DirCW.h"
#include "mcc_generated_files/mcc.h"
#include "UART.h"



uint16_t extern ValorADC; //Guarda el dato del ADC completo
int extern duty;
int extern dir; // 1 = CW 0=Stop -1=CCW
int extern prevdir;
uint8_t extern leidos[6];
int cont = 0;
bool acelerando = 0;
int dir_previo = 0;

int extern duty;

bool extern index;
uint16_t extern corriente[6];
int extern contConm;
bool extern timer6;
bool extern empezoTimer;
uint32_t extern sumatoriaCorriente;
//int estado;
//int estadoPrevio = 0;
bool extern acelerando;
uint16_t extern send_data[4];
uint16_t adc_meas;

void actualizarDir() {
    /*
     * Esta función actualiza la direccion dependiendo del valor de ADC que se recibe desde la ESP32
     * dir -> |1 = CW | 0=Stop | -1=CCW
     */
    prevdir = dir;
    if (leidos[0] == 0x2E)dir = 0;
    if (leidos[0] == 0x2D) dir = -1;
    if (leidos[0] == 0x2B) dir = 1;

}

void velocidadTransitorio() {
    int paso = (int) ((duty - 100)*0.2);
    if (INDEX_CHC_RB0_GetValue() == 1)
        cont++;
    if (cont > 5) {
        PWM6_LoadDutyValue(duty);
        cont = 0;
        acelerando = 0;
    } else {
        PWM6_LoadDutyValue(100 + (paso * cont));
    }
}

void actualizarEstadoMotor() {

    actualizarDir();
    if (dir == 1) {
        if (dir_previo != 1) {
            if (dir_previo != 0) {
                STOP();
                __delay_ms(10);
            }
            dir_previo = 1;
            PWM6_LoadDutyValue(100);
            startUpForwardMode();
            acelerando = 1;
        }
        if (acelerando)velocidadTransitorio();
        forwardMode();
    }
    if (dir == -1) {
        if (dir_previo != -1) {
            if (dir_previo != 0) {
                STOP();
                __delay_ms(10);
            }
            dir_previo = -1;
            PWM6_LoadDutyValue(100);
            startUpReverseMode();
            acelerando = 1;
        }
        if (acelerando)velocidadTransitorio();
        reverseMode();
    }
    if (dir == 0) {
        dir_previo = 0;
        STOP();
        acelerando = 0;
    }
}

void current(int current) {
    /*
     * 1. Revisar si el motor ya volvio a la posicion 0
     * 2. Iniciar el timer para contar el 80% del tiempo
     * 3. Revisar si ya paso este tiempo
     * 4. Si ya paso el 80% del tiempo, revisar que corriente se debe
     *    muestrear y guardarla en el arreglo corriente
     * 5. Se suma uno al contador de 
     *    las conmutaciones
     */
    if (index && !acelerando) {

        if (!empezoTimer) {
            PIE9bits.TMR6IE = 1; //Habilito interrupcion del timer
            TMR6 = 0; // Reiniciar el Timer 6 antes de iniciarlo
            PIR9bits.TMR6IF = 0; // Limpiar la bandera de interrupción
            T6CONbits.TMR6ON = 1; // Encender el Timer 6
            empezoTimer = 1;

        }
        if (timer6) {
            timer6 = 0;

            contConm++;
            // select the A/D channel
            if (contConm>-1 && contConm < 6) {
                if (current == 1) ADPCH = channel_ANA7;
                if (current == 2) ADPCH = channel_ANA6;
                if (current == 3) ADPCH = channel_ANC0;

                // Turn on the ADC module
                ADCON0bits.ADON = 1;

                // Start the conversion
                ADCON0bits.ADGO = 1;
                while (ADCON0bits.ADGO); // Espera a que termine la conversión

                corriente[contConm] = (uint16_t) ((ADRESH << 8) + ADRESL);

            }

        }
    }


}

void Temp() {
    FVRCONbits.FVREN = 1; // Habilita FVR
    FVRCONbits.ADFVR = 0b10; // Selecciona FVR2 (2x = ~2.048V)

    ADREFbits.ADPREF = 0b11; // Referencia positiva = FVR
    ADREFbits.ADNREF = 0b00; // Negativa = VSS

    FVRCONbits.TSRNG = 1; // Rango alto
    FVRCONbits.TSEN = 1; // Activar sensor de temperatura

    ADPCH = 0x3C; // Canal del sensor de temperatura
    //__delay_us(25); // Espera mínima de adquisición

    ADCON0bits.ADON = 1;
    ADCON0bits.ADGO = 1;
    while (ADCON0bits.ADGO);

    adc_meas = (uint16_t) ((ADRESH << 8) | ADRESL);
    ADREFbits.ADPREF = 0b00; // VDD como referencia positiva

}