#ifndef LISTA_REQUERIMIENTOS_H
#define LISTA_REQUERIMIENTOS_H
#include "NodoRequerimiento.h"
#include <iostream>
using namespace std;

class ListaRequerimientos{
    private:
        NodoRequerimiento* cabeza;

    public:
        //Constructor
        ListaRequerimientos(){
            cabeza = nullptr;
        }

        //Destructor
        ~ListaRequerimientos();

        //Métodos principales
        void insertar(Requerimiento* requerimiento);
        
        bool estaVacia();
        
        //Método para calcular la complejidad acumulada
        int calcularComplejidadAcumulada();
        
        //Método para imprimir todos los requerimientos
        void imprimirRequerimientos();
        
        //Método auxiliar
        NodoRequerimiento* getCabeza();
};

#endif

