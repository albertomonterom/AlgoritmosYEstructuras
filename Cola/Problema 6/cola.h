#ifndef _cola_
#define _cola_
#define TAMCOLA 100
#define TRUE 1
#define FALSE 0

typedef struct{
    char nombre[20];
    char sexo;
    int edad;
    int ticket;
    int atencion;
}Persona;

typedef struct{
    Persona * cola[100];
    int primero, ultimo;
    int tam;
}Cola;

typedef Cola * COLA;
typedef Persona * PERSONA;


COLA crearCola();
int es_vaciaCola(COLA);
int sig(int);
void encolar(COLA, PERSONA);
PERSONA desencolar(COLA);
PERSONA primero(COLA);

#endif