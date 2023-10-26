#ifndef _conjunto_
#define _conjunto_

typedef struct {
    int * elementos;
    int tamanio;
}Conjunto;

typedef Conjunto * CONJUNTO;

//operaciones
CONJUNTO conjuntoVacio(int);
void anadir(CONJUNTO, int);
void retirar(CONJUNTO, int);
int pertenece(CONJUNTO, int);
int esVacio(CONJUNTO);
int cardinal(CONJUNTO);
CONJUNTO unionConjuntos(CONJUNTO, CONJUNTO);
CONJUNTO interseccion(CONJUNTO, CONJUNTO);
int inclusion(CONJUNTO, CONJUNTO);
void liberarMemoria(CONJUNTO);


#endif
