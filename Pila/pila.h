#ifndef _pila_
#define _pila_
#define TAMPILA 100
#define TRUE 1
#define FALSE 0

typedef struct{
    int pila[TAMPILA];
    int tope;
}Pila;
typedef Pila * PILA;

//operaiciones
PILA crearPila();
void apilar(PILA, int);
int es_vaciaPila(PILA);
int desapilar(PILA);
int elemTope(PILA);

#endif