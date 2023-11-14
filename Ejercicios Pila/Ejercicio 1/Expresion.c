#include <stdlib.h>
#include <stdio.h>
#include "expresion.h"

void manejaMsg(int);

PILA crearPila(){
    PILA S;

    S = (PILA) malloc(sizeof(Pila));

    if(S == NULL){
        manejaMsg(0);
        exit(0);
    }

    S -> tope = -1;
    return S;
}
void apilar(PILA S, char e){
    if(S -> tope == TAMPILA - 1){
        manejaMsg(1);
        exit(0);
    }
    S -> tope++;
    S -> pila[S -> tope] = e;
}
int es_vacia(PILA S){
    return S -> tope < 0;
}
char desapilar(PILA S){
    char v;
    if(es_vacia(S)){
        manejaMsg(2);
        exit(0);
    }
    v = S -> pila[S -> tope];
    S -> tope--;
    return v;
}
char cima(PILA S){
    return S -> pila[S -> tope];
}
