#include "Producto.h"
#include <iostream>
using namespace std;

int Producto::getId(){
    return id;
}

string Producto::getNombre(){
    return nombre;
}

double Producto::getPrecio(){
    return precio;
}

int Producto::getCantidad(){
    return cantidad;
}

Producto* Producto::getSiguiente(){
    return siguiente;
}

void Producto::setId(int nuevoId){
    id = nuevoId;
}

void Producto::setNombre(string nuevoNombre){
    nombre = nuevoNombre;
}

void Producto::setPrecio(double nuevoPrecio){
    precio = nuevoPrecio;
}

void Producto::setCantidad(int nuevaCantidad){
    cantidad = nuevaCantidad;
}

void Producto::setSiguiente(Producto* nuevoSiguiente){
    siguiente = nuevoSiguiente;
}

void Producto::imprimir(){
    cout << "ID: " << id 
         << "\nNombre: " << nombre 
         << "\nPrecio: $" << precio 
         << "\nCantidad: " << cantidad << "\n" << endl;
}
