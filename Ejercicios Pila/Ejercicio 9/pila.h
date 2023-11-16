#ifndef _pila_
#define _pila_
#define TAMPILA 10

typedef struct{
    int pila[TAMPILA];
    int tope;
}Pila;

typedef Pila * PILA;

PILA crearPila();
void apilar(PILA, int);
int es_vacia(PILA);
int desapilar(PILA);

#endif