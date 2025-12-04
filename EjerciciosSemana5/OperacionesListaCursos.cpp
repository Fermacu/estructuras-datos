#include "ListaCursos.h"

Curso* ListaCursos::getPrimero(){
    return primero;
}

void ListaCursos::insertarInicio(string nombreNodo, 
    string seccionNodo, 
    char modalidadNodo, 
    unsigned char nivelNodo){
        Curso* nuevoNodo = new Curso(nombreNodo, seccionNodo, modalidadNodo, nivelNodo);
        nuevoNodo->setSiguiente(nuevoNodo);
        primero = nuevoNodo;
    }

Curso* ListaCursos::getUltimo(){
    Curso* nodoTemp = primero;
    if(nodoTemp == nullptr){
        cout << "La lista esta vacia.\n" << endl;
        return nodoTemp;
    }
    while(nodoTemp->getSiguiente() != nullptr){
        nodoTemp = nodoTemp->getSiguiente();
    }
    return nodoTemp;
}

void ListaCursos::insertarFinal(string nombreNodo, 
    string seccionNodo, 
    char modalidadNodo, 
    unsigned char nivelNodo){
        Curso* nuevoNodo = new Curso(nombreNodo, seccionNodo, modalidadNodo, nivelNodo);
        if(primero == nullptr){
            primero = nuevoNodo;
        }
        else{
            Curso* ultimo = this->getUltimo();
            ultimo->setSiguiente(nuevoNodo);
           
        }
    }

Curso* ListaCursos::buscar(string nombreBuscar){
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "es_ES.UTF-8");
    Curso* nodoTemp = primero;
    if(nodoTemp == nullptr){
        cout << "La lista esta vacia.\n" << endl;
        return nodoTemp;
    }
    while(nodoTemp -> getNombre() != nombreBuscar && nodoTemp->getSiguiente() != nullptr){
        nodoTemp = nodoTemp->getSiguiente();
    }
    if(nodoTemp->getNombre() == nombreBuscar){
        cout << "El curso se encontró en la lista.\n" << endl;
        return nodoTemp;
    }
    else{
        cout << "El curso no se encontró en la lista.\n" << endl;
        return nullptr;
    }
}