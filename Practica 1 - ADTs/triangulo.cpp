#include "triangulo.h"
#include <cmath>
#include <iostream>
using namespace std;

//Constructor
Triangulo::Triangulo(double x1, double y1, double x2, double y2, double x3, double y3){
    this->x1 = x1; this->y1 = y1;
    this->x2 = x2; this->y2 = y2;
    this->x3 = x3; this->y3 = y3;
}

//Modificador 
void Triangulo::modificarCoordenadas(double x1, double y1, double x2, double y2, double x3, double y3){
    this->x1 = x1; this->y1 = y1;
    this->x2 = x2; this->y2 = y2;
    this->x3 = x3; this->y3 = y3;
}

//Metodos
double Triangulo::calcularDistancia(double x1, double y1, double x2, double y2){
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double Triangulo::calcularArea(){
    return 0.5 * abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));
}

double Triangulo::calcularPerimetro(){
    return calcularDistancia(x1, y1, x2, y2) + calcularDistancia(x2, y2, x3, y3) + calcularDistancia(x3, y3, x1, y1);
}

string Triangulo::determinarTipo(){
 double lado1 = calcularDistancia(x1, y1, x2, y2);
 double lado2 = calcularDistancia(x2, y2, x3, y3);
 double lado3 = calcularDistancia(x3, y3, x1, y1);

 if(lado1 == lado2 && lado2 == lado3){
    return "Equilatero";
 }
 else if(lado1 == lado2 || lado2 == lado3 || lado3 == lado1){
    return "Isosceles";
 }
 else{
    return "Escaleno";
 }
}

bool Triangulo::esTrianguloValido(){
    return calcularArea() > 0;
}

