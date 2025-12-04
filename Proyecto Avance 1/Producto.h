#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>
#include <iostream>
using namespace std;

class Producto{

    //Atributos
    private: 
        int id;
        string nombre;
        double precio;
        int cantidad;
        Producto* siguiente;

    //Metodos
    public:
        //Constructor
        Producto(int pId, string pNombre, double pPrecio, int pCantidad){
            id = pId;
            nombre = pNombre;
            precio = pPrecio;
            cantidad = pCantidad;
            siguiente = nullptr;
        }

        //Getters
        int getId();
        string getNombre();
        double getPrecio();
        int getCantidad();
        Producto* getSiguiente();

        //Setters
        void setId(int nuevoId);
        void setNombre(string nuevoNombre);
        void setPrecio(double nuevoPrecio);
        void setCantidad(int nuevaCantidad);
        void setSiguiente(Producto* nuevoSiguiente);

        void imprimir();
};
#endif
