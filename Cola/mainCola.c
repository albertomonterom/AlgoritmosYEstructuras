#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void manejaMsg(int);

void main(){
}

void manejaMsg(int msg){
    char * errores[] = {"No hay memoria disponible\n",
                        "La Pila esta Llena\n",
                        "La Pila esta Vacia\n",
                        "La Cola esta Llena\n",
                        "La Cola esta Vacia\n"};
    printf("%s", errores[msg]);
}