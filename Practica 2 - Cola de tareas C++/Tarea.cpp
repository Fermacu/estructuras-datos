#include "Tarea.h"

//Constructor
Tarea::Tarea(string descripcion, int prioridad, string encargado){
    this->descripcion = descripcion;
    // Validar que la prioridad esté entre 1 y 3
    if(prioridad >= 1 && prioridad <= 3){
        this->prioridad = prioridad;
    } else {
        this->prioridad = 1; // Valor por defecto si está fuera de rango
    }
    this->encargado = encargado;
    // Crear una nueva lista de requerimientos para esta tarea
    listaRequerimientos = new ListaRequerimientos();
}

//Destructor - Libera la memoria de la lista de requerimientos
Tarea::~Tarea(){
    if(listaRequerimientos != nullptr){
        delete listaRequerimientos;
        listaRequerimientos = nullptr;
    }
}

//Getter para descripción
string Tarea::getDescripcion(){
    return descripcion;
}

//Getter para prioridad
int Tarea::getPrioridad(){
    return prioridad;
}

//Getter para encargado
string Tarea::getEncargado(){
    return encargado;
}

//Getter para lista de requerimientos
ListaRequerimientos* Tarea::getListaRequerimientos(){
    return listaRequerimientos;
}

//Setter para descripción
void Tarea::setDescripcion(string nuevaDescripcion){
    this->descripcion = nuevaDescripcion;
}

//Setter para prioridad
void Tarea::setPrioridad(int nuevaPrioridad){
    if(nuevaPrioridad >= 1 && nuevaPrioridad <= 3){
        this->prioridad = nuevaPrioridad;
    }
}

//Setter para encargado
void Tarea::setEncargado(string nuevoEncargado){
    this->encargado = nuevoEncargado;
}

//Método para insertar un requerimiento en la lista
void Tarea::insertarRequerimiento(Requerimiento* requerimiento){
    listaRequerimientos->insertar(requerimiento);
}

