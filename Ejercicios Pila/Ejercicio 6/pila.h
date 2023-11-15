#ifndef _pila_
#define _pila_
#define TAMPILA 10

typedef struct{
    char * productos[10];
    int tope;
}Pila;

typedef Pila * PILA;

PILA crearPila();
void apilar(PILA, char *);
int es_vacia(PILA);
char * desapilar(PILA);

#endif