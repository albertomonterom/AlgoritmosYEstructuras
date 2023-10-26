#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "abstracto.h"

void obtenerRaices(ECUACION, float *, float *);
void manejaMsg(int);
void liberarMemoria(ECUACION);

void main(){
    ECUACION ecuacion;
    float a, b, c, x1, x2;
    ecuacion = crearEcuacion();

    printf("Ingrese el coeficiente A: \n");
    scanf("%f", &a);
    asignaA(ecuacion, a);

    printf("Ingrese el coeficiente B: \n");
    scanf("%f", &b);
    asignaB(ecuacion, b);

    printf("Ingrese el coeficiente C: \n");
    scanf("%f", &c);
    asignaC(ecuacion, c);

    obtenerRaices(ecuacion, &x1, &x2);

    liberarMemoria(ecuacion);
}
void obtenerRaices(ECUACION ecuacion, float * x1, float * x2){
    if((ecuacion -> a) != 0){
        float discriminante = pow(obtenB(ecuacion), 2) - (4 * obtenA(ecuacion) * obtenC(ecuacion));

        if(discriminante >= 0){
            *x1 = (-obtenB(ecuacion) + sqrt(discriminante)) / (2 * obtenA(ecuacion));
            *x2 = (-obtenB(ecuacion) - sqrt(discriminante)) / (2 * obtenA(ecuacion));
            printf("Las raices son: x1 = %.2f y x2 = %.2f\n", *x1, *x2);
        }else{
            float real = (-obtenB(ecuacion)) / (2 * obtenA(ecuacion));
            float imaginaria = sqrt(-discriminante) / (2 * obtenA(ecuacion));
            printf("Las raices complejas son: x1 = %.2f + %.2fi y x2 = %.2f - %.2fi\n", real, imaginaria, real, imaginaria);
        }
    }else{
        printf("Solo tiene una raiz: %.2f\n", ((-obtenC(ecuacion))/obtenB(ecuacion)));
    }
}
void manejaMsg(int msg){
    char * mensajes[] = {"No hay memoria disponible . . . \n", "\nMemoria liberada . . . \n"};
    printf("%s", mensajes[msg]);
}
void liberarMemoria(ECUACION ecuacion){
    free(ecuacion);
    manejaMsg(1);
}