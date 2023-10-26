#include<stdio.h>
#include "complejo.h"

void manejaMsg(int);
char * operacionMsg(int);
void darComplejos(COMPLEJO, COMPLEJO);
void mostrarComplejo(COMPLEJO, COMPLEJO, COMPLEJO, int);

void main(){
    COMPLEJO C1, C2, C3;
    int opcion, operacion;
    C1 = crearComplejo();
    C2 = crearComplejo();
    C3 = crearComplejo();
    darComplejos(C1, C2);

    do{
        printf("\n");
        printf("--------------------------\n");
        printf("           MENU           \n");
        printf("--------------------------\n");
        printf("1.- Suma\n");
        printf("2.- Resta\n");
        printf("3.- Multiplicacion\n");
        printf("4.- Division\n");
        printf("5.- Salir\n");
        printf("Selecciona alguna de las opciones anteriores: ");
        scanf("%d", &opcion);

        switch(opcion){
            case 1:
                C3 = suma(C1, C2);
                operacion = 0;
                break;
            case 2:
                C3 = resta(C1, C2);
                operacion = 1;
                break;
            case 3:
                C3 = multiplicacion(C1, C2);
                operacion = 2;
                break;
            case 4:
                C3 = division(C1, C2);
                operacion = 3;
                break;
            case 5:
                printf("\nSaliendo . . . \n");
                break;
            default:
                printf("\nSelecciona una opcion valida");
        }
        if(opcion != 5){
            mostrarComplejo(C1, C2, C3, operacion);
        }
    }while(opcion != 5);
}
void darComplejos(COMPLEJO C1, COMPLEJO C2){
    float r, i;
    printf("Dar la parte real del complejo 1: \n");
    scanf("%f", &r);
    asignaReal(C1, r);
    printf("Dar la parte imaginaria del complejo 1: \n");
    scanf("%f", &i);
    asignaImaginario(C1, i);
    printf("Dar la parte real del complejo 2: \n");
    scanf("%f", &r);
    asignaReal(C2, r);
    printf("Dar la parte imaginaria del complejo 2: \n");
    scanf("%f", &i);
    asignaImaginario(C2, i);
}
void mostrarComplejo(COMPLEJO C1, COMPLEJO C2, COMPLEJO C3, int operacion){
    printf("\n");
    printf("Complejo 1 %f + %fi \n", obtenReal(C1), obtenImaginario(C1));
    printf("Complejo 2 %f + %fi \n", obtenReal(C2), obtenImaginario(C2));
    printf("La %s es %f + %fi", operacionMsg(operacion), obtenReal(C3), obtenImaginario(C3));
    printf("\n");
}
void manejaMsg(int msg){
    char * mensajes[] = {"No hay memoria disponible ... \n"};
    printf("%s", mensajes[msg]);
}
char * operacionMsg(int msg){
    char * mensaje[] = {"suma", "resta", "multiplicacion", "division"};
    return mensaje[msg];
}