#include "NodoTarea.h"

Tarea* NodoTarea::getTarea(){
    return tarea;
}

NodoTarea* NodoTarea::getSiguiente(){
    return siguiente;
}

void NodoTarea::setTarea(Tarea* nuevaTarea){
    tarea = nuevaTarea;
}

void NodoTarea::setSiguiente(NodoTarea* nuevoSiguiente){
    siguiente = nuevoSiguiente;
}

