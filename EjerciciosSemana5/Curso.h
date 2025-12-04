#ifndef CURSO_H
#define CURSO_H
#include <string>
using namespace std;

class Curso{

    //Atributos
    private: 
        string nombre;
        string seccion;
        char modalidad;
        unsigned char nivel;
        Curso* siguiente;

    //Metodos
    public:
        //Constructor
        Curso(string pNombre, string pSeccion, char pModalidad, unsigned char pNivel){
            nombre = pNombre;
            seccion = pSeccion;
            modalidad = pModalidad;
            nivel = pNivel;
            siguiente = nullptr;
        }

        //Getters
        string getNombre();
        string getSeccion();
        char getModalidad();
        unsigned char getNivel();
        Curso* getSiguiente();

        //Setters
        void setNombre(string nuevoNombre);
        void setSeccion(string nuevoSeccion);
        void setModalidad(char nuevoModalidad);
        void setNivel(unsigned char nuevoNivel);
        void setSiguiente(Curso* nuevoSiguiente);

        void imprimir();
};
#endif