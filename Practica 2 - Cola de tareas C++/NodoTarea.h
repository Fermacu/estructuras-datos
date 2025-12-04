#ifndef NODO_TAREA_H
#define NODO_TAREA_H
#include "Tarea.h"

class NodoTarea{
    private:
        Tarea* tarea;
        NodoTarea* siguiente;

    public:
        //Constructor
        NodoTarea(Tarea* pTarea){
            tarea = pTarea;
            siguiente = nullptr;
        }

        //Getters
        Tarea* getTarea();
        NodoTarea* getSiguiente();

        //Setters
        void setTarea(Tarea* nuevaTarea);
        void setSiguiente(NodoTarea* nuevoSiguiente);
};

#endif

