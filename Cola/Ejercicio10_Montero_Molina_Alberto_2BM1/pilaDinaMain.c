#include <stdio.h>
#include <stdlib.h>
#include "pilaDina.h"

void manejaError(int);
void conversion(PILA, int);
void mostrar(PILA, int);
void liberarMemoria(PILA S);

void main(){
    PILA S;
    S = crearPila();
    int dato;
    printf("Introduzca el valor entero: ");
    scanf("%d", &dato);
    getchar();
    conversion(S, dato);
    mostrar(S, dato);
    liberarMemoria(S);
}
void mostrar(PILA S, int dato){
    int d;
    printf("\n");
    printf("Dato de entrada: %d\n", dato);
    printf("Salida: ");
    while(!es_vaciaPila(S)){
        d = desapilar(S);
        if((d - 10) >= 0 && (d - 10) <= 5){
            printf("%c", (65 + (d - 10)));
        }else{
            printf("%d", d);
        }
    }
    printf("\n");
}
void conversion(PILA S, int dato){
    int decimal = dato, residuo;
    while(decimal > 0){
        residuo = decimal % 16;
        apilar(S, residuo);
        decimal = decimal / 16;
    }
}

void manejaError(int msg){
    char * errores[] = {"No hay memoria disponible\n",
                        "La Pila esta Llena\n",
                        "La Pila esta Vacia\n",
                        "La Cola esta Llena\n",
                        "La Cola esta Vacia\n",
                        "Memoria liberada\n"};
    printf("%s", errores[msg]);
}
void liberarMemoria(PILA S){
    free(S);
    manejaError(5);
}