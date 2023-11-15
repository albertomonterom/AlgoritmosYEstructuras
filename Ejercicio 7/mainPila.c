#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

char * leerTexto(char *);
void analizaTexto(PILA, char *);
void mostrarTexto(PILA);
void analizaTexto(PILA, char *);
void manejaMsg(int);
void liberarMemoria(PILA);

void main(){
    PILA cadena;
    cadena = crearPila();
    char cad[TAMPILA];
    leerTexto(cad);
    analizaTexto(cadena, cad);
    mostrarTexto(cadena);
}
void mostrarTexto(PILA cadena){
    PILA temp;
    temp = crearPila();
    while(!es_vacia(cadena)){
        apilar(temp, desapilar(cadena));
    }
    printf("El resultado del texto analizado es: ");
    while(!es_vacia(temp)){
        printf("%c", desapilar(temp));
    }
    printf("\n");
}
void analizaTexto(PILA cadena, char * cad){
    char ch;
    int pos = 0;
    while((ch = cad[pos]) != '\0'){
        if(ch == '#'){
            desapilar(cadena);
        }else if(ch == '@'){
            while(!es_vacia(cadena)){
                desapilar(cadena);
            }
        }else{
            apilar(cadena, ch);
        }
        pos++;
    }
}
char * leerTexto(char * cad){
    char ch;
    int pos = 0;
    printf("Introduzca el texto: ");
    while((ch = getchar()) != '\n'){
        cad[pos++] = ch;
    }
    cad[pos] = '\0';
    return cad;
}
void manejaMsg(int msg){
    char * mensaje[] = {"\nNo hay memoria disponible\n", "\nError: Pila Llena\n", "\nError: Pila Vacia\n", "\nMemoria liberada\n"};
    printf("%s", mensaje[msg]);
}
void liberarMemoria(PILA S){
    free(S);
    manejaMsg(4);
}