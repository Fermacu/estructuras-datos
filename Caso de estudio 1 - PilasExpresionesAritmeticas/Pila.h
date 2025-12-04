#ifndef PILA_H
#define PILA_H

#include "Nodo.h"
#include <iostream>
using namespace std;

class Pila{
    //Atributos
    private:
        Nodo* tope;

    //Metodos
    public:
        //Constructor
        Pila(){
            tope = nullptr;
        }

        //Destructor
        ~Pila();

        //Métodos principales de la pila
        void push(char dato);
        
        char pop();
        
        char peek();
        
        bool estaVacia();

        //Método auxiliar
        Nodo* getTope();
};

#endif

