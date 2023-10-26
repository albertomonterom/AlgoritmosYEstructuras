#include<stdio.h>
#include "matriz.h"
#include<stdlib.h>
#include <math.h>

void manejaMsg(int);
void leerDim(int*, int*);
void llenarMatriz(MATRIZ);
void mostrarResultadoSuma(MATRIZ, MATRIZ, MATRIZ);
void mostrarResultadoResta(MATRIZ, MATRIZ, MATRIZ);
void mostrarResultadoMultiplicacion(MATRIZ, MATRIZ, MATRIZ);
void mostrarResultadoTraspuesta(MATRIZ, MATRIZ);
void mostrarMatriz(MATRIZ);
void menu(MATRIZ, MATRIZ);

void main(){
    int col1, col2, fil1, fil2;
    MATRIZ m1, m2;
    printf("Ingresa las dimensiones de la primera matriz\n");
    leerDim(&fil1, &col1);
    printf("Ingresa las dimensiones de la segunda matriz\n");
    leerDim(&fil2, &col2);
    m1 = crearMatriz(fil1, col1);
    m2 = crearMatriz(fil2, col2);
    printf("Ingresa los datos de la primera matriz\n");
    llenarMatriz(m1);
    printf("Ingresa los datos de la segunda matriz\n");
    llenarMatriz(m2);

    menu(m1, m2);
}

void leerDim(int* fil, int* col){
    printf("filas:\n");
    scanf("%d", fil);
    printf("columnas:\n");
    scanf("%d", col);
}

void llenarMatriz(MATRIZ m1) {
    int i, j, elemento;

    for (i = 0; i < m1->filas; i++) {
        for (j = 0; j < m1->columnas; j++) {
            printf("Dato[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &elemento);
            m1->matriz[i][j] = elemento;
        }
    }
}

void menu(MATRIZ m1, MATRIZ m2){
    int opcion;
    MATRIZ m3, m4, m5, m6;
    m3 = crearMatriz(m1->filas, m1->columnas);
    m4 = crearMatriz(m1->filas, m1->columnas);
    m5 = crearMatriz(m1->filas, m1->columnas);
    m6 = crearMatriz(m1->filas, m1->columnas);

    while (1) {
        printf("\nSelecione la operacion que desea hacer con las matrices:\n");
        printf("1. SUMA \n");
        printf("2. RESTA \n");
        printf("3. MULTIPLICACION\n");
        printf("4. TRASPUESTA\n");
        printf("5. SALIR\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                m3=sumaMatriz(m1,m2);
                mostrarResultadoSuma(m1, m2, m3);
                break;
            case 2:
                m4=restaMatriz(m1, m2);
                mostrarResultadoResta(m1, m2, m4);
                break;
            case 3:
                m5=multiplicaMatriz(m1,m2);
                mostrarResultadoMultiplicacion(m1, m2, m5);
                break;
            case 4:
                m6=traspuestaMatriz(m1);
                mostrarResultadoTraspuesta(m1, m6);
                break;
            case 5:
                printf("Saliendo del programa.\n");
                exit(0);
            default:
                printf("Opcion no valida. Por favor, seleccione una opcion valida.\n");
        }
    }
}

void mostrarMatriz(MATRIZ m){
    int i, j;

    for (i=0; i<m->filas; i++){
        for (j=0; j<m->columnas; j++)
            printf ("\t%d", m->matriz[i][j]);
            printf ("\n");
    }
}

void mostrarResultadoSuma(MATRIZ m1, MATRIZ m2, MATRIZ m3){
    printf("El resultado de la suma de la primera matriz mas la segunda es el siguiente:\n");
    printf("Primer sumando:\n");
    mostrarMatriz(m1);
    printf("Segundo sumando\n");
    mostrarMatriz(m2);
    printf("Resultado\n");
    mostrarMatriz(m3);
}
void mostrarResultadoResta(MATRIZ m1, MATRIZ m2, MATRIZ m3){
    printf("El resultado de la resta de la primera matriz menos la segunda es el siguiente:\n");
    printf("Primera matriz:\n");
    mostrarMatriz(m1);
    printf("Segunda matriz\n");
    mostrarMatriz(m2);
    printf("Resultado\n");
    mostrarMatriz(m3);
}
void mostrarResultadoMultiplicacion(MATRIZ m1, MATRIZ m2, MATRIZ m3){
    printf("El resultado del producto de la primera matriz por la segunda es:\n");
    printf("Primer producto:\n");
    mostrarMatriz(m1);
    printf("Segundo producto\n");
    mostrarMatriz(m2);
    printf("Resultado\n");
    mostrarMatriz(m3);
}
void mostrarResultadoTraspuesta(MATRIZ m1, MATRIZ m2){
    printf("La matriz traspuesta de la primera matriz es la siguiente:\n");
    printf("Primera matriz:\n");
    mostrarMatriz(m1);
    printf("Traspuesta\n");
    mostrarMatriz(m2);
}

void manejaMsg(int msg){
     char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  "};
     printf("%s", mensajes[msg] );
}