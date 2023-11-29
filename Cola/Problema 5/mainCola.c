#include <stdlib.h>
#include <stdio.h>
#include "cola.h"

void manejaMsg(int);
void liberarMemoria(COLA);
void menu(COLA);
COLA agrupaColas(COLA, COLA, COLA, COLA);
COLA mezclaCola(COLA, COLA);
void mostrar(COLA);

void main(){
int dato;
    COLA C1, C2, C3, C4, C5;
    C1 = crearCola();
    C2 = crearCola();
    C3 = crearCola();
    C4 = crearCola();

    printf("Introduzca un elemento entero para C1: ");
    scanf("%d", &dato);
    getchar();
    encolar(C1, dato);
    menu(C1);

    printf("\n");
    printf("Introduzca un elemento entero para C2: ");
    scanf("%d", &dato);
    getchar();
    encolar(C2, dato);
    menu(C2);

    printf("Introduzca un elemento entero para C3: ");
    scanf("%d", &dato);
    getchar();
    encolar(C3, dato);
    menu(C3);

    printf("\n");
    printf("Introduzca un elemento entero para C4: ");
    scanf("%d", &dato);
    getchar();
    encolar(C4, dato);
    menu(C4);

    C5 = agrupaColas(C1, C2, C3, C4);
    mostrar(C5);
}
void mostrar(COLA C){
    printf("Elementos de la cola: ");
    while(!es_vaciaCola(C)){
        printf("%d ", desencolar(C));
    }
}
COLA agrupaColas(COLA C1, COLA C2, COLA C3, COLA C4){
    COLA aux1, aux2, C5;
    aux1 = mezclaCola(C1, C2);
    aux2 = mezclaCola(aux1, C3);
    C5 = mezclaCola(aux2, C4);
    return C5;
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