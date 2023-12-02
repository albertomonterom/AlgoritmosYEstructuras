#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void manejaMsg(int);
void liberarMemoria(COLA);
void menu(COLA);
void leerDato(COLA);
COLA interseccion(COLA, COLA);
void mostrarCola(COLA);

void main(){
    COLA A, B, C;
    A = crearCola();
    B = crearCola();
    C = crearCola();

    printf("Introduce los elementos para la COLA A\n");
    menu(A);
    printf("\n");
    printf("\n");
    printf("Introduce los elementos para la COLA B\n");
    menu(B);

    C = interseccion(A, B);
    mostrarCola(C);
}
COLA interseccion(COLA A, COLA B){
    COLA C;
    C = crearCola();
    int elemA, elemB, tamanio, prim;
    prim = B -> primero;
    tamanio = B -> tam;
    while(!es_vaciaCola(A)){
        elemA = desencolar(A);
        while(!es_vaciaCola(B)){
            elemB = desencolar(B);
            if(elemA == elemB){
                encolar(C, elemA);
            }
        }
        B -> primero = prim;
        B -> tam = tamanio;
    }
    return C;
}
void mostrarCola(COLA C){
    printf("\n");
    printf("COLA C resultante de la interseccion: ");
    while(!es_vaciaCola(C)){
        printf("%d ", desencolar(C));
    }
}
void menu(COLA C){
    int dato, opcion;
    printf("Introduzca un elemento: ");
    scanf("%d", &dato);
    getchar();
    encolar(C, dato);

    do{
        printf("¿Desea introducir otro elemento? (1: Si, 0: No): ");
        scanf("%d", &opcion);
        getchar();

        switch(opcion){
            case 1:
                leerDato(C);
                break;
            case 0:
                break;
            default:
                printf("\nOpcion no valida\n");
        }
    }while(opcion != 0);
}
void leerDato(COLA C){
    int dato;
    printf("Introduzca el elemento: ");
    scanf("%d", &dato);
    getchar();
    encolar(C, dato);
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