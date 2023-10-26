#include<stdlib.h>
#include "conjunto.h"

void manejaMsg(int);
void liberarMemoria(CONJUNTO);

CONJUNTO conjuntoVacio(int tamanio){
    int i;
    CONJUNTO conjunto;

    conjunto = (CONJUNTO) malloc(sizeof(Conjunto));
    
    if(conjunto == NULL){
        manejaMsg(0);
        exit(0);
    }

    conjunto -> tamanio = tamanio;
    conjunto -> elementos = (int *) malloc(sizeof(int) * tamanio);
    for(i = 0; i < tamanio; i++){
        conjunto -> elementos[i] = 0; 
    }

    return conjunto;
}
void anadir(CONJUNTO conjunto, int elemento){
    int i;
    if(!pertenece(conjunto, elemento)){
        for(i = 0; i < conjunto -> tamanio; i++){
            if((conjunto -> elementos[i]) == 0){
                (conjunto -> elementos[i]) = elemento;
                return;
            }
        }
    }
}
void retirar(CONJUNTO conjunto, int elemento){
    int i;
    for(i = 0; i < conjunto -> tamanio; i++){
        if((conjunto -> elementos[i]) == elemento){
            (conjunto -> elementos[i]) = 0;
            return;
        }
    }
}
int pertenece(CONJUNTO conjunto, int elemento){
    int i;
    for(i = 0; i < conjunto -> tamanio; i++){
        if((conjunto -> elementos[i]) == elemento){
            return 1;
        }
    }
    return 0;
}
int esVacio(CONJUNTO conjunto){
    int i;
    for(i = 0; i < conjunto -> tamanio; i++){
        if((conjunto -> elementos[i]) != 0){
            return 0;
        }
    }
    return 1;
}
int cardinal(CONJUNTO conjunto){
    int i, contador = 0;
    for(i = 0; i < conjunto -> tamanio; i++){
        if((conjunto -> elementos[i]) != 0){
            contador++;
        }
    }
    return contador;
}
CONJUNTO unionConjuntos(CONJUNTO conjuntoA, CONJUNTO conjuntoB){
    int max = (conjuntoA -> tamanio) + (conjuntoB -> tamanio);
    CONJUNTO resultado = conjuntoVacio(max);

    int i;
    for(i = 0; i < conjuntoA -> tamanio; i++){
        if((conjuntoA -> elementos[i]) != 0){
            anadir(resultado, conjuntoA -> elementos[i]);
        }
    }

    for(i = 0; i < conjuntoB -> tamanio; i++){
        if((conjuntoB -> elementos[i]) != 0){
            anadir(resultado, conjuntoB -> elementos[i]);
        }
    }
    return resultado;
}
CONJUNTO interseccion(CONJUNTO conjuntoA, CONJUNTO conjuntoB){
    int max = (conjuntoA -> tamanio) < (conjuntoB -> tamanio) ? conjuntoA -> tamanio : conjuntoB -> tamanio;
    CONJUNTO resultado = conjuntoVacio(max);
    int i;

    for(i = 0; i < conjuntoA -> tamanio; i++){
        if((conjuntoA -> elementos[i] != 0) && (pertenece(conjuntoB, conjuntoA -> elementos[i]))){
            anadir(resultado, conjuntoA -> elementos[i]);
        }
    }
    return resultado;
}
int inclusion(CONJUNTO conjuntoA, CONJUNTO conjuntoB){
    int i;
    for(i = 0; i < conjuntoA -> tamanio; i++){
        if(((conjuntoA -> elementos[i]) != 0) && (!pertenece(conjuntoB, conjuntoA -> elementos[i]))){
            return 0;
        }
    }
    return 1;
}
void liberarMemoria(CONJUNTO conjunto){
    free(conjunto -> elementos);
    free(conjunto);
    manejaMsg(1);
}