#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void manejaMsg(int);
void mostrar(COLA, COLA);
int ultimo(COLA);
void intercambiarElementos(COLA, COLA);
void liberarMemoria(COLA);

void main(){
    int opcion, dato;
    COLA C, aux;
    Cola temporal;
    C = crearCola();
    aux = crearCola();
    printf("Introduzca un dato: ");
    scanf("%d", &dato);
    getchar();
    encolar(C, dato);

    do{
        printf("¿Desea intoducir otro dato? (1: Sí, 0: No): ");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                printf("Introduzca el dato: ");
                scanf("%d", &dato);
                encolar(C, dato);
                break;
            case 0:
                break;
            default:
                printf("\nOpcion invalida");
        }
    }while(opcion != 0);

    temporal = *C;
    intercambiarElementos(C, aux);
    mostrar(&temporal, aux);
    liberarMemoria(C);
}
void intercambiarElementos(COLA C, COLA aux){
    int elem;
    int prim = primero(C);
    int ult = ultimo(C); 
    while(!es_vaciaCola(C)){
        elem = desencolar(C);
        if(!es_vaciaCola(aux)){
            encolar(aux, prim);
        }else if(es_vaciaCola(aux)){
            encolar(aux, ult);
        }else{
            encolar(aux, elem);
        }
    }
    *C = *aux;
}
void mostrar(COLA C, COLA aux){
    //Mostrar cola original
    printf("Cola antes del intercambio: ");  
    while(!es_vaciaCola(C)){
        printf("%d ", desencolar(C));
    }
    printf("\n");

    //Mostrar cola aux
    printf("Cola después del intercambio: ");
    while(!es_vaciaCola(aux)){
        printf("%d ", desencolar(aux));
    }
    printf("\n");
}
int ultimo(COLA C){
    int  ult;
    Cola aux = *C;

    while(!es_vaciaCola(&aux)){
        ult = desencolar(&aux);
    }

    return ult;
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