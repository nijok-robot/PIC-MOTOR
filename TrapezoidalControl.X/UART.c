#include "UART.h"
#include "mcc_generated_files/mcc.h"
char extern digitos[28];
char extern leidos[6]; //OJO DEBE SER TAMANO 4
volatile extern char* digito_ptr;
volatile extern int leidos_ptr;
char conversion[16] = {0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46};
uint16_t extern corriente[8];
int extern i;
int i2 = 0;
uint32_t extern sumatoriaCorriente;
uint16_t promedio;
bool extern ascii;
uint16_t extern send_data[3];

void ConvertADC12BitToHexASCII_A() {
    // Separar los nibbles de los bits relevantes de ADRESH y ADRESL
    ADPCH = channel_ANA7;
    PIE1bits.ADIE = 0;
    digitos[2] = conversion[ADRESL & 0x0F]; // Sólo los 4 bits menos significativos de ADRESH son relevantes
    digitos[1] = conversion[(ADRESL >> 4) & 0x0F]; // Nibble alto de ADRESL
    digitos[0] = conversion[ADRESH & 0x0F];
    PIE3bits.U1TXIE = 1; // Habilitar interrupción de transmisión
}

void ConvertADC12BitToHexASCII_B() {
    // Separar los nibbles de los bits relevantes de ADRESH y ADRESL
    ADPCH = channel_ANA6;
    PIE1bits.ADIE = 0;
    digitos[6] = conversion[ADRESL & 0x0F]; // Sólo los 4 bits menos significativos de ADRESH son relevantes
    digitos[5] = conversion[(ADRESL >> 4) & 0x0F]; // Nibble alto de ADRESL
    digitos[4] = conversion[ADRESH & 0x0F];
    PIE3bits.U1TXIE = 1; // Habilitar interrupción de transmisión
}

void ConvertADC12BitToHexASCII_C() {
    // Separar los nibbles de los bits relevantes de ADRESH y ADRESL
    ADPCH = channel_ANC0;
    PIE1bits.ADIE = 0;
    digitos[10] = conversion[ADRESL & 0x0F]; // Sólo los 4 bits menos significativos de ADRESH son relevantes
    digitos[9] = conversion[(ADRESL >> 4) & 0x0F]; // Nibble alto de ADRESL
    digitos[8] = conversion[ADRESH & 0x0F];
    digito_ptr = digitos; // Inicializar el puntero al inicio del arreglo
    PIE3bits.U1TXIE = 1; // Habilitar interrupción de transmisión
}

void RutinaTransmicionUSART_ASCII(void) {
    //led_1_SetHigh();
    if (*digito_ptr != 0x0A) { // Transmite hasta llegar al terminador
        //PIE3bits.U1TXIE = 1;
        U1TXB = *digito_ptr; // Enviar el dígito actual U1TXB Registro que carga el dato que se va a enviar
        digito_ptr++; // Avanzar el puntero al siguiente dígito
        //PIE3bits.U1TXIE = 0;
    } else {
        U1TXB = *digito_ptr; // Enviar el terminador
        CHA_RC6_SetLow();
        PIE3bits.U1TXIE = 0; // Deshabilitar la interrupción cuando se haya transmitido el último byte        
        digito_ptr = digitos; //regresar puntero al origen
    }
}

void convertirASCII(void) {

        digitos[0 + i] = conversion[(send_data[i2] >> 8) & 0x000F]; //Centenas
        digitos[1 + i] = conversion[(send_data[i2] >> 4) & 0x000F]; // Nibble alto de ADRESL Decenas
        digitos[2 + i] = conversion[send_data[i2] & 0x000F]; // Sólo los 4 bits menos significativos de ADRESH son relevantes Unidades
        i+=4;
        i2++;
        if (i ==16) {
            i2 = 0;
            i = 0;
            ascii = 0;
            digito_ptr = digitos;
            CHA_RC6_SetHigh();
            PIE3bits.U1TXIE = 1;
        }
}