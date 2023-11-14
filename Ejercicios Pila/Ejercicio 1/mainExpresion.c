#include <stdio.h>
#include <stdlib.h>
#include "expresion.h"

void manejaMsg(int);
void leerExpresion(char *);
int equilibrados(PILA, char *);
void liberarMemoria(PILA);

void main(){
    PILA S;
    char ent[TAMPILA];
    int valida;
    S = crearPila();

    leerExpresion(ent);

    valida = equilibrados(S, ent);

    if(valida){
        printf("Los parentesis, corchetes y llaves estan equilibrados\n");
    }else{
        printf("Los parentesis, corchetes y llaves no estan equilibrados\n");
    }
    liberarMemoria(S);
}
int equilibrados(PILA S, char * ent){
    char e[1], top; //Arreglo de un caracter
    int pos = 0;
    while(ent[pos] != '\0'){
        *e = ent[pos++]; //e es un apuntador a un caracter
        switch(*e){
            case '(':
            case '[':
            case '{':
                apilar(S, *e);
                break;
            case ')':
            case ']':
            case '}':
                if(es_vacia(S)){
                    return 0;
                }
                top = cima(S);
                if((*e == ')' && top != '(') ||
                   (*e == ']' && top != '[') ||
                   (*e == '}' && top != '{')){
                    return 0;
                }
                desapilar(S);
                break;
        }
    }
    return es_vacia(S);
}
void leerExpresion(char * ent){
    char ch;
    int pos = 0;
    printf("\n\tComprobacion de parentesis de una expresion\n");
    printf("Introduzca la expresion: ");
    while((ch = getchar()) != '\n'){
        ent[pos++] = ch;
    }
    ent[pos] = '\0';
}

void manejaMsg(int msg){
    char * mensaje[] = {"No hay memoria disponible . . . \n", "Pila Llena \n", "Pila Vacia \n", "Memoria liberada . . . \n"};
    printf("%s", mensaje[msg]);
}

void liberarMemoria(PILA S){
    free(S);
    manejaMsg(3);
}