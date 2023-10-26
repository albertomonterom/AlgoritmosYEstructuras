#include<stdlib.h>
#include "matriz.h"
#include <math.h>

void manejaMsg(int);

MATRIZ crearMatriz(int Filas, int Columnas){
    MATRIZ m;
    int i;

    m = (MATRIZ)malloc(sizeof(Matriz));
    if (m == NULL) {
        manejaMsg(0);
        exit(0);
    }

    m->matriz = (int**)malloc(Filas * sizeof(int*));
    if (m->matriz == NULL) {
        manejaMsg(0);
        exit(0);
    }
    for (i = 0; i < Filas; i++) {
        m->matriz[i] = (int *)malloc(Columnas * sizeof(int));
        if (m->matriz[i] == NULL) {
            manejaMsg(0);
            exit(0);
        }
    }
    m->columnas = Columnas;
    m->filas = Filas;
    return m;
}

int obtenValor(MATRIZ m1,  int fila, int columna){
    return m1->matriz[fila][columna];
}

MATRIZ asignaValor(MATRIZ m1, int fila, int columna, int elemento){
    m1->matriz[fila][columna]=elemento;
    return m1;
}

int tamFilas(MATRIZ m1){
    return m1->filas;
}
int tamColumnas(MATRIZ m1){
    return m1->columnas;
}
MATRIZ sumaMatriz(MATRIZ m1, MATRIZ m2){
    int i, j;
    MATRIZ m3;
    m3 = crearMatriz(m1->filas, m1->columnas);
    for(i = 0; i<m1->filas; i++){
        for(j=0; j<m1->columnas; j++)
            m3->matriz[i][j] = m1->matriz[i][j] + m2->matriz[i][j];
    }
    return m3;
}
MATRIZ restaMatriz(MATRIZ m1, MATRIZ m2){
    int i, j;
    MATRIZ m3;
    m3 = crearMatriz(m1->filas, m1->columnas);
    for(i = 0; i<m1->filas; i++){
        for(j=0; j<m1->columnas; j++)
            m3->matriz[i][j] = m1->matriz[i][j] - m2->matriz[i][j];
    }
    return m3;
}
MATRIZ multiplicaMatriz(MATRIZ m1, MATRIZ m2){
    int i, j, k, h, valor;
    MATRIZ m3;
    m3 = crearMatriz(m1->columnas, m2->filas);
     for (i = 0; i < m1->filas; i++)
        for (j = 0; j < m2->columnas; j++) {
            int suma = 0;
            for (k = 0; k < m1->columnas; k++) {
                suma += m1->matriz[i][k] * m2->matriz[k][j];
            }
            m3->matriz[i][j] = suma;
        }
    return m3;
}
MATRIZ traspuestaMatriz(MATRIZ m1){
    int i, j, aux;
    MATRIZ m3;
    m3 = crearMatriz(m1->columnas, m1->filas);
    for(i = 0; i<m1->filas; i++)
        for(j = 0; j<m1->columnas; j++){
            m3->matriz[j][i] = m1->matriz[i][j];
        }
    return m3;
}