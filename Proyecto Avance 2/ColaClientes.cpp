#include "ColaClientes.h"
#include <iostream>
using namespace std;

//Destructor - Libera toda la memoria dinámica
ColaClientes::~ColaClientes(){
    while(!estaVacia()){
        Cliente* clienteEliminado = eliminar();
        delete clienteEliminado;
    }
}

//Verifica si la cola está vacía
bool ColaClientes::estaVacia(){
    return frente == nullptr;
}

//Busca un cliente por cédula
Cliente* ColaClientes::buscarPorCedula(string cedula){
    Cliente* actual = frente;
    while(actual != nullptr){
        if(actual->getCedula() == cedula){
            return actual;
        }
        actual = actual->getSiguiente();
    }
    return nullptr;
}

//Inserta un cliente en la cola de prioridad
//Menor número de prioridad = mayor prioridad (1 es mayor que 3)
void ColaClientes::insertar(Cliente* cliente){
    if(estaVacia()){
        frente = cliente;
        final = cliente;
        cliente->setSiguiente(nullptr);
        return;
    }

    // Si el nuevo cliente tiene mayor prioridad que el frente (prioridad menor)
    if(cliente->getPrioridad() < frente->getPrioridad()){
        cliente->setSiguiente(frente);
        frente = cliente;
        return;
    }

    // Buscar la posición correcta según prioridad
    Cliente* actual = frente;
    Cliente* anterior = nullptr;

    while(actual != nullptr && actual->getPrioridad() <= cliente->getPrioridad()){
        anterior = actual;
        actual = actual->getSiguiente();
    }

    // Insertar en la posición encontrada
    if(anterior != nullptr){
        anterior->setSiguiente(cliente);
    }
    cliente->setSiguiente(actual);

    // Si se inserta al final, actualizar el puntero final
    if(actual == nullptr){
        final = cliente;
    }
}

//Elimina el cliente con mayor prioridad (menor número)
Cliente* ColaClientes::eliminar(){
    if(estaVacia()){
        cout << "Error: La cola de clientes esta vacia." << endl;
        return nullptr;
    }

    Cliente* clienteEliminado = frente;
    frente = frente->getSiguiente();
    
    if(frente == nullptr){
        final = nullptr;
    }

    clienteEliminado->setSiguiente(nullptr);
    return clienteEliminado;
}

