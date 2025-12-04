#include "Pila.h"
#include <iostream>
using namespace std;

//Destructor - Libera toda la memoria dinámica
//Complejidad: O(n) donde n es el número de elementos en la pila
//Explicación: Debe recorrer todos los elementos para liberar la memoria de cada nodo
Pila::~Pila(){
    while(!estaVacia()){
        pop();
    }
}

//Método auxiliar para obtener el tope de la pila
//Complejidad: O(1) - Tiempo constante
//Explicación: Acceso directo al puntero tope sin recorrer la pila
Nodo* Pila::getTope(){
    return tope;
}

//Verifica si la pila está vacía
//Complejidad: O(1) - Tiempo constante
//Explicación: Solo verifica si el puntero tope es nullptr, operación de comparación directa
bool Pila::estaVacia(){
    return tope == nullptr;
}

//Inserta un elemento en el tope de la pila (push)
//Complejidad: O(1) - Tiempo constante
//Explicación: La inserción siempre ocurre al inicio (tope), sin necesidad de recorrer
//la pila. Solo se crean enlaces entre el nuevo nodo y el tope anterior.
void Pila::push(char dato){
    Nodo* nuevoNodo = new Nodo(dato);
    nuevoNodo->setSiguiente(tope);
    tope = nuevoNodo;
}

//Elimina y retorna el elemento del tope de la pila (pop)
//Complejidad: O(1) - Tiempo constante
//Explicación: La eliminación siempre ocurre en el tope, sin recorrer la pila.
//Solo se actualiza el puntero tope y se libera el nodo eliminado.
char Pila::pop(){
    if(estaVacia()){
        cout << "Error: La pila esta vacia.\n" << endl;
        return '\0';
    }
    
    Nodo* nodoTemp = tope;
    char datoEliminado = nodoTemp->getDato();
    tope = tope->getSiguiente();
    delete nodoTemp;
    
    return datoEliminado;
}

//Consulta el elemento del tope sin eliminarlo (peek/top)
//Complejidad: O(1) - Tiempo constante
//Explicación: Solo accede al dato del nodo en el tope, sin modificar la estructura
//ni recorrer elementos adicionales.
char Pila::peek(){
    if(estaVacia()){
        cout << "Error: La pila esta vacia.\n" << endl;
        return '\0';
    }
    return tope->getDato();
}

