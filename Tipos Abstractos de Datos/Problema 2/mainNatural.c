#include<stdio.h>
#include "natural.h"

void manejaMsg(int);

void main(){
    Natural n1, n2;

    printf("Ingrese el primer numero natural: \n");
    scanf("%d", &n1);
    if(n1 < 0){
        printf("El numero debe ser natural (mayor o igual a cero)");
        return;
    }

    printf("Ingrese el segundo numero natural: \n");
    scanf("%d", &n2);
    if(n2 < 0){
        printf("El numero debe se natural (mayor o igual a cero)");
        return;
    }

    //Verificar si los numeros son cero
    printf("El primer numero es cero: %s\n", esCero(n1) ? "Verdadero" : "Falso");
    printf("El segundo numero es cero: %s\n", esCero(n2) ? "Verdadero" : "Falso");

    //Verificar si uno es menor que el otro
    printf("El primer numero es menor que el segundo: %s\n", esMenor(n1, n2) ? "Verdadero" : "Falso");
    printf("El primer numero es menor o igual que el segundo: %s\n", esMenorIgual(n1, n2) ? "Verdadero" : "Falso");

    //Verificar si uno es mayor que el otro
    printf("El primer numero es mayor que el segundo: %s\n", esMayor(n1, n2) ? "Verdadero" : "Falso");
    printf("El primer numero es mayor o igual que el segundo: %s\n", esMayorIgual(n1, n2) ? "Verdadero" : "Falso");

    //Calcular y mostrar el sucesor y predecesor de ambos numeros
    printf("El sucesor del primero numero es: %d\n", sucesor(n1));
    printf("El predecesor del primero numero es: %d\n", predecesor(n1));
    printf("El sucesor del segundo numero es: %d\n", sucesor(n2));
    printf("El predecesor del segundo numero es: %d\n", predecesor(n2));
}

void manejaMsg(int msg){
    char * mensajes[] = {"No hay memoria disponible . . . \n"};
    printf("%s", mensajes[msg]);
}