#include <stdlib.h>
#include <stdio.h>
#include "cola.h"
#include <time.h>


void manejaMsg(int);
void liberarMemoria(COLA);
PERSONA crearPersona();
COLA colaNoColados(COLA, COLA, COLA);
void mostrar(COLA, COLA);
void leerDatos(COLA);
void leerPersona(COLA, int);
void asignaTicket(PERSONA);
void ordenar(Persona **, int);

PERSONA crearPersona(){
    PERSONA P;

    P = (PERSONA) malloc(sizeof(Persona));

    if(P == NULL){
        manejaMsg(0);
        exit(0);
    }

    return P;
}
void main(){
    COLA C, colados, noColados, noColadosDef;
    C = crearCola();
    colados = crearCola();
    noColados = crearCola();
    leerDatos(C);
    noColadosDef = colaNoColados(C, colados, noColados);
    mostrar(colados, noColadosDef);
}
COLA colaNoColados(COLA C, COLA colados, COLA noColados){
    PERSONA persona;
    int tamanio, i = 0;
    while(!es_vaciaCola(C)){
        persona = desencolar(C);
        if(persona -> ticket == 0){
            encolar(colados, persona);
        }else{
            encolar(noColados, persona);
        }
    }
    tamanio = noColados -> tam;

    //Arreglo dinamico
    Persona ** arrNoColados = (Persona **) malloc(tamanio * sizeof(Persona *));
    while(!es_vaciaCola(noColados)){
        arrNoColados[i] = desencolar(noColados);
        i++;
    }
    ordenar(arrNoColados, tamanio);

    COLA nuevoNoColados;
    nuevoNoColados = crearCola();
    for(i = 0; i < tamanio; i++){
        encolar(nuevoNoColados, arrNoColados[i]);
    }

    return nuevoNoColados;
}
void ordenar(Persona ** arr, int tam){
    int i, j;
    PERSONA temp;
    for(i = 0; i < tam - 1; i++){
        for(j = tam - 1; j > 0; j--){
            if((arr[j] -> atencion) > (arr[j - 1] -> atencion)){
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void mostrar(COLA colados, COLA noColados){
    PERSONA persona;
    printf("\n");
    printf("LISTA DE COLADOS:\n");
    while(!es_vaciaCola(colados)){
        persona = desencolar(colados);
        printf("Nombre: %s\n", persona -> nombre);
        printf("Sexo: %c\n", persona -> sexo);
        printf("Edad: %d\n", persona -> edad);
        printf("Ticket: %d\n", persona -> ticket);
        printf("Atencion: %d\n", persona -> atencion);
        printf("\n");
    }
    printf("LISTA DE NO COLADOS:\n");
    while(!es_vaciaCola(noColados)){
        persona = desencolar(noColados);
        printf("Nombre: %s\n", persona -> nombre);
        printf("Sexo: %c\n", persona -> sexo);
        printf("Edad: %d\n", persona -> edad);
        printf("Ticket: %d\n", persona -> ticket);
        printf("Atencion: %d\n", persona -> atencion);
        printf("\n");
    }
}
void leerDatos(COLA C){
    int opcion, contador = 1;
    do{
        printf("\n");
        printf("¿Desea formar a una persona? (1: Si, 0: No): ");
        scanf("%d", &opcion);
        getchar();

        switch(opcion){
            case 1:
                leerPersona(C, contador++);
                break;
            case 0:
                break;
            default:
                printf("\nOpcion invalida\n");
        }
    }while(opcion != 0);
}
void leerPersona(COLA C, int contador){
    PERSONA persona;
    persona = crearPersona();
    printf("\n");
    printf("PERSONA %d: \n", contador);
    printf("Introduzca su nombre: ");
    scanf("%[^\n]", persona -> nombre);
    getchar();
    printf("Introduzca el sexo: (H: Hombre, M: Mujer): ");
    scanf("%[^\n]", &persona -> sexo);
    getchar();
    printf("Introduzca su edad: ");
    scanf("%d", &persona -> edad);
    getchar();
    asignaTicket(persona);
    encolar(C, persona);
}
void asignaTicket(PERSONA P){
    int generator, aten = 0;
    srand(time(NULL));
    generator = rand() % 2;
    P -> ticket = generator;

    if(generator){
        aten = (rand() % 5) + 1;
        P -> atencion = aten;
    }
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