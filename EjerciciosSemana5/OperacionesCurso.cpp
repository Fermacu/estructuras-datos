#include "Curso.h"
using namespace std;

string Curso::getNombre(){
    return nombre;
}

string Curso::getSeccion(){
    return seccion;
}

char Curso::getModalidad(){
    return modalidad;
}

unsigned char Curso::getNivel(){
    return nivel;
}

Curso* Curso::getSiguiente(){
    return siguiente;
}

void Curso::setNombre(string nuevoNombre){
    nombre = nuevoNombre;
}

void Curso::setSeccion(string nuevoSeccion){
    seccion = nuevoSeccion;
}

void Curso::setModalidad(char nuevoModalidad){
    modalidad = nuevoModalidad;
}

void Curso::setNivel(unsigned char nuevoNivel){
    nivel = nuevoNivel;
}

void Curso::setSiguiente(Curso* nuevoSiguiente){
    siguiente = nuevoSiguiente;
}

void Curso::imprimir(){
SetConsoleOutputCP(CP_UTF8);
setLocale(LC_ALL, "es_ES.UTF-8");
cout << "Nombre: " << nombre <<     
     << "\nSeccion: " << seccion <<
     << "\nModalidad: " << modalidad <<
     << "\nNivel: " << nivel << "\n" << endl;

}