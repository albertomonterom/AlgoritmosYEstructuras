#include <stdlib.h>
#include <stdio.h>
#include "cola.h"

void manejaMsg(int);
void liberarMemoria(COLA);
void agregarDato(COLA);
int tamCola(COLA);
void mostrar(int);

void main(){
    COLA C;
    int opcion, dato, tam;
    C = crearCola();
    printf("Introduzca un elemento entero: ");
    scanf("%d", &dato);
    encolar(C, dato);
    getchar();
    do{
        printf("\n");
        printf("¿Desea introducir otro dato? (1: Si, 0: No): ");
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

    tam = tamCola(C);
    mostrar(tam);
    liberarMemoria(C);
}
void mostrar(int tam){
    printf("\n");
    printf("La cola tiene %d elementos", tam);
    printf("\n");
}
int tamCola(COLA C){
    int contador = 0;
    while(!es_vaciaCola(C)){
        desencolar(C);
        contador++;
    }
    return contador;
}
void agregarDato(COLA C){
    int dato;
    printf("Introduzca otro dato: ");
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