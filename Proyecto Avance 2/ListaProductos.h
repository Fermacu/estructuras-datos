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
        Producto* buscar(int idBuscar);

        Producto* eliminar(string nombreEliminar);

        void imprimir();

        //Métodos auxiliares
        Producto* getPrimero();

        Producto* getUltimo();

        bool validarIdUnico(int id);

        int obtenerTamanio();

        //Métodos de conversión para ordenamiento y búsqueda
        Producto** convertirAArreglo(int& tamanio);
        void reconstruirDesdeArreglo(Producto** arreglo, int tamanio);

        //Métodos de ordenamiento
        // atributo: 1=id, 2=nombre, 3=precio, 4=cantidad
        // orden: true=ascendente, false=descendente
        void ordenarPorSeleccion(int atributo, bool ascendente);
        void ordenarPorMezcla(int atributo, bool ascendente);

        //Métodos de búsqueda
        // atributo: 1=id, 2=nombre, 3=precio, 4=cantidad
        Producto* busquedaLineal(int atributo, string valorBuscar);
        Producto* busquedaLineal(int atributo, int valorBuscar);
        Producto* busquedaLineal(int atributo, double valorBuscar);
        Producto* busquedaBinaria(int atributo, string valorBuscar);
        Producto* busquedaBinaria(int atributo, int valorBuscar);
        Producto* busquedaBinaria(int atributo, double valorBuscar);
        bool estaOrdenada(int atributo);

    private:
        //Métodos privados auxiliares para ordenamiento
        int& obtenerContadorComparaciones();
        bool compararProductos(Producto* p1, Producto* p2, int atributo, bool ascendente);
        bool compararProductosSinContar(Producto* p1, Producto* p2, int atributo, bool ascendente);
        void merge(Producto** arreglo, int izquierda, int medio, int derecha, int atributo, bool ascendente);
        void mergeSortRecursivo(Producto** arreglo, int izquierda, int derecha, int atributo, bool ascendente);
        
        //Variable estática para contador de comparaciones
        static int contadorComparaciones;
    };

#endif
