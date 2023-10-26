#include<stdlib.h>
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