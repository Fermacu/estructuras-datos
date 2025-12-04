#include "ColaTareas.h"
#include "Tarea.h"
#include "Requerimiento.h"
#include <iostream>
#include <string>
#include <limits>
using namespace std;

void mostrarMenu(){
    cout << "\n=== MENU DE COLA DE TAREAS ===" << endl;
    cout << "1. Insertar nueva tarea" << endl;
    cout << "2. Eliminar tarea con mayor prioridad" << endl;
    cout << "3. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

void limpiarBuffer(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void insertarTarea(ColaTareas* cola){
    string descripcion, encargado, descripcionReq;
    int prioridad, numRequerimientos, complejidad;
    
    cout << "\n=== INSERTAR NUEVA TAREA ===" << endl;
    
    // Limpiar buffer antes de leer strings
    limpiarBuffer();
    
    cout << "Ingrese la descripcion de la tarea: ";
    getline(cin, descripcion);
    
    cout << "Ingrese la prioridad (1-3, donde 1 es mayor prioridad): ";
    cin >> prioridad;
    while(prioridad < 1 || prioridad > 3){
        cout << "Prioridad invalida. Ingrese un valor entre 1 y 3: ";
        cin >> prioridad;
    }
    
    limpiarBuffer();
    cout << "Ingrese el nombre del encargado: ";
    getline(cin, encargado);
    
    // Crear la tarea
    Tarea* nuevaTarea = new Tarea(descripcion, prioridad, encargado);
    
    // Pedir requerimientos
    cout << "Cuantos requerimientos tiene esta tarea? ";
    cin >> numRequerimientos;
    
    limpiarBuffer();
    for(int i = 0; i < numRequerimientos; i++){
        cout << "\nRequerimiento " << (i + 1) << ":" << endl;
        cout << "  Descripcion: ";
        getline(cin, descripcionReq);
        
        cout << "  Complejidad (1-10): ";
        cin >> complejidad;
        while(complejidad < 1 || complejidad > 10){
            cout << "  Complejidad invalida. Ingrese un valor entre 1 y 10: ";
            cin >> complejidad;
        }
        
        // Crear el requerimiento
        Requerimiento* nuevoReq = new Requerimiento(descripcionReq, complejidad);
        
        // Insertar el requerimiento en la tarea
        nuevaTarea->insertarRequerimiento(nuevoReq);
        
        limpiarBuffer();
    }
    
    // Insertar la tarea en la cola
    cola->insertar(nuevaTarea);
    
    cout << "\nTarea insertada exitosamente!" << endl;
}

void eliminarTarea(ColaTareas* cola){
    if(cola->estaVacia()){
        cout << "\nLa cola de tareas esta vacia. No hay tareas para eliminar." << endl;
        return;
    }
    
    cout << "\n=== ELIMINANDO TAREA CON MAYOR PRIORIDAD ===" << endl;
    cola->eliminarTareaPrioridad();
}

int main(){
    ColaTareas* cola = new ColaTareas();
    int opcion;
    
    cout << "Bienvenido al Sistema de Gestion de Cola de Tareas" << endl;
    
    do{
        mostrarMenu();
        cin >> opcion;
        
        switch(opcion){
            case 1:
                insertarTarea(cola);
                break;
                
            case 2:
                eliminarTarea(cola);
                break;
                
            case 3:
                cout << "\nSaliendo del programa..." << endl;
                break;
                
            default:
                cout << "\nOpcion no valida. Por favor, seleccione una opcion del 1 al 3." << endl;
        }
        
    } while(opcion != 3);
    
    // Liberar memoria de la cola
    delete cola;
    
    cout << "\n=== FIN DEL PROGRAMA ===" << endl;
    return 0;
}

