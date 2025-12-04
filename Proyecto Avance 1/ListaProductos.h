#ifndef LISTAPRODUCTOS_H
#define LISTAPRODUCTOS_H

#include "Producto.h"

class ListaProductos{

    //Atributos
    private:
        Producto* primero;

    //Metodos
    public:
        //Constructor
        ListaProductos(){
            primero = nullptr;
        }

        //Destructor
        ~ListaProductos();

        //Métodos principales requeridos
        void insertarFinal(int id, string nombre, double precio, int cantidad);
        
        Producto* buscar(string nombreBuscar);

        Producto* eliminar(string nombreEliminar);

        void imprimir();

        //Métodos auxiliares
        Producto* getPrimero();

        Producto* getUltimo();

        bool validarIdUnico(int id);

    };

#endif
