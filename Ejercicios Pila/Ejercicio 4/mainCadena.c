#include <stdio.h>
#include <stdlib.h>
#include "cadena.h"

void leeCadena(char *);
void invertirCadena(PILA, char *);
void mostrar(PILA);
void manejaMsg(int);
void liberarMemoria(PILA);

void main(){
    char cadena[TAMPILA];
    PILA S;
    S = crearPila();

    leeCadena(cadena);
    invertirCadena(S, cadena);
    mostrar(S);
    liberarMemoria(S);
}
void mostrar(PILA S){
    printf("Cadena invertida: ");
    while(!es_vacia(S)){
        printf("%c", desapilar(S));
    }
    printf("\n");
}
void invertirCadena(PILA S, char * cadena){
    char ch = cadena[0];
    int pos = 1;
    apilar(S, ch);
    while((ch = cadena[pos++]) != '\0'){
        apilar(S, ch);
    }
}
void leeCadena(char * cadena){
    char ch;
    int pos = 0;
    printf("Ingrese una cadena: ");
    while((ch = getchar()) != '\n'){
        cadena[pos++] = ch;
    }
    cadena[pos] = '\0';
}

void manejaMsg(int msg){
    char * mensaje[] = {"No hay memoria disponible . . .\n", "Pila Llena\n", "Pila Vacia\n", "Memoria liberada . . .\n"};
    printf("%s", mensaje[msg]);
}
void liberarMemoria(PILA S){
    free(S);
    manejaMsg(3);
}