#ifndef COLA_TAREAS_H
#define COLA_TAREAS_H
#include "NodoTarea.h"
#include <iostream>
using namespace std;

class ColaTareas{
    private:
        NodoTarea* frente;
        NodoTarea* final;

    public:
        //Constructor
        ColaTareas(){
            frente = nullptr;
            final = nullptr;
        }

        //Destructor
        ~ColaTareas();

        //Métodos principales
        void insertar(Tarea* tarea);
        
        void eliminarTareaPrioridad();  // Elimina la tarea con mayor prioridad
        
        bool estaVacia();
        
        //Método para generar el reporte de una tarea
        void generarReporte(Tarea* tarea);
};

#endif

