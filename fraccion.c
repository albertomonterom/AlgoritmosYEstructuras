#include<stdlib.h>
#include "fraccion.h"

void manejaMsg(int);

FRACCION crearFraccion(void){
 FRACCION F;
   F = (FRACCION)malloc(sizeof(Fraccion));
   if( F == NULL){
         manejaMsg(0);
         exit(0);
    }
    return F;
}
void asignaNum(FRACCION F,  int n){
    F -> numerador = n;
}

void asignaDenom(FRACCION F, int d){
      F -> denominador = d;
}

int obtenNum(FRACCION F){
       return ( F -> numerador);
}

int obtenDenom(FRACCION F){
      return ( F -> denominador);
}

FRACCION producto(FRACCION F1, FRACCION F2){
      FRACCION F3 =  crearFraccion();
      asignaNum( F3, obtenNum(F1) * obtenNum(F2) );
      asignaDenom( F3, obtenDenom(F1) * obtenDenom(F2) );
      return F3;
}
FRACCION division(FRACCION F1, FRACCION F2){
      FRACCION F3 = crearFraccion();
      asignaNum(F3, (obtenNum(F1) * obtenDenom(F2)));
      asignaDenom(F3, (obtenNum(F2) * obtenDenom(F1)));
      return F3;
}
int esImpropia(FRACCION F){
      if(obtenNum(F) > obtenDenom(F)){
            return 1;
      }else{
            return 0;
      }
}
FRACCION obtenMayor(FRACCION F1, FRACCION F2){
      int n1 = obtenNum(F1) * obtenDenom(F2);
      int n2 = obtenNum(F2) * obtenDenom(F1);

      if(n1 > n2){
            return F1;
      }else{
            return F2;
      }
}