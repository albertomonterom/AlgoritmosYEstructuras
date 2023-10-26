#include<stdlib.h>
#include "natural.h"

void manejaMsg(int);

Natural crearNatural(int entero){
    return entero;
}
int esCero(Natural natural){
    return natural == 0;
}
Natural sucesor(Natural natural){
    return natural + 1;
}
int esMenor(Natural natural1, Natural natural2){
    return natural1 < natural2;
}
int esMenorIgual(Natural natural1, Natural natural2){
    return natural1 <= natural2;
}
int esMayor(Natural natural1, Natural natural2){
    return natural1 > natural2;
}
int esMayorIgual(Natural natural1, Natural natural2){
    return natural1 >= natural2;
}
Natural predecesor(Natural natural){
    if(esCero(natural)){
        return natural;
    }else{
        return natural - 1;
    }
}