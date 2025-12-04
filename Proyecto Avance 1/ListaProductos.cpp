#include "ListaProductos.h"
#include <iostream>
using namespace std;

//Destructor - Libera toda la memoria dinámica
ListaProductos::~ListaProductos(){
    Producto* actual = primero;
    while(actual != nullptr){
        Producto* siguiente = actual->getSiguiente();
        delete actual;
        actual = siguiente;
    }
}

Producto* ListaProductos::getPrimero(){
    return primero;
}

Producto* ListaProductos::getUltimo(){
    Producto* nodoTemp = primero;
    if(nodoTemp == nullptr){
        cout << "La lista esta vacia.\n" << endl;
        return nodoTemp;
    }
    while(nodoTemp->getSiguiente() != nullptr){
        nodoTemp = nodoTemp->getSiguiente();
    }
    return nodoTemp;
}

bool ListaProductos::validarIdUnico(int id){
    Producto* actual = primero;
    while(actual != nullptr){
        if(actual->getId() == id){
            cout << "Error: El ID " << id << " ya existe en la lista.\n" << endl;
            return false;
        }
        actual = actual->getSiguiente();
    }
    return true;
}

void ListaProductos::insertarFinal(int id, string nombre, double precio, int cantidad){
    //Validar que el ID sea único
    if(!validarIdUnico(id)){
        return;
    }
    
    Producto* nuevoProducto = new Producto(id, nombre, precio, cantidad);
    if(primero == nullptr){
        primero = nuevoProducto;
    }
    else{
        Producto* ultimo = this->getUltimo();
        ultimo->setSiguiente(nuevoProducto);
    }
    cout << "Producto agregado exitosamente.\n" << endl;
}

Producto* ListaProductos::buscar(string nombreBuscar){
    Producto* nodoTemp = primero;
    if(nodoTemp == nullptr){
        cout << "La lista esta vacia.\n" << endl;
        return nodoTemp;
    }
    while(nodoTemp != nullptr && nodoTemp->getNombre() != nombreBuscar){
        nodoTemp = nodoTemp->getSiguiente();
    }
    if(nodoTemp != nullptr && nodoTemp->getNombre() == nombreBuscar){
        cout << "El producto se encontro en la lista.\n" << endl;
        return nodoTemp;
    }
    else{
        cout << "El producto no se encontro en la lista.\n" << endl;
        return nullptr;
    }
}

Producto* ListaProductos::eliminar(string nombreEliminar){
    if(primero == nullptr){
        cout << "La lista esta vacia.\n" << endl;
        return nullptr;
    }
    
    Producto* actual = primero;
    Producto* anterior = nullptr;
    
    //Buscar el producto a eliminar
    while(actual != nullptr && actual->getNombre() != nombreEliminar){
        anterior = actual;
        actual = actual->getSiguiente();
    }
    
    if(actual == nullptr){
        cout << "El producto no se encontro en la lista.\n" << endl;
        return nullptr;
    }
    
    //Eliminar el producto
    if(anterior == nullptr){
        //Eliminar el primer elemento
        primero = actual->getSiguiente();
    }
    else{
        //Eliminar elemento del medio o final
        anterior->setSiguiente(actual->getSiguiente());
    }
    
    cout << "Producto eliminado exitosamente.\n" << endl;
    return actual;
}

void ListaProductos::imprimir(){
    Producto* actual = primero;
    if(actual == nullptr){
        cout << "La lista esta vacia.\n" << endl;
        return;
    }
    
    cout << "=== LISTA DE PRODUCTOS ===" << endl;
    int contador = 1;
    while(actual != nullptr){
        cout << "Producto " << contador << ":" << endl;
        actual->imprimir();
        actual = actual->getSiguiente();
        contador++;
    }
}
