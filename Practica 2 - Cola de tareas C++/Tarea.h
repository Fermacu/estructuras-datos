#ifndef TAREA_H
#define TAREA_H
#include "ListaRequerimientos.h"
#include <string>
using namespace std;

class Tarea{
    private:
        string descripcion;
        int prioridad;  // Clasificada del 1 al 3
        string encargado;
        ListaRequerimientos* listaRequerimientos;

    public:
        //Constructor
        Tarea(string descripcion, int prioridad, string encargado);

        //Destructor
        ~Tarea();

        //Getters
        string getDescripcion();
        int getPrioridad();
        string getEncargado();
        ListaRequerimientos* getListaRequerimientos();

        //Setters
        void setDescripcion(string nuevaDescripcion);
        void setPrioridad(int nuevaPrioridad);
        void setEncargado(string nuevoEncargado);

        //Método para insertar un requerimiento en la lista
        void insertarRequerimiento(Requerimiento* requerimiento);
};

#endif

