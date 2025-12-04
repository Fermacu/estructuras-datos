#ifndef FECHA_HORA_H
#define FECHA_HORA_H
#include <string>
using namespace std;

class FechaHora{
    private:
    int dia, mes, anio;
    int hora, minuto, segundo;

    public:
    //Constructir
    FechaHora(int dia, int mes, int anio, int hora, int minuto, int segundo);

    //Modificador
    void modificarFechaHora(int dia, int mes, int anio, int hora, int minuto, int segundo);

    //Metodos
    string obtenerDiaSemana(); // Sirve para obtener el dia de la semana
    int diasEntreFechas(FechaHora fecha); // Sirve para calcular la diferencia de dias entre dos fechas
    string formatearFechaHora(); // Sirve para formatear la fecha y hora
    bool esFechaValida(); // Sirve para verificar si la fecha es valida

    bool esBisiesto(int anio); // Sirve para verificar si el anio es bisiesto
    int diasEnMes(int mes, int anio); // Sirve para obtener los dias en un mes
};

#endif