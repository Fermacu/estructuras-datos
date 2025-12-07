#ifndef ARBOLPRODUCTOS_H
#define ARBOLPRODUCTOS_H

#include "NodoArbol.h"
#include <iostream>
using namespace std;

class ArbolProductos{
    //Atributos
    private:
        NodoArbol* raiz;

    //Metodos
    public:
        //Constructor
        ArbolProductos(){
            raiz = nullptr;
        }

        //Destructor
        ~ArbolProductos();

        //Métodos principales
        void insertar(int id, string nombre, double precio, int cantidad);
        Producto* buscar(int id);
        Producto* buscar(string nombre);
        bool eliminar(int id);
        void imprimir();
        bool estaVacio();

        //Métodos auxiliares para compatibilidad con el código existente
        Producto* getPrimero(); // Retorna el producto con menor ID (para compatibilidad)
        bool validarIdUnico(int id); // Verifica si el ID ya existe

    private:
        //Métodos privados para balanceo AVL
        int obtenerAltura(NodoArbol* nodo);
        int obtenerBalance(NodoArbol* nodo);
        NodoArbol* rotacionDerecha(NodoArbol* y);
        NodoArbol* rotacionIzquierda(NodoArbol* x);
        NodoArbol* insertarRecursivo(NodoArbol* nodo, int id, string nombre, double precio, int cantidad);
        NodoArbol* buscarRecursivoPorId(NodoArbol* nodo, int id);
        Producto* buscarRecursivoPorNombre(NodoArbol* nodo, string nombre);
        NodoArbol* eliminarRecursivo(NodoArbol* nodo, int id);
        NodoArbol* obtenerMinimo(NodoArbol* nodo);
        void imprimirRecursivo(NodoArbol* nodo);
        void liberarArbol(NodoArbol* nodo);
        Producto* obtenerMinimoProducto(NodoArbol* nodo);
};

#endif



