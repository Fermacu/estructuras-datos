#ifndef TRIANGULO_H
#define TRIANGULO_H
#include <string>
using namespace std;

class Triangulo{
    private: 
        double x1, y1;
        double x2, y2;
        double x3, y3;

    public:
        //Constructor
        Triangulo(double x1, double y1, double x2, double y2, double x3, double y3);

        void modificarCoordenadas(double x1, double y1, double x2, double y2, double x3, double y3);

        //Metodos
        double calcularArea();

        double calcularPerimetro();

        string determinarTipo();

        bool esTrianguloValido();

        double calcularDistancia(double x1, double y1, double x2, double y2);
     
};

#endif