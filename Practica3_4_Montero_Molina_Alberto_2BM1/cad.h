#ifndef  _complejo_
#define  _complejo_

typedef struct{
    char * cad;
    int tam;
}Cadena;

typedef Cadena * CADENA;

//operaciones
CADENA crearCadena(int);
char obtenComponente(CADENA, int);
void ponComponente(CADENA, int, char);
int tamanio(CADENA);

#endif