#include "NodoArbol.h"

Producto* NodoArbol::getProducto(){
    return producto;
}

NodoArbol* NodoArbol::getIzquierdo(){
    return izquierdo;
}

NodoArbol* NodoArbol::getDerecho(){
    return derecho;
}

int NodoArbol::getAltura(){
    return altura;
}

void NodoArbol::setProducto(Producto* nuevoProducto){
    producto = nuevoProducto;
}

void NodoArbol::setIzquierdo(NodoArbol* nuevoIzquierdo){
    izquierdo = nuevoIzquierdo;
}

void NodoArbol::setDerecho(NodoArbol* nuevoDerecho){
    derecho = nuevoDerecho;
}

void NodoArbol::setAltura(int nuevaAltura){
    altura = nuevaAltura;
}



