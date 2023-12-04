#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cola.h"

void manejaMsg(int);
void liberarMemoria(COLA);
void leerDatos(COLA);
void mostrar(COLA, int);
void datos(COLA);
int estadof();
CLIENTE crearCliente();
COLA colaMayores(COLA, int);
float calcularProm(COLA C);

void main(){
    int cantidad;
    float promedio;
    COLA C, mayores;
    C = crearCola();
    leerDatos(C);
    //Mostrar clientes con montos mayores a una cantidad especifica
    printf("\nIngrese la cantidad para filtrar los depositos mayores: ");
    scanf("%d", &cantidad);
    getchar();
    mayores = colaMayores(C, cantidad);
    mostrar(mayores, cantidad);
    promedio = calcularProm(mayores);
    printf("\nMonto promedio de depositos: %.2f", promedio);
}
float calcularProm(COLA C){
    int count = 0, tam = C -> tam;
    while(!es_vaciaCola(C)){
        count += desencolar(C) -> monto;
    }
    return count / tam;
}
void leerDatos(COLA C){
    int opcion;
    printf("Introduzca los datos de un cliente\n");
    datos(C);
    do{
        printf("¿Desea introducir otro cliente?: (1: Si, 0: No): ");
        scanf("%d", &opcion);
        getchar();

        switch(opcion){
            case 1:
                datos(C);
                break;
            case 0:
                break;
            default:
                printf("\nOpcion no valida\n");
        }
    }while(opcion != 0);
}
COLA colaMayores(COLA C, int cantidad){
    COLA M = crearCola();
    CLIENTE v;
    while(!es_vaciaCola(C)){
        v = desencolar(C);
        if((v -> monto) >= cantidad){
            encolar(M, v);
        }
    }
    return M;
}
void mostrar(COLA C, int monto){
    printf("\nClientes con depositos mayores a %d: ", monto);
    CLIENTE v;
    while(!es_vaciaCola(C)){
        v = desencolar(C);
        printf("\n");
        printf("Numero del cliente: %d\n", v -> num_cliente);
        printf("Nombre: %s\n", v -> nombre);
        printf("Estado: %d\n", v -> estado);
        printf("Monto del deposito: %d\n", v -> monto);
    }
}
CLIENTE crearCliente(){
    CLIENTE v;

    v = (CLIENTE) malloc(sizeof(Cliente));

    if(v == NULL){
        manejaMsg(0);
        exit(0);
    }
    return v;
}
void datos(COLA C){
    CLIENTE v;
    v = crearCliente();
    encolar(C, v);
    printf("\n");
    //Nombre
    printf("Ingresa el nombre: ");
    scanf("%[^\n]", C -> cola[C -> tam - 1] -> nombre);
    getchar();
    //Estado
    C -> cola[C -> tam - 1] -> estado = estadof();
    //Cliente
    C -> cola[C -> tam - 1] -> num_cliente = C -> tam;
    //Monto
    printf("Ingresa el monto del deposito: ");
    scanf("%d", &C -> cola[C -> tam - 1] -> monto);
    getchar();
}
int estadof(){
    srand(time(NULL));
    return rand() % 2;
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