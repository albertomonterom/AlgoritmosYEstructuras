#ifndef _cola_
#define _cola_
#define TAMCOLA 100
#define TRUE 1
#define FALSE 0

typedef struct{
    int num_cliente;
    char nombre[20];
    int estado;
    int monto;
}Cliente;

typedef struct{
    Cliente * cola[TAMCOLA];
    int primero, ultimo;
    int tam;
}Cola;

typedef Cola * COLA;
typedef Cliente * CLIENTE;

COLA crearCola();
int es_vaciaCola(COLA);
int sig(int);
void encolar(COLA, CLIENTE);
CLIENTE desencolar(COLA);
CLIENTE primero(COLA);

#endif