#include "triangulo.h"
#include "fecha_hora.h"
#include <iostream>
using namespace std;

int main() {
    int opcion;
    
    cout << "=== MENU DE ADTs ===" << endl;
    cout << "1. Probar ADT Triangulo" << endl;
    cout << "2. Probar ADT Fecha_Hora" << endl;
    cout << "3. Salir" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    
    switch(opcion) {
        case 1: {
            // ADT Triangulo
            double x1, y1, x2, y2, x3, y3;
            
            cout << "\n=== CALCULADORA DE TRIANGULOS ===" << endl;
            cout << "Ingrese las coordenadas de los 3 vertices del triangulo:" << endl;
            
            cout << "Punto 1 (x1, y1): ";
            cin >> x1 >> y1;
            
            cout << "Punto 2 (x2, y2): ";
            cin >> x2 >> y2;
            
            cout << "Punto 3 (x3, y3): ";
            cin >> x3 >> y3;
            
            // Construictor del triángulo
            Triangulo miTriangulo(x1, y1, x2, y2, x3, y3);
            
            cout << "\n=== RESULTADOS ===" << endl;
            cout << "Coordenadas ingresadas:" << endl;
            cout << "Punto 1: (" << x1 << ", " << y1 << ")" << endl;
            cout << "Punto 2: (" << x2 << ", " << y2 << ")" << endl;
            cout << "Punto 3: (" << x3 << ", " << y3 << ")" << endl;
            
            // Validacion para el triangulo
            if (miTriangulo.esTrianguloValido()) {
                cout << "\n El triangulo es VALIDO" << endl;
                
                // Mostrar resultados
                cout << "Area: " << miTriangulo.calcularArea() << endl;
                cout << "Perimetro: " << miTriangulo.calcularPerimetro() << endl;
                cout << "Tipo: " << miTriangulo.determinarTipo() << endl;
                
            } else {
                cout << "\n El triangulo NO es VALIDO" << endl;
                cout << "Los puntos estan alineados o son iguales." << endl;
            }
            break;
        }
        
        case 2: {
            // ADT Fecha_Hora
            int dia, mes, anio, hora, minuto, segundo;
            
            cout << "\n=== CALCULADORA DE FECHAS ===" << endl;
            cout << "Ingrese la fecha y hora:" << endl;
            
            cout << "Dia: ";
            cin >> dia;
            cout << "Mes: ";
            cin >> mes;
            cout << "Anio: ";
            cin >> anio;
            cout << "Hora: ";
            cin >> hora;
            cout << "Minuto: ";
            cin >> minuto;
            cout << "Segundo: ";
            cin >> segundo;
            
            // Crear la fecha_hora
            FechaHora miFecha(dia, mes, anio, hora, minuto, segundo);
            
            cout << "\n=== RESULTADOS ===" << endl;
            
            // Validar fecha
            if (miFecha.esFechaValida()) {
                cout << "La fecha es VALIDA" << endl;
                cout << "Fecha formateada: " << miFecha.formatearFechaHora() << endl;
                cout << "Dia de la semana: " << miFecha.obtenerDiaSemana() << endl;
                
                // Pedir segunda fecha para comparar
                cout << "\nIngrese una segunda fecha para comparar:" << endl;
                cout << "Dia: ";
                cin >> dia;
                cout << "Mes: ";
                cin >> mes;
                cout << "Anio: ";
                cin >> anio;
                
                FechaHora segundaFecha(dia, mes, anio, 0, 0, 0);
                if (segundaFecha.esFechaValida()) {
                    cout << "Dias entre fechas: " << miFecha.diasEntreFechas(segundaFecha) << endl;
                } else {
                    cout << "La segunda fecha no es valida" << endl;
                }
                
            } else {
                cout << "La fecha NO es VALIDA" << endl;
            }
            break;
        }
        
        case 3:
            cout << "Saliendo del programa..." << endl;
            break;
            
        default:
            cout << "Opcion no valida" << endl;
    }
    
    cout << "\n=== FIN DEL PROGRAMA ===" << endl;
    return 0;
}
