#include<stdlib.h>
#include "vector.h"

VECTOR crearVector(int tamanio){
    VECTOR vector;
    
    vector = (VECTOR) malloc(sizeof(Vector));

    if(vector == NULL){
        manejaMsg(0);
        exit(0);
    }

    vector -> tamanio = tamanio;
    vector -> datos = (int *) malloc(tamanio * sizeof(int));

    return vector;
}
int obtenComponente(VECTOR vector, int indice){
    return vector -> datos[indice];
}
void asignaComponente(VECTOR vector, int indice, int valor){
    vector -> datos[indice] = valor;
}
VECTOR sumaVector(VECTOR vector1, VECTOR vector2){
    VECTOR resultado = crearVector(vector1 -> tamanio);
    
    int i;
    for(i = 0; i < resultado -> tamanio; i++){
        resultado -> datos[i] = vector1 -> datos[i] + vector2 -> datos[i];
    }
    return resultado;
}
VECTOR restaVector(VECTOR vector1, VECTOR vector2){
    VECTOR resultado = crearVector(vector1 -> tamanio);

    int i;
    for(i = 0; i < resultado -> tamanio; i++){
        resultado -> datos[i] = vector1 -> datos[i] - vector2 -> datos[i];
    }
    return resultado;
}
int productoPunto(VECTOR vector1, VECTOR vector2){
    int resultado = 0, i;

    for(i = 0; i < vector1 -> tamanio; i++){
        resultado += vector1 -> datos[i] * vector2 -> datos[i];
    }
    return resultado;
}
int esMayorQue(int elem1, int elem2){
    return elem1 > elem2;
}
VECTOR ordenaVector(VECTOR vector){
    int i, j;
    for(i = 0; i < vector -> tamanio - 1; i++){
        for(j = 0; j < vector -> tamanio - 1; j++){
            if(vector -> datos[j] < vector -> datos[j+1]){
                int temp = vector -> datos[j];
                vector -> datos[j] = vector -> datos[j+1];
                vector -> datos[j+1] = temp;
            }
        }
    }
    return vector;
}