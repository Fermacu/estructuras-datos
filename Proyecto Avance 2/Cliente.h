#ifndef CLIENTE_H
#define CLIENTE_H

#include "ListaProductos.h"
#include <string>
#include <iostream>
using namespace std;

class Cliente{
    //Atributos
    private:
        string nombre;
        string cedula;
        int prioridad; // 1=ordinario, 2=regular, 3=mayores/discapacitados/embarazadas
        ListaProductos* carritoCompras;
        Cliente* siguiente;

    //Metodos
    public:
        //Constructor
        Cliente(string pNombre, string pCedula, int pPrioridad){
            nombre = pNombre;
            cedula = pCedula;
            prioridad = pPrioridad;
            carritoCompras = new ListaProductos();
            siguiente = nullptr;
        }

        //Destructor
        ~Cliente();

        //Getters
        string getNombre();
        string getCedula();
        int getPrioridad();
        ListaProductos* getCarritoCompras();
        Cliente* getSiguiente();

        //Setters
        void setNombre(string nuevoNombre);
        void setCedula(string nuevaCedula);
        void setPrioridad(int nuevaPrioridad);
        void setSiguiente(Cliente* nuevoSiguiente);

        void imprimir();
        double calcularTotal();
};

#endif

