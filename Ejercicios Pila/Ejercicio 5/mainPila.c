#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void leeCadena(PILA, char *);
void numElem(PILA);
void copiarPila(PILA, PILA);
void elemFondo(PILA);
void numElem(PILA);
void manejaMsg(int);

void main(){
    PILA S, D;
    char cad[TAMPILA];
    S = crearPila();
    leeCadena(S, cad);
    int opcion;
    do{
        printf("\n");
        printf("1.- Calcular el numero de elementos de una Pila\n");
        printf("2.- Consultar el elemento del fondo de la Pila\n");
        printf("3.- Copiar una Pila a otra\n");
        printf("4.- Salir\n");
        printf("Selecciona una de las opciones: ");
        scanf("%d", &opcion);
        printf("\n");

        switch(opcion){
            case 1:
                numElem(S);
                break;
            case 2:
                elemFondo(S);
                break;
            case 3:
                D = crearPila();
                copiarPila(S, D);
                break;
            case 4:
                printf("\nSaliendo del programa\n");
                break;
            default:
                printf("\nOpcion invalida. Intentelo de nuevo\n");
        }
    }while(opcion != 4);
}
void copiarPila(PILA S, PILA D){
    int pos;
    if(es_vacia(S)){
        manejaMsg(3);
        exit(0);
    }
    for(pos = 0; pos <= S -> tope; pos++){
        apilar(D, S -> cadena[pos]);
    }
    printf("Pila copiada exitosamente\n");
    
}
void elemFondo(PILA S){
    if(es_vacia(S)){
        manejaMsg(3);
        exit(0);
    }
    printf("Elemento del fondo de la pila: %c\n", S -> cadena[0]);
                
}
void numElem(PILA S){
    if(es_vacia(S)){
        manejaMsg(3);
        exit(0);
    }
    printf("Numero de elementos en la pila: %d\n", S -> tope + 1);
                
}
void leeCadena(PILA S, char * cad){
    char ch;
    int pos = 0;
    printf("Introduzca la cadena: ");
    while((ch = getchar()) != '\n'){
        cad[pos++] = ch;
    }
    cad[pos] = '\0';

    //Pila
    pos = 0;
    while((ch = cad[pos++]) != '\0'){
        apilar(S, ch);
    }
}
void manejaMsg(int msg){
    char * mensaje[] = {"No hay memoria disponible . . . \n", "Pila Llena \n", "Error: Pila vacia no hay elementos para consultar\n", "Memoria liberada . . . \n"};
    printf("%s", mensaje[msg]);
}