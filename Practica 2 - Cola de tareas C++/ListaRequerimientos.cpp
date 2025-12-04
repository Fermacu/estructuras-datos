#include "ListaRequerimientos.h"

//Destructor - Libera toda la memoria dinámica
ListaRequerimientos::~ListaRequerimientos(){
    NodoRequerimiento* actual = cabeza;
    while(actual != nullptr){
        NodoRequerimiento* siguiente = actual->getSiguiente();
        delete actual->getRequerimiento(); // Liberar el requerimiento
        delete actual; // Liberar el nodo
        actual = siguiente;
    }
    cabeza = nullptr;
}

//Verifica si la lista está vacía
bool ListaRequerimientos::estaVacia(){
    return cabeza == nullptr;
}

//Inserta un requerimiento al final de la lista
void ListaRequerimientos::insertar(Requerimiento* requerimiento){
    NodoRequerimiento* nuevoNodo = new NodoRequerimiento(requerimiento);
    
    if(estaVacia()){
        cabeza = nuevoNodo;
    } else {
        NodoRequerimiento* actual = cabeza;
        // Recorrer hasta el final de la lista
        while(actual->getSiguiente() != nullptr){
            actual = actual->getSiguiente();
        }
        actual->setSiguiente(nuevoNodo);
    }
}

//Calcula la complejidad acumulada de todos los requerimientos
int ListaRequerimientos::calcularComplejidadAcumulada(){
    int suma = 0;
    NodoRequerimiento* actual = cabeza;
    while(actual != nullptr){
        suma += actual->getRequerimiento()->getComplejidad();
        actual = actual->getSiguiente();
    }
    return suma;
}

//Imprime todos los requerimientos de la lista
void ListaRequerimientos::imprimirRequerimientos(){
    if(estaVacia()){
        cout << "    No hay requerimientos." << endl;
        return;
    }
    
    NodoRequerimiento* actual = cabeza;
    int contador = 1;
    while(actual != nullptr){
        cout << "    " << contador << ". " << actual->getRequerimiento()->getDescripcion() 
             << " (Complejidad: " << actual->getRequerimiento()->getComplejidad() << ")" << endl;
        actual = actual->getSiguiente();
        contador++;
    }
}

//Método auxiliar para obtener la cabeza de la lista
NodoRequerimiento* ListaRequerimientos::getCabeza(){
    return cabeza;
}

