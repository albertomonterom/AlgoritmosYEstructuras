#include <stdlib.h>
#include <stdio.h>
#include "cola.h"

void manejaMsg(int);
void liberarMemoria(COLA);
void menu(COLA);
COLA mezclaCola(COLA, COLA);
void mostrar(COLA);

void main(){
    int dato;
    COLA C1, C2, C3;
    C1 = crearCola();
    C2 = crearCola();
    printf("Introduzca un elemento entero para C1: ");
    scanf("%d", &dato);
    getchar();
    encolar(C1, dato);
    menu(C1);

    printf("\n");
    printf("\n");
    printf("Introduzca un elemento entero para C2: ");
    scanf("%d", &dato);
    getchar();
    encolar(C2, dato);
    menu(C2);

    C3 = mezclaCola(C1, C2);
    mostrar(C3);
}
void mostrar(COLA C){
    printf("Elementos de la cola: ");
    while(!es_vaciaCola(C)){
        printf("%d ", desencolar(C));
    }
}
COLA mezclaCola(COLA C1, COLA C2){
    COLA C3;
    C3 = crearCola();
    while(!es_vaciaCola(C1) || !es_vaciaCola(C2)){
        if(!es_vaciaCola(C1)){
            encolar(C3, desencolar(C1));
        }
        if(!es_vaciaCola(C2)){
            encolar(C3, desencolar(C2));
        }
    }
    return C3;
}
void menu(COLA C){
    int opcion, dato;
    do{
        printf("\n");
        printf("¿Desea introducir otro elemento? (1: Si, 0: No): ");
        scanf("%d", &opcion);
        getchar();

        switch(opcion){
            case 1:
                printf("Introduzca el dato: ");
                scanf("%d", &dato);
                getchar();
                encolar(C, dato);
                break;
            case 0:
                break;
            default:
                printf("\nOpcion invalida\n");
        }
    }while(opcion != 0);
}
void manejaMsg(int msg){
    char * errores[] = {"No hay memoria disponible\n",
                        "La Pila esta Llena\n",
                        "La Pila esta Vacia\n",
                        "La Cola esta Llena\n",
                        "La Cola esta Vacia\n",
                        "Memoria liberada\n"};
    printf("%s", errores[msg]);
}
void liberarMemoria(COLA C){
    free(C);
    manejaMsg(5);
}