#include <stdlib.h>
#include <stdio.h>
#include "cola.h"

void manejaMsg(int);
void liberarMemoria(COLA);
void agregarDato(COLA);
int ultimoCola(COLA);
void mostrar(int);

void main(){
    COLA C;
    C = crearCola();
    int opcion, dato, ult;
    printf("Introduzca un elemento entero: ");
    scanf("%d", &dato);
    getchar();
    encolar(C, dato);

    do{
        printf("\n");
        printf("¿Desea introducir un elemento? (1: Si, 0: No): ");
        scanf("%d", &opcion);
        getchar();

        switch(opcion){
            case 1:
                agregarDato(C);
                break;
            case 0:
                break;
            default:
                printf("\nOpcion invalida\n");
        }
    }while(opcion != 0);
    ult = ultimoCola(C);
    mostrar(ult);
}
void mostrar(int ult){
    printf("\nEl ultimo elemento es: %d\n", ult);
}
int ultimoCola(COLA C){
    int dato;
    while(!es_vaciaCola(C)){
        dato = desencolar(C);
    }
    return dato;
}
void agregarDato(COLA C){
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