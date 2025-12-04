#include "Requerimiento.h"

//Constructor
Requerimiento::Requerimiento(string descripcion, int complejidad){
    this->descripcion = descripcion;
    // Validar que la complejidad esté entre 1 y 10
    if(complejidad >= 1 && complejidad <= 10){
        this->complejidad = complejidad;
    } else {
        this->complejidad = 1; // Valor por defecto si está fuera de rango
    }
}

//Getter para descripción
string Requerimiento::getDescripcion(){
    return descripcion;
}

//Getter para complejidad
int Requerimiento::getComplejidad(){
    return complejidad;
}

//Setter para descripción
void Requerimiento::setDescripcion(string nuevaDescripcion){
    this->descripcion = nuevaDescripcion;
}

//Setter para complejidad
void Requerimiento::setComplejidad(int nuevaComplejidad){
    if(nuevaComplejidad >= 1 && nuevaComplejidad <= 10){
        this->complejidad = nuevaComplejidad;
    }
}

