#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void leeNumero(int *);
void convertirHexadecimal(PILA, int);
void mostrarHexadecimal(PILA);
void manejaMsg(int);
void liberarMemoria(PILA);

void main(){
    PILA S;
    int numero;
    S = crearPila();
    leeNumero(&numero);
    convertirHexadecimal(S, numero);
    mostrarHexadecimal(S);
    liberarMemoria(S);
}
void mostrarHexadecimal(PILA S){
    int digito;
    printf("Representacion hexadecimal: ");
    while(!es_vacia(S)){
        digito = desapilar(S);
        if(digito < 10){
            printf("%d", digito);
        }else{
            printf("%c", 'A' + (digito - 10));
        }
    }
}
void convertirHexadecimal(PILA S, int num){
    int residuo;
    while(num > 0){
        residuo = num % 16;
        apilar(S, residuo);
        num /= 16;
    }
}
void leeNumero(int * num){
    printf("Ingrese un numero entero: ");
    scanf("%d", num);
    getchar();
}
void manejaMsg(int msg){
    char * mensaje[] = {"\nNo hay memoria disponible . . .\n", "\nError: Pila Llena\n", "\nError: Pila Vacia\n", "\nMemoria liberada\n"};
    printf("%s", mensaje[msg]);
}
void liberarMemoria(PILA S){
    free(S);
    manejaMsg(3);
}