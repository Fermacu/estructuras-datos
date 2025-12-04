#include "fecha_hora.h"
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

// Constructor
FechaHora::FechaHora(int dia, int mes, int anio, int hora, int minuto, int segundo) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
    this->hora = hora;
    this->minuto = minuto;
    this->segundo = segundo;
}

// Modificador
void FechaHora::modificarFechaHora(int dia, int mes, int anio, int hora, int minuto, int segundo) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
    this->hora = hora;
    this->minuto = minuto;
    this->segundo = segundo;
}

//  verificar si un año es bisiesto
bool FechaHora::esBisiesto(int anio) {
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

// obtener días en un mes
int FechaHora::diasEnMes(int mes, int anio) {
    int dias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (mes == 2 && esBisiesto(anio)) {
        return 29;
    }
    return dias[mes - 1];
}

// Validar la fecha
bool FechaHora::esFechaValida() {
    if (anio < 1) return false;
    
    if (mes < 1 || mes > 12) return false;
    
    if (dia < 1 || dia > diasEnMes(mes, anio)) return false;
    
    if (hora < 0 || hora > 23) return false;
    
    if (minuto < 0 || minuto > 59) return false;
    
    if (segundo < 0 || segundo > 59) return false;
    
    return true;
}

// Obtener día de la semana
string FechaHora::obtenerDiaSemana() {
    int d = dia;
    int m = mes;
    int y = anio;
    
    // Ajuste para enero y febrero
    if (m < 3) {
        m += 12;
        y--;
    }
    
    int k = y % 100;
    int j = y / 100;
    
    int diaSemana = (d + (13 * (m + 1)) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
    
    string dias[] = {"Sabado", "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes"};
    return dias[diaSemana];
}

// Calcular días entre fechas
int FechaHora::diasEntreFechas(FechaHora otraFecha) {

    int dias1 = dia;
    for (int i = 1; i < mes; i++) {
        dias1 += diasEnMes(i, anio);
    }
    for (int i = 1; i < anio; i++) {
        dias1 += esBisiesto(i) ? 366 : 365;
    }
    
    int dias2 = otraFecha.dia;
    for (int i = 1; i < otraFecha.mes; i++) {
        dias2 += diasEnMes(i, otraFecha.anio);
    }
    for (int i = 1; i < otraFecha.anio; i++) {
        dias2 += esBisiesto(i) ? 366 : 365;
    }
    
    return abs(dias1 - dias2);
}

// Formatear fecha y hora
string FechaHora::formatearFechaHora() {
    stringstream ss;
    ss << setfill('0') << setw(2) << dia << "/" 
       << setw(2) << mes << "/" 
       << setw(4) << anio << " "
       << setw(2) << hora << ":" 
       << setw(2) << minuto << ":" 
       << setw(2) << segundo;
    return ss.str();
}
