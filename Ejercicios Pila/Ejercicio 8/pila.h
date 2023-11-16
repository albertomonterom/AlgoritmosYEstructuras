#ifndef _pila_
#define _pila_
#define TAMPILA 100

typedef struct{
    int dia;
    int mes;
    int anio;
}Fecha;

typedef struct{
    int numero;
    char titular[20];
    char tramite[20];
    Fecha fecha;
}Expediente;

typedef Expediente * EXPEDIENTE;

typedef struct{
    EXPEDIENTE expedientes[TAMPILA];
    int tope;
}Pila;


typedef Pila * PILA;

PILA crearPila();
void apilar(PILA, EXPEDIENTE);
int es_vacia(PILA);
EXPEDIENTE desapilar(PILA);

#endif