#include<stdlib.h>
#include "cad.h"

void manejaMsg(int);

CADENA crearCadena(int tamanio){
    CADENA cadena;

    cadena = (CADENA) malloc(sizeof(Cadena));

    if(cadena == NULL){
        manejaMsg(0);
        exit(0);
    }

    cadena -> tam = tamanio + 1;
    cadena -> cad = (char *) malloc((tamanio + 1) * sizeof(char));

    return cadena; 
}
char obtenComponente(CADENA cadena, int posicion){
    return cadena -> cad[posicion];
}
void ponComponente(CADENA cadena, int posicion, char elemento){
    cadena -> cad[posicion] = elemento;
}
int tamanio(CADENA cadena){
    return cadena -> tam;
}