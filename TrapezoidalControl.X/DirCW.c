#include "states.h"
#include "DirCW.h"
#include "Joystick.h"
#include "mcc_generated_files/mcc.h"
int extern duty;

bool extern index;
uint16_t extern corriente[6];
int extern contConm;
bool extern timer6;
bool extern empezoTimer;
uint32_t extern sumatoriaCorriente;
int estado;
int estadoPrevio = 0;
bool extern acelerando;

void startUpForwardMode() {// Esta funcion inicializa el motor para que gire CW
    if (HallA_RD6_GetValue() == 0 &&
            HallB_RD5_GetValue() == 0 &&
            HallC_RD4_GetValue() == 1) {

        //HS_U
        CWG1STRbits.OVRB = 0;
        CWG1STRbits.STRB = 0;

        //LS_U
        CWG1STRbits.OVRA = 0;
        CWG1STRbits.STRA = 0;

        //HS_V
        CWG2STRbits.STRB = 1;

        //LS_V
        CWG2STRbits.OVRA = 0;
        CWG2STRbits.STRA = 0;

        //HS_W
        CWG3STRbits.OVRA = 0;
        CWG3STRbits.STRA = 0;

        //LS_W
        CWG3STRbits.OVRB = 1;
        CWG3STRbits.STRB = 0;

    }

    if (HallA_RD6_GetValue() == 0 &&
            HallB_RD5_GetValue() == 1 &&
            HallC_RD4_GetValue() == 1) {

        //HS_U
        CWG1STRbits.STRB = 1;

        //LS_U
        CWG1STRbits.OVRA = 0;
        CWG1STRbits.STRA = 0;

        //HS_V
        CWG2STRbits.OVRB = 0;
        CWG2STRbits.STRB = 0;

        //LS_V
        CWG2STRbits.OVRA = 0;
        CWG2STRbits.STRA = 0;

        //HS_W
        CWG3STRbits.OVRA = 0;
        CWG3STRbits.STRA = 0;

        //LS_W
        CWG3STRbits.OVRB = 1;
        CWG3STRbits.STRB = 0;

    }

    if (HallA_RD6_GetValue() == 0 &&
            HallB_RD5_GetValue() == 1 &&
            HallC_RD4_GetValue() == 0) {
        //HS_U
        CWG1STRbits.STRB = 1;

        //LS_U
        CWG1STRbits.OVRA = 0;
        CWG1STRbits.STRA = 0;

        //HS_V
        CWG2STRbits.OVRB = 0;
        CWG2STRbits.STRB = 0;

        //LS_V
        CWG2STRbits.OVRA = 1;
        CWG2STRbits.STRA = 0;

        //HS_W
        CWG3STRbits.OVRA = 0;
        CWG3STRbits.STRA = 0;

        //LS_W
        CWG3STRbits.OVRB = 0;
        CWG3STRbits.STRB = 0;

    }

    if (HallA_RD6_GetValue() == 01 &&
            HallB_RD5_GetValue() == 1 &&
            HallC_RD4_GetValue() == 0) {
        //HS_U
        CWG1STRbits.OVRB = 0;
        CWG1STRbits.STRB = 0;

        //LS_U
        CWG1STRbits.OVRA = 0;
        CWG1STRbits.STRA = 0;

        //HS_V
        CWG2STRbits.OVRB = 0;
        CWG2STRbits.STRB = 0;

        //LS_V
        CWG2STRbits.OVRA = 1;
        CWG2STRbits.STRA = 0;

        //HS_W
        CWG3STRbits.STRA = 1;

        //LS_W
        CWG3STRbits.OVRB = 0;
        CWG3STRbits.STRB = 0;

    }
    if (HallA_RD6_GetValue() == 1 &&
            HallB_RD5_GetValue() == 0 &&
            HallC_RD4_GetValue() == 0) {
        //HS_U
        CWG1STRbits.OVRB = 0;
        CWG1STRbits.STRB = 0;

        //LS_U
        CWG1STRbits.OVRA = 1;
        CWG1STRbits.STRA = 0;

        //HS_V
        CWG2STRbits.OVRB = 0;
        CWG2STRbits.STRB = 0;

        //LS_V
        CWG2STRbits.OVRA = 0;
        CWG2STRbits.STRA = 0;

        //HS_W
        CWG3STRbits.STRA = 1;

        //LS_W
        CWG3STRbits.OVRB = 0;
        CWG3STRbits.STRB = 0;

    }
    if (HallA_RD6_GetValue() == 1 &&
            HallB_RD5_GetValue() == 0 &&
            HallC_RD4_GetValue() == 1) {
        //HS_U
        CWG1STRbits.OVRB = 0;
        CWG1STRbits.STRB = 0;

        //LS_U
        CWG1STRbits.OVRA = 1;
        CWG1STRbits.STRA = 0;

        //HS_V
        CWG2STRbits.STRB = 1;

        //LS_V
        CWG2STRbits.OVRA = 0;
        CWG2STRbits.STRA = 0;

        //HS_W
        CWG3STRbits.OVRA = 0;
        CWG3STRbits.STRA = 0;

        //LS_W
        CWG3STRbits.OVRB = 0;
        CWG3STRbits.STRB = 0;

    }


}

