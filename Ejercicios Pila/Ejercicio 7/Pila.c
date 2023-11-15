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
void apilar(PILA S, char e){
    if(S -> tope == TAMPILA - 1){
        manejaMsg(1);
        exit(0);
    }
    S -> tope++;
    S -> cadena[S -> tope] = e;
}
int es_vacia(PILA S){
    return S -> tope < 0;
}
char desapilar(PILA S){
    char ch;
    if(es_vacia(S)){
        manejaMsg(2);
        exit(0);
    }
    ch = S -> cadena[S -> tope];
    S -> tope--;

    return ch;
}