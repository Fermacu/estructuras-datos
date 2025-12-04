#ifndef REQUERIMIENTO_H
#define REQUERIMIENTO_H
#include <string>
using namespace std;

class Requerimiento{
    private:
        string descripcion;
        int complejidad;  // Valorada del 1 al 10

    public:
        //Constructor
        Requerimiento(string descripcion, int complejidad);

        //Getters
        string getDescripcion();
        int getComplejidad();

        //Setters
        void setDescripcion(string nuevaDescripcion);
        void setComplejidad(int nuevaComplejidad);
};

#endif

