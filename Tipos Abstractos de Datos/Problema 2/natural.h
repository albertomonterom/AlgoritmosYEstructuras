#ifndef _natural_
#define _natural_

typedef int Natural;

//operaciones
Natural crearNatural(int);
int esCero(Natural);
Natural sucesor(Natural);
int esMenor(Natural, Natural);
int esMenorIgual(Natural, Natural);
int esMayor(Natural, Natural);
int esMayorIgual(Natural, Natural);
Natural predecesor(Natural);

#endif