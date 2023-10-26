#include<stdio.h>
#include<stdlib.h>
#include "conjunto.h"

void manejaMsg(int);

void main(){
    int tamanioA, tamanioB, opcion, i, elemento;
    char letter;
    CONJUNTO conjuntoA, conjuntoB;

    printf("Ingresa el tamaño del conjunto A: \n");
    scanf("%d", &tamanioA);
    getchar();
    printf("Ingresa el tamaño del conjunto B: \n");
    scanf("%d", &tamanioB);
    getchar();

    conjuntoA = conjuntoVacio(tamanioA);
    conjuntoB = conjuntoVacio(tamanioB);

    //Llenar los conjuntos
    printf("Ingresa elementos para el conjunto A (separados por espacios): ");
    for(i = 0; i < tamanioA; i++){
        int elemento;
        scanf("%d", &elemento);
        getchar()
;        anadir(conjuntoA, elemento);
    }

    printf("Ingresa los elementos para el conjunto B (separados por espacios): ");
    for(i = 0; i < tamanioB; i++){
        int elemento;
        scanf("%d", &elemento);
        getchar();
        anadir(conjuntoB, elemento);
    }

    do{
        printf("\n");
        printf("--------------------------\n");
        printf("           MENU           \n");
        printf("--------------------------\n");
        printf("1.- Añadir elemento\n");
        printf("2.- Retirar elemento\n");
        printf("3.- Verificar si un elemento pertenece a un conjunto\n");
        printf("4.- Verificar si un conjunto es vacio (no tiene elementos)\n");
        printf("5.- Numero de elementos de un conjunto\n");
        printf("6.- Union\n");
        printf("7.- Interseccion\n");
        printf("8.- Inclusion\n");
        printf("9.- Salir\n");
        printf("Selecciona alguna de las opciones anteriores: ");
        scanf("%d", &opcion);
        getchar();

        switch(opcion){
            case 1:
                printf("\nIngresa el conjunto al que desea agregar un elemento ('A' para conjunto A y 'B' para conjunto B): ");
                scanf("%c", &letter);
                getchar();
                
                if(letter == 'A'){
                    printf("Ingresa el elemento a añadir: ");
                    scanf("%d", &elemento);
                    getchar();
                    anadir(conjuntoA, elemento);
                }else if(letter == 'B'){
                    printf("Ingresa el elemento a añadir: ");
                    scanf("%d", &elemento);
                    getchar();
                    anadir(conjuntoB, elemento);
                }else{
                    printf("\nConjunto no valido");
                }
                break;
            case 2:
                printf("\nIngresa el conjunto al que desea retirar un elemento ('A' para conjunto A y 'B' para conjunto B): ");
                scanf("%c", &letter);
                getchar();
                
                if(letter == 'A'){
                    printf("Ingresa el elemento a retirar: ");
                    scanf("%d", &elemento);
                    getchar();
                    retirar(conjuntoA, elemento);
                }else if(letter == 'B'){
                    printf("Ingresa el elemento a retirar: ");
                    scanf("%d", &elemento);
                    getchar();
                    retirar(conjuntoB, elemento);
                }else{
                    printf("\nConjunto no valido");
                }
                break;
            case 3:
                printf("\nIngresa el conjunto ('A' para conjunto A y 'B' para conjunto B): ");
                scanf("%c", &letter);
                getchar();

                if(letter == 'A'){
                    printf("Ingresa el elemento: ");
                    scanf("%d", &elemento);
                    getchar();
                    if(pertenece(conjuntoA, elemento)){
                        printf("\nEl elemento %d pertenece al conjunto A", elemento);
                    }else{
                        printf("\nEl elemento %d no pertenece al conjunto A", elemento);
                    }
                }else if(letter == 'B'){
                    printf("Ingresa el elemento: ");
                    scanf("%d", &elemento);
                    getchar();
                    if(pertenece(conjuntoB, elemento)){
                        printf("\nEl elemento %d pertenece al conjunto B", elemento);
                    }else{
                        printf("\nEl elemento %d no pertenece al conjunto B", elemento);
                    }
                }else{
                    printf("\nConjunto no valido");
                }
                break;
            case 4:
                printf("\nIngresa el conjunto ('A' para conjunto A y 'B' para conjunto B): ");
                scanf("%c", &letter);
                getchar();

                if(letter == 'A'){
                    if(esVacio(conjuntoA)){
                        printf("\nEl conjunto A es vacio");
                    }else{
                        printf("\nEl conjunto A no es vacio");
                    }
                }else if(letter == 'B'){
                    if(esVacio(conjuntoB)){
                        printf("\nEl conjunto B es vacio");
                    }else{
                        printf("\nEl conjunto B no es vacio");
                    }
                }else{
                    printf("\nConjunto no valido");
                }
                break;
            case 5:
                printf("\nIngresa el conjunto ('A' para conjunto A y 'B' para conjunto B): ");
                scanf("%c", &letter);
                getchar();

                if(letter == 'A'){
                    printf("\nHay %d elementos en el conjunto A", cardinal(conjuntoA));
                }else if(letter == 'B'){
                    printf("\nHay %d elementos en el conjunto B", cardinal(conjuntoB));
                }else{
                    printf("\nConjunto no valido");
                }
                break;
            case 6: ;
                CONJUNTO unionAB = unionConjuntos(conjuntoA, conjuntoB);
                printf("\nResultado de la Union: \n");
                for(i = 0; i < unionAB -> tamanio; i++){
                    if((unionAB -> elementos[i]) != 0){
                        printf("%d ", unionAB -> elementos[i]);
                    }
                }
                printf("\n");
                liberarMemoria(unionAB);
                break;
            case 7: ;
                CONJUNTO interseccionAB = interseccion(conjuntoA, conjuntoB);
                printf("\nResultado de la Interseccion: \n");
                for(i = 0; i < interseccionAB -> tamanio; i++){
                    if((interseccionAB -> elementos[i]) != 0){
                        printf("%d ", interseccionAB -> elementos[i]);
                    }
                }
                printf("\n");
                liberarMemoria(interseccionAB);
                break;
            case 8:
                if(inclusion(conjuntoA, conjuntoB)){
                    printf("\nEl conjunto A esta incluido en el conjunto B\n");
                }else{
                    printf("El conjunto A no esta incluido en el conjunto B");
                }
                break;
            case 9:
                printf("\nSaliendo . . . \n");
                liberarMemoria(conjuntoA);
                liberarMemoria(conjuntoB);
                break;
            
            default:
                printf("\nSelecciona una opcion valida . . .");
        }
    }while(opcion != 9);
}

void manejaMsg(int msg){
    char * mensajes[] = {"No hay memoria disponible . . . \n", "\nMemoria liberada . . . \n"};
    printf("%s", mensajes[msg]);
}