#include<stdlib.h>
#include<math.h>
#include "abstracto.h"

ECUACION crearEcuacion(){
    ECUACION ecuacion;
    
    ecuacion = (ECUACION) malloc(sizeof(Ecuacion));
    
    if(ecuacion == NULL){
        manejaMsg(0);
        exit(0);
    }
    return ecuacion;
}
void asignaA(ECUACION ecuacion, float a){
    ecuacion -> a = a;
}
void asignaB(ECUACION ecuacion, float b){
    ecuacion -> b = b;
}
void asignaC(ECUACION ecuacion, float c){
    ecuacion -> c = c;
}
float obtenA(ECUACION ecuacion){
    return ecuacion -> a;
}
float obtenB(ECUACION ecuacion){
    return ecuacion -> b;
}
float obtenC(ECUACION ecuacion){
    return ecuacion -> c;
}
void obtenerRaices(ECUACION ecuacion, float * x1, float * x2){
    float discriminante = pow((ecuacion -> b), 2) - (4 * (ecuacion -> a) * (ecuacion -> c));

    if(discriminante >= 0){
        *x1 = ((-ecuacion -> b) + sqrt(discriminante)) / (2 * ecuacion -> a);
        *x2 = ((ecuacion -> b) - sqrt(discriminante)) / (2 * ecuacion -> a);
    }else{
        float real = (-ecuacion -> b) / (2 * ecuacion -> a);
        float imaginaria = sqrt(-discriminante) / (2 * ecuacion -> a);
        *x1 = real + imaginaria;
        *x2 = real + imaginaria;
    }
}