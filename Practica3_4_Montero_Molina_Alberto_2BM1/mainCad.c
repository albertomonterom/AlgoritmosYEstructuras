#include<stdio.h>
#include<stdlib.h>
#include "cad.h"

CADENA numCaracteres(CADENA);
CADENA leeCadena(CADENA);
CADENA decoCadena(CADENA);
void mostrarCadenas(CADENA, CADENA);
void manejaMsg(int);
void liberarMemoria(CADENA, CADENA);


void main(){
    CADENA cadena, decodificada;
    cadena = numCaracteres(cadena);
    cadena = leeCadena(cadena);
    decodificada = decoCadena(cadena);
    mostrarCadenas(cadena, decodificada);
    liberarMemoria(cadena, decodificada);
}
CADENA numCaracteres(CADENA cadena){
    int tamanio;
    printf("\nIntroduce el numero de caracteres: \n");
    scanf("%d", &tamanio);
    getchar();
    cadena = crearCadena(tamanio);
    return cadena;
}
CADENA leeCadena(CADENA cadena){
    printf("Introduce la cadena codificada: \n");
    scanf("%[^\n]", cadena -> cad);
    return cadena;
}
CADENA decoCadena(CADENA cadena){
    int i;
    char letters[5] = {'a', 'e', 'i', 'o', 'u'};
    int componente;
    CADENA decodificada = crearCadena(tamanio(cadena));
    for(i = 0; i < tamanio(cadena); i++){
        ponComponente(decodificada, i, obtenComponente(cadena, i)); 
    }
    for(i = 0; i < tamanio(cadena); i++){
        componente = obtenComponente(cadena, i) - '0';
        if((componente >= 1) && (componente <= 5)){
            ponComponente(decodificada, i, letters[componente-1]);
        }
    }
    return decodificada;
}
void mostrarCadenas(CADENA cadena, CADENA decodificada){
    printf("\nCadena codificada A: %s\n", cadena -> cad);
    printf("\nCadena decodificada B: %s\n", decodificada -> cad);
}
void manejaMsg(int msg){
    char * mensajes[] = {"No hay memoria disponible . . . \n", "\nMemoria liberada . . . \n"};
    printf("%s", mensajes[msg]);
}
void liberarMemoria(CADENA cadena, CADENA decodificada){
    free(cadena);
    free(decodificada);
    manejaMsg(1);
}