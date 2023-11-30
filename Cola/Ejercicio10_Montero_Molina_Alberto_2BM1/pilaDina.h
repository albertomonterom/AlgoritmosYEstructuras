#ifndef pilaDina
#define pilaDina

#define TRUE    1
#define FALSE  0

typedef struct Nodo_Pila{
    int dato;
    struct Nodo_Pila * anterior;
}Nodo_Pila;

typedef struct{
	Nodo_Pila * tope;
}Pila;
typedef Pila * PILA;

PILA crearPila ();
int es_vaciaPila(PILA);
Nodo_Pila * crearNodoPila();
int elemTope(PILA);
void apilar(PILA, int);
int desapilar(PILA);

#endif