#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void agregarExpediente(PILA);
void leerExpediente(EXPEDIENTE);
EXPEDIENTE crearExpediente();
void ExpedPorMes(PILA);
void mostrarExpedientes(PILA);
void manejaMsg(int);

void main(){
    PILA S;
    S = crearPila();
    int opcion;

    do{
        printf("\n");
        printf("1.- Agregar Expediente\n");
        printf("2.- Obtener Expedientes pos Mes\n");
        printf("3.- Obtener Expedientes por Fecha\n");
        printf("4.- Mostrar Expedientes\n");
        printf("0.- Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);
        getchar();

        switch(opcion){
            case 1:
                agregarExpediente(S);
                break;
            case 2:
                ExpedPorMes(S);
                break;
            case 3:
                break;
            case 4:
                mostrarExpedientes(S);
                break;
            case 0:
                printf("\nSaliendo del programa\n");
                break;
            default:
                printf("\nOpcion no valida. Intente de nuevo\n");
        }
    }while(opcion != 0);
}
void ExpedPorMes(PILA S){
    int m, temp = S -> tope;
    EXPEDIENTE exp;
    PILA pilaMes;
    pilaMes = crearPila();
    printf("\nIngrese el mes (01-12): ");
    scanf("%d", &m);
    getchar();
    
    while(!es_vacia(S)){
        exp = desapilar(S);
        if((exp -> fecha.mes) == m){
            apilar(pilaMes, exp);
        }
    }
    S -> tope = temp;

    printf("Expedientes para el mes %d:\n", m);
    mostrarExpedientes(pilaMes);
}
void mostrarExpedientes(PILA S){
    int temp = S -> tope;
    EXPEDIENTE exp;
    while(!es_vacia(S)){
        exp = desapilar(S);
        printf("\nNo. de Expediente: %d\nTitular: %s\nTramite: %s\nFecha del expediente: %d/%d/%d", 
                exp -> numero,
                exp -> titular,
                exp -> tramite,
                exp -> fecha.dia,
                exp -> fecha.mes,
                exp -> fecha.anio
        );
        printf("\n");
    }
    S -> tope = temp;
}
void agregarExpediente(PILA S){
    int opcion;
    EXPEDIENTE exp;
    do{
        exp = crearExpediente();
        leerExpediente(exp);
        apilar(S, exp);

        printf("¿Desea agregar otro expediente? (1: Sí, 0: No): ");
        scanf("%d", &opcion);
        getchar();
    }while(opcion == 1);
}
void leerExpediente(EXPEDIENTE exp){
    printf("\n");
    printf("Ingrese el numero de expediente: ");
    scanf("%d", &(exp -> numero));
    getchar();
    printf("Ingrese el titular del expediente: ");
    scanf("%[^\n]", exp -> titular);
    getchar();
    printf("Ingrese el tramite del expediente: ");
    scanf("%[^\n]", exp -> tramite);
    getchar();
    printf("Ingrese la fecha del expediente (dd mm yyyy): ");
    scanf("%d %d %d", &(exp -> fecha.dia), &(exp -> fecha.mes), &(exp -> fecha.anio));
    getchar();
}
EXPEDIENTE crearExpediente(){
    EXPEDIENTE exp;

    exp = (EXPEDIENTE) malloc(sizeof(Expediente));

    if(exp == NULL){
        manejaMsg(0);
        exit(0);
    }

    return exp;
}
void manejaMsg(int msg){
    char * mensaje[] = {"\nNo hay memoria disponible . . .\n", "\nError: Pila Llena\n", "\nError: Pila Vacia\n"};
    printf("%s", mensaje[msg]);
}