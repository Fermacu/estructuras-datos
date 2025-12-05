#ifndef NODO_H
#define NODO_H

class Nodo{
    //Atributos
    private:
        char dato;
        Nodo* siguiente;

    //Metodos
    public:
        //Constructor
        Nodo(char pDato){
            dato = pDato;
            siguiente = nullptr;
        }

        //Getters
        char getDato();
        Nodo* getSiguiente();

        //Setters
        void setDato(char nuevoDato);
        void setSiguiente(Nodo* nuevoSiguiente);
};

#endif

