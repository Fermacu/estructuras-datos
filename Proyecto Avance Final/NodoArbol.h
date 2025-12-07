#ifndef NODOARBOL_H
#define NODOARBOL_H

#include "Producto.h"

class NodoArbol{
    //Atributos
    private:
        Producto* producto;
        NodoArbol* izquierdo;
        NodoArbol* derecho;
        int altura; // Para el balanceo AVL

    //Metodos
    public:
        //Constructor
        NodoArbol(Producto* pProducto){
            producto = pProducto;
            izquierdo = nullptr;
            derecho = nullptr;
            altura = 1; // Nueva hoja tiene altura 1
        }

        //Destructor
        ~NodoArbol(){
            delete producto;
        }

        //Getters
        Producto* getProducto();
        NodoArbol* getIzquierdo();
        NodoArbol* getDerecho();
        int getAltura();

        //Setters
        void setProducto(Producto* nuevoProducto);
        void setIzquierdo(NodoArbol* nuevoIzquierdo);
        void setDerecho(NodoArbol* nuevoDerecho);
        void setAltura(int nuevaAltura);
};

#endif



