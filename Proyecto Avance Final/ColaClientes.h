#ifndef COLACLIENTES_H
#define COLACLIENTES_H

#include "Cliente.h"
#include <iostream>
using namespace std;

class ColaClientes{
    //Atributos
    private:
        Cliente* frente;
        Cliente* final;

    //Metodos
    public:
        //Constructor
        ColaClientes(){
            frente = nullptr;
            final = nullptr;
        }

        //Destructor
        ~ColaClientes();

        //Métodos principales
        void insertar(Cliente* cliente);
        
        Cliente* eliminar();
        
        bool estaVacia();

        Cliente* buscarPorCedula(string cedula);
};

#endif

