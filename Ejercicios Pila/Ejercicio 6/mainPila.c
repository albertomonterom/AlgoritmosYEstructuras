#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void mostrarElementos(PILA);
void introducirElemento(PILA);
void liberarMemoria(PILA);
char * crearArr();
void manejaMsg(int);

void main(){
    PILA S;
    S = crearPila();
    int opcion;
    do{
        printf("\n");
        printf("1.- Introducir un elemento a la cesta\n");
        printf("2.- Sacar un elemento de la cesta\n");
        printf("3.- Imprimir los elementos que contiene la cesta\n");
        printf("4.- Salir\n");
        printf("Introduzca alguna de las opciones: ");
        scanf("%d", &opcion);
        getchar();

        switch(opcion){
            case 1:
                introducirElemento(S);
                break;
            case 2:
                desapilar(S);
                break;
            case 3:
                mostrarElementos(S);
                break;
            case 4:
                printf("\nSaliendo del programa\n");
                liberarMemoria(S);
                break;
            default:
                printf("\nOpcion invalida. Intentelo de nuevo\n");
        }
    }while(opcion != 4);
}
void mostrarElementos(PILA S){
    int pos = 0;
    int topeTemp = S -> tope;
    PILA temp;
    temp = crearPila();
    while(!(es_vacia(S))){
        apilar(temp, desapilar(S));
    }
    printf("\nLa cesta contiene: \n");
    while(!(es_vacia(temp))){
        printf("\n\t%d. %s", ++pos, desapilar(temp));
    }
    printf("\n");
    S -> tope = topeTemp;
}
void introducirElemento(PILA S){
    char ch;
    int pos = 0;
    char * producto = crearArr();
    printf("Ingrese el nombre del producto: ");
    scanf("%[^\n]", producto);
    apilar(S, producto);
}
char * crearArr(){
    char * arr;
    arr = (char *)malloc(sizeof(char) * 20);
    if(arr == NULL){
        manejaMsg(0);
        exit(0);
    }
    return arr;
}

void manejaMsg(int msg){
    char * mensaje[] = {"No hay memoria disponible . . . \n", "La cesta esta llena. No se puede agregar mas productos\n", "\nLa cesta esta vacia. No hay elementos para sacar\n", "\nMemoria liberada . . . \n"};
    printf("%s", mensaje[msg]);
}
void liberarMemoria(PILA S){
    free(S);
    manejaMsg(4);
}