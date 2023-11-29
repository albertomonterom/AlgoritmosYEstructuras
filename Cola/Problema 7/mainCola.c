#include <stdio.h>
#include <stdlib.h>
#include "cola.h"
#include "pila.h"

void manejaMsg(int);
void liberarMemoria(COLA);
void mostrar(int, int);
int verificarCapicua(int);
void leerEntero(int *);

void main(){
    int elemento, esCapicua;
    leerEntero(&elemento);
    esCapicua = verificarCapicua(elemento);
    mostrar(elemento, esCapicua);
}
void mostrar(int elemento, int esCapicua){
    printf("El elemento %d ", elemento);
    if(esCapicua){
        printf("es un capicúa.");
    }else{
        printf("no es un capicua");
    }
}
int verificarCapicua(int elemento){
    int dato = elemento, residuo, esCapicua = 0;
    COLA C = crearCola();
    PILA S = crearPila();
    while(dato > 0){
        residuo = dato % 10;
        encolar(C, residuo);
        apilar(S, residuo);
        dato /= 10;
    }
    while(!es_vaciaCola(C) && !es_vaciaPila(S)){
        if(desencolar(C) == desapilar(S)){
            esCapicua = 1;
        }else{
            esCapicua = 0;
            break;
        }
    }
    return esCapicua;
}
void leerEntero(int * elemento){
    printf("Introduzca un numero entero: ");
    scanf("%d", elemento);
    getchar();
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