#ifndef _pila_
#define _pila_
#define TAMPILA 100

typedef struct{
    int pila[TAMPILA];
    int tope;
}Pila;

typedef Pila * PILA;

PILA crearPila();
void apilar(PILA, int);
int desapilar(PILA);
int es_vaciaPila(PILA);
int elemTope(PILA);

#endif