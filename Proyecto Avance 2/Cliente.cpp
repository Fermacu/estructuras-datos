#include "Cliente.h"
#include <iostream>
using namespace std;

//Destructor
Cliente::~Cliente(){
    delete carritoCompras;
}

string Cliente::getNombre(){
    return nombre;
}

string Cliente::getCedula(){
    return cedula;
}

int Cliente::getPrioridad(){
    return prioridad;
}

ListaProductos* Cliente::getCarritoCompras(){
    return carritoCompras;
}

Cliente* Cliente::getSiguiente(){
    return siguiente;
}

void Cliente::setNombre(string nuevoNombre){
    nombre = nuevoNombre;
}

void Cliente::setCedula(string nuevaCedula){
    cedula = nuevaCedula;
}

void Cliente::setPrioridad(int nuevaPrioridad){
    prioridad = nuevaPrioridad;
}

void Cliente::setSiguiente(Cliente* nuevoSiguiente){
    siguiente = nuevoSiguiente;
}

void Cliente::imprimir(){
    cout << "Nombre: " << nombre << endl;
    cout << "Cedula: " << cedula << endl;
    cout << "Prioridad: " << prioridad << endl;
}

double Cliente::calcularTotal(){
    Producto* actual = carritoCompras->getPrimero();
    double total = 0.0;
    while(actual != nullptr){
        total += actual->getPrecio() * actual->getCantidad();
        actual = actual->getSiguiente();
    }
    return total;
}

