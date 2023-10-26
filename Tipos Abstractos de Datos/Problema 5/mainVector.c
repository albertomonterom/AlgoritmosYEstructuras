#include<stdio.h>
#include<stdlib.h>
#include "vector.h"

void llenarVector(VECTOR);
void mostrarVector(VECTOR);
void manejaMsg(int);
void liberarMemoria(VECTOR);

void main(){
    int tamanio;
    VECTOR vector1, vector2;
    printf("Introduce el tamaño de los vectores: ");
    scanf("%d", &tamanio);
    getchar();

    vector1 = crearVector(tamanio);
    vector1 -> tamanio = tamanio;
    vector2 = crearVector(tamanio);
    vector2 -> tamanio = tamanio;

    llenarVector(vector1);
    llenarVector(vector2);

    int opcion, v;
    VECTOR resultado;
    do{
        printf("\n");
        printf("--------------------------\n");
        printf("           MENU           \n");
        printf("--------------------------\n");
        printf("1.- Suma\n");
        printf("2.- Resta\n");
        printf("3.- Producto punto\n");
        printf("4.- Ordenar de manera descendente\n");
        printf("5.- Salir\n");
        printf("Selecciona alguna de las opciones anteriores: ");
        scanf("%d", &opcion);

        switch(opcion){
            case 1:
                resultado = sumaVector(vector1, vector2);
                printf("\nResultado de la suma:\n");
                mostrarVector(resultado);
                break;
            case 2:
                resultado = restaVector(vector1, vector2);
                printf("\nResultado de la resta: \n");
                mostrarVector(resultado);
                break;
            case 3:
                printf("\nEl producto punto es: %d\n", productoPunto(vector1, vector2));
                break;
            case 4:
                printf("\nIngrese el vector que desea ordenar: ");
                scanf("%d", &v);
                getchar();

                if(v == 1){
                    resultado = ordenaVector(vector1);
                    printf("\nVector ordenado: \n");
                    mostrarVector(resultado);
                }else if(v == 2){
                    resultado = ordenaVector(vector2);
                    printf("\nVector ordenado: \n");
                    mostrarVector(resultado);
                }else{
                    printf("\nOpcion invalida\n");
                }
                break;
            case 5:
                printf("\nSaliendo . . .\n");
                liberarMemoria(vector1);
                liberarMemoria(vector2);
                break;
        }
    }while(opcion != 5);
}

void llenarVector(VECTOR vector){
    int i;
    printf("\nIntroduce los %d elementos del vector: \n", vector -> tamanio);
    for(i = 0; i < vector -> tamanio; i++){
        scanf("%d", &vector -> datos[i]);
        getchar();
    }
}
void mostrarVector(VECTOR vector){
    int i;
    printf("[");
    for(i = 0; i < vector -> tamanio; i++){
        printf("%d", vector -> datos[i]);
        if(i < vector -> tamanio - 1){
            printf(", ");
        }
    }
    printf("]\n");
}
void manejaMsg(int msg){
    char * mensajes[] = {"No hay memoria disponible . . . \n", "\nMemoria liberada . . . \n"};
    printf("%s", mensajes[msg]);
}
void liberarMemoria(VECTOR vector){
    free(vector -> datos);
    free(vector);
    manejaMsg(1);
}