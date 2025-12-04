#include "ColaTareas.h"

//Destructor - Libera toda la memoria dinámica
ColaTareas::~ColaTareas(){
    while(!estaVacia()){
        eliminarTareaPrioridad();
    }
}

//Verifica si la cola está vacía
bool ColaTareas::estaVacia(){
    return frente == nullptr;
}

//Inserta una tarea al final de la cola
void ColaTareas::insertar(Tarea* tarea){
    NodoTarea* nuevoNodo = new NodoTarea(tarea);
    
    if(estaVacia()){
        frente = nuevoNodo;
        final = nuevoNodo;
    } else {
        final->setSiguiente(nuevoNodo);
        final = nuevoNodo;
    }
}

//Elimina la tarea con mayor prioridad (1 es mayor, 3 es menor)
//En caso de empate, elimina la más cercana al frente
void ColaTareas::eliminarTareaPrioridad(){
    if(estaVacia()){
        cout << "Error: La cola de tareas esta vacia." << endl;
        return;
    }

    // Buscar la tarea con mayor prioridad (menor número = mayor prioridad)
    // En caso de empate, se selecciona la más cercana al frente
    NodoTarea* actual = frente;
    NodoTarea* anterior = nullptr;
    NodoTarea* nodoAEliminar = frente;
    NodoTarea* anteriorAEliminar = nullptr;
    int mayorPrioridad = frente->getTarea()->getPrioridad(); // Menor número = mayor prioridad

    // Recorrer la cola para encontrar la tarea con mayor prioridad
    while(actual != nullptr){
        if(actual->getTarea()->getPrioridad() < mayorPrioridad){
            mayorPrioridad = actual->getTarea()->getPrioridad();
            nodoAEliminar = actual;
            anteriorAEliminar = anterior;
        }
        anterior = actual;
        actual = actual->getSiguiente();
    }

    // Generar reporte antes de eliminar
    generarReporte(nodoAEliminar->getTarea());

    // Eliminar el nodo encontrado
    if(nodoAEliminar == frente){
        // Si es el primero
        frente = frente->getSiguiente();
        if(frente == nullptr){
            final = nullptr;
        }
    } else if(nodoAEliminar == final){
        // Si es el último
        anteriorAEliminar->setSiguiente(nullptr);
        final = anteriorAEliminar;
    } else {
        // Si está en el medio
        anteriorAEliminar->setSiguiente(nodoAEliminar->getSiguiente());
    }

    // Liberar memoria
    delete nodoAEliminar->getTarea(); // Esto también libera la lista de requerimientos
    delete nodoAEliminar;
}

//Genera un reporte de la tarea eliminada
void ColaTareas::generarReporte(Tarea* tarea){
    cout << "\n=== REPORTE DE TAREA ELIMINADA ===" << endl;
    cout << "Descripcion: " << tarea->getDescripcion() << endl;
    cout << "Prioridad: " << tarea->getPrioridad() << endl;
    cout << "Encargado: " << tarea->getEncargado() << endl;
    cout << "Requerimientos:" << endl;
    tarea->getListaRequerimientos()->imprimirRequerimientos();
    int complejidadAcumulada = tarea->getListaRequerimientos()->calcularComplejidadAcumulada();
    cout << "Complejidad Acumulada: " << complejidadAcumulada << endl;
    cout << "===================================" << endl << endl;
}

