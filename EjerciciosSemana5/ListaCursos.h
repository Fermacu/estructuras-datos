#ifndef LISTACURSOS_H
#define LISTACURSOS_H

#include "Curso.h"

class ListaCursos{

    //Atributos
    private:
        Curso* primero;

    //Metodos
    public:
        //Constructor
        ListaCursos(){
            primero = nullptr;
        }

        //Destructor
        ~ListaCursos();

        Curso* getPrimero();

        void insertarInicio(string nombreNodo, string seccionNodo, char modalidadNodo, unsigned char nivelNodo);
        
        Curso* getUltimo();

        void insertarFinal(string nombreNodo, string seccionNodo, char modalidadNodo, unsigned char nivelNodo);

        Curso* buscar(string nombreBuscar);

        Curso* eliminar(string nombreEliminar);

        void imprimir();

    }

#endif