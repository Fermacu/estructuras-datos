#include "NodoRequerimiento.h"

Requerimiento* NodoRequerimiento::getRequerimiento(){
    return requerimiento;
}

NodoRequerimiento* NodoRequerimiento::getSiguiente(){
    return siguiente;
}

void NodoRequerimiento::setRequerimiento(Requerimiento* nuevoRequerimiento){
    requerimiento = nuevoRequerimiento;
}

void NodoRequerimiento::setSiguiente(NodoRequerimiento* nuevoSiguiente){
    siguiente = nuevoSiguiente;
}

