#include <stdlib.h>
#include "pila.h"

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
void apilar(PILA S, int e){
    if(S -> tope == TAMPILA -1){
        manejaMsg(1);
        exit(0);
    }
    S -> tope++;
    S -> pila[S -> tope] = e;
}
int desapilar(PILA S){
    int v;
    if(es_vaciaPila(S)){
        manejaMsg(2);
        exit(0);
    }
    v = S -> pila[S -> tope];
    S -> tope--;
    return v;
}
int es_vaciaPila(PILA S){
    return S -> tope < 0;
}
int elemTope(PILA S){
    int v;
    if(es_vaciaPila(S)){
        manejaMsg(2);
        exit(0);
    }
    v = desapilar(S);
    apilar(S, v);
    return v;
}