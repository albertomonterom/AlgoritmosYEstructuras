#ifndef _abstracto_
#define _abstracto_

typedef struct{
    float a;
    float b;
    float c;
}Ecuacion;

typedef Ecuacion * ECUACION;

//operaciones
ECUACION crearEcuacion();
void asignaA(ECUACION, float);
void asignaB(ECUACION, float);
void asignaC(ECUACION, float);
float obtenA(ECUACION);
float obtenB(ECUACION);
float obtenC(ECUACION);
void obtenerRaices(ECUACION, float *, float *);

#endif