void state1F() {//CCW 1 U|V|W 110
    CWG1STRbits.OVRB = 0;
    CWG1STRbits.STRB = 0;

    CWG2STRbits.STRB = 1;
}

void state2F() {
    CWG2STRbits.OVRA = 0;
    CWG2STRbits.STRA = 0;

    CWG3STRbits.OVRB = 1;
    CWG3STRbits.STRB = 0;
}

void state3F() {
    CWG3STRbits.OVRA = 0;
    CWG3STRbits.STRA = 0;

    CWG1STRbits.STRB = 1;
}

void state4F() {
    CWG1STRbits.OVRA = 0;
    CWG1STRbits.STRA = 0;

    CWG2STRbits.OVRA = 1;
    CWG2STRbits.STRA = 0;
}

void state5F() {
    CWG2STRbits.OVRB = 0;
    CWG2STRbits.STRB = 0;

    CWG3STRbits.STRA = 1;
}

void state6F() {
    CWG3STRbits.OVRB = 0;
    CWG3STRbits.STRB = 0;

    CWG1STRbits.OVRA = 1;
    CWG1STRbits.STRA = 0;
}

void forwardMode() {

    if (HallA_RD6_GetValue() == 0 &&
            HallB_RD5_GetValue() == 0 &&
            HallC_RD4_GetValue() == 1) {
        estado = 1;
        if (estado != estadoPrevio) {
            state1F();
            estadoPrevio = estado;
            empezoTimer = 0;
        }
        current(1);
    }


    if (HallA_RD6_GetValue() == 0 &&
            HallB_RD5_GetValue() == 1 &&
            HallC_RD4_GetValue() == 1) {
        estado = 2;
        if (estado != estadoPrevio) {
            state2F();
            estadoPrevio = estado;
            empezoTimer = 0;
        }
        current(1);
    }

    if (HallA_RD6_GetValue() == 0 &&
            HallB_RD5_GetValue() == 1 &&
            HallC_RD4_GetValue() == 0) {
        estado = 3;
        if (estado != estadoPrevio) {
            state3F();
            estadoPrevio = estado;
            empezoTimer = 0;
        }
        current(2);
    }

    if (HallA_RD6_GetValue() == 1 &&
            HallB_RD5_GetValue() == 1 &&
            HallC_RD4_GetValue() == 0) {
        estado = 4;
        if (estado != estadoPrevio) {
            state4F();
            estadoPrevio = estado;
            empezoTimer = 0;
        }
        current(2);
    }

    if (HallA_RD6_GetValue() == 1 &&
            HallB_RD5_GetValue() == 0 &&
            HallC_RD4_GetValue() == 0) {
        estado = 5;
        if (estado != estadoPrevio) {
            state5F();
            estadoPrevio = estado;
            empezoTimer = 0;
        }
        current(3);
    }

    if (HallA_RD6_GetValue() == 1 &&
            HallB_RD5_GetValue() == 0 &&
            HallC_RD4_GetValue() == 1) {
        estado = 6;
        if (estado != estadoPrevio) {
            state6F();
            estadoPrevio = estado;
            empezoTimer = 0;
        }
        current(3);
    }
}