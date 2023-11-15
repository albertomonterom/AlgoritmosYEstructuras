#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

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
void apilar(PILA S, char * producto){
    if(S -> tope == TAMPILA - 1){
        manejaMsg(1);
    }else{
        S -> tope++;
        S -> productos[S -> tope] = producto;
        printf("\n%s ha sido agregado a la cesta\n", producto);
    }
}
int es_vacia(PILA S){
    return S -> tope < 0;
}
char * desapilar(PILA S){
    char * p;
    if(es_vacia(S)){
        manejaMsg(2);
    }else{
        p = S -> productos[S -> tope];
        S -> tope--;
        return p;
    }
}