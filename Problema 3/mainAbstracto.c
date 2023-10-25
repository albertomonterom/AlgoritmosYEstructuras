#include<stdio.h>
#include "abstracto.h"

void manejaMsg(int);

void main(){
    ECUACION ecuacion;
    float a, b, c, x1, x2;
    ecuacion = crearEcuacion();

    printf("Ingrese el coeficiente a: \n");
    scanf("%f", &a);
    asignaA(ecuacion, a);

    printf("Ingrese el coeficiente b: \n");
    scanf("%f", &b);
    asignaB(ecuacion, b);

    printf("Ingrese el coeficiente C: \n");
    scanf("%f", &c);
    asignaC(ecuacion, c);

    obtenerRaices(ecuacion, &x1, &x2);

    printf("Las raices son: %.2f y %.2f \n", x1, x2);
}

void manejaMsg(int msg){
    char * mensajes[] = {"No hay memoria disponible . . . \n"};
    printf("%s", mensajes[msg]);
}