#ifndef _pila_
#define _pila_
#define TAMPILA 100

typedef struct{
    char cadena[TAMPILA];
    int tope;
}Pila;

typedef Pila * PILA;

PILA crearPila();
void apilar(PILA, char);
int es_vacia(PILA);
char desapilar(PILA);

#endif