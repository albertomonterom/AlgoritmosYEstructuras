#ifndef _vector_
#define _vector_

typedef struct{
    int * datos;
    int tamanio;
}Vector;

typedef Vector * VECTOR;

//operaciones
VECTOR crearVector(int);
int obtenComponente(VECTOR, int);
void asignaComponente(VECTOR, int, int);
VECTOR sumaVector(VECTOR, VECTOR);
VECTOR restaVector(VECTOR, VECTOR);
int productoPunto(VECTOR, VECTOR);
int esMayorQue(int, int);
VECTOR ordenaVector(VECTOR);

#endif