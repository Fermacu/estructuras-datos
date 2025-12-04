#ifndef NODO_REQUERIMIENTO_H
#define NODO_REQUERIMIENTO_H
#include "Requerimiento.h"

class NodoRequerimiento{
    private:
        Requerimiento* requerimiento;
        NodoRequerimiento* siguiente;

    public:
        //Constructor
        NodoRequerimiento(Requerimiento* pRequerimiento){
            requerimiento = pRequerimiento;
            siguiente = nullptr;
        }

        //Getters
        Requerimiento* getRequerimiento();
        NodoRequerimiento* getSiguiente();

        //Setters
        void setRequerimiento(Requerimiento* nuevoRequerimiento);
        void setSiguiente(NodoRequerimiento* nuevoSiguiente);
};

#endif

