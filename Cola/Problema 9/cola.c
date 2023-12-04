#include <stdlib.h>
#include "cola.h"

void manejaMsg(int);

COLA crearCola(){
    COLA C;
    C = (COLA) malloc(sizeof(Cola));
    if(C == NULL){
        manejaMsg(0);
        exit(0);
    }
    C -> primero = 0;
    C -> ultimo = 0;
    C -> tam = 0;
    return C;
}
int es_vaciaCola(COLA C){
    if(C -> tam == 0){
        return TRUE;
    }else{
        return FALSE;
    }
}
int sig(int i){
    int p;
    p = (i + 1) % TAMCOLA;
    return p;
}
void encolar(COLA C, CLIENTE cliente){
    if(C -> tam == TAMCOLA){
        manejaMsg(3);
        exit(0);
    }
    C -> cola[C -> ultimo] = cliente;
    C -> ultimo = sig(C -> ultimo);
    C -> tam = C -> tam + 1;
}
CLIENTE desencolar(COLA C){
    CLIENTE v;
    if(es_vaciaCola(C) == TRUE){
        manejaMsg(4);
        exit(0);
    }
    v = C -> cola[C -> primero];
    C -> primero = sig(C -> primero);
    C -> tam = C -> tam - 1;
    return v;
}
CLIENTE primero(COLA C){
    CLIENTE v;
    if(es_vaciaCola(C) == TRUE){
        manejaMsg(4);
        exit(0);
    }
    v = C -> cola[C -> primero];
    return v;
}