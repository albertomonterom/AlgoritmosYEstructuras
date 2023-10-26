#include <stdio.h>
#ifndef  _complejo_
#define  _complejo_

typedef struct{
    float real;
    float imaginario;
}Complejo;

typedef Complejo * COMPLEJO;

//operaciones
COMPLEJO crearComplejo(void);
void asignaReal(COMPLEJO, float);
void asignaImaginario(COMPLEJO, float);
float obtenReal(COMPLEJO);
float obtenImaginario(COMPLEJO);
COMPLEJO suma(COMPLEJO, COMPLEJO);
COMPLEJO resta(COMPLEJO, COMPLEJO);
COMPLEJO multiplicacion(COMPLEJO, COMPLEJO);
COMPLEJO division(COMPLEJO, COMPLEJO);

#endif