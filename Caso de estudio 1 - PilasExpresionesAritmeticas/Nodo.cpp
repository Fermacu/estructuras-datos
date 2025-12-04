#include "Nodo.h"

char Nodo::getDato(){
    return dato;
}

Nodo* Nodo::getSiguiente(){
    return siguiente;
}

void Nodo::setDato(char nuevoDato){
    dato = nuevoDato;
}

void Nodo::setSiguiente(Nodo* nuevoSiguiente){
    siguiente = nuevoSiguiente;
}

