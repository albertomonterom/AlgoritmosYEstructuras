#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void mostrarPila(PILA);
void manejaMsg(int);
void liberarMemoria(PILA);

void main(){
    PILA S;
    S = crearPila();
    int opcion, elem;
    do{
        printf("\n¿Desea insertar un nuevo elemento? (1: Sí, No: 0)\n");
        scanf("%d", &opcion);
        getchar();
        switch(opcion){
            case 0:
                if(es_vaciaPila(S)){
                    manejaMsg(3);
                }else{
                    mostrarPila(S);
                    liberarMemoria(S);
                }
                break;
            case 1:
                printf("Inserta el elemento: ");
                scanf("%d", &elem);
                apilar(S, elem);
                getchar();
                break;
            default:
                printf("\nOpcion invalida");
        }
    }while(opcion != 0);
}
void mostrarPila(PILA S){
    int v;
    printf("\nPila:\t");
    while(!es_vaciaPila(S)){
        printf("%d", desapilar(S));
        printf(", ");
    }
    printf("\n");
}
void manejaMsg(int msg){
    char * mensaje[] = {"No hay memoria disponible . . . ", "\nMemoria liberada . . .\n", "Pila llena . . .", "Pila vacia . . ."};
    printf("%s", mensaje[msg]);
}
void liberarMemoria(PILA S){
    free(S);
    manejaMsg(1);
}