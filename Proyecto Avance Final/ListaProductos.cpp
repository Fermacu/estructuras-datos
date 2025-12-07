#include "ListaProductos.h"
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

//Inicializar contador de comparaciones
int ListaProductos::contadorComparaciones = 0;

//Destructor - Libera toda la memoria dinámica
ListaProductos::~ListaProductos(){
    Producto* actual = primero;
    while(actual != nullptr){
        Producto* siguiente = actual->getSiguiente();
        delete actual;
        actual = siguiente;
    }
}

Producto* ListaProductos::getPrimero(){
    return primero;
}

Producto* ListaProductos::getUltimo(){
    Producto* nodoTemp = primero;
    if(nodoTemp == nullptr){
        cout << "La lista esta vacia.\n" << endl;
        return nodoTemp;
    }
    while(nodoTemp->getSiguiente() != nullptr){
        nodoTemp = nodoTemp->getSiguiente();
    }
    return nodoTemp;
}

bool ListaProductos::validarIdUnico(int id){
    Producto* actual = primero;
    while(actual != nullptr){
        if(actual->getId() == id){
            cout << "Error: El ID " << id << " ya existe en la lista.\n" << endl;
            return false;
        }
        actual = actual->getSiguiente();
    }
    return true;
}

void ListaProductos::insertarFinal(int id, string nombre, double precio, int cantidad){
    //Validar que el ID sea único
    if(!validarIdUnico(id)){
        return;
    }
    
    //Validar que precio y cantidad sean valores válidos
    if(precio < 0){
        cout << "Error: El precio no puede ser negativo.\n" << endl;
        return;
    }
    
    if(cantidad < 0){
        cout << "Error: La cantidad no puede ser negativa.\n" << endl;
        return;
    }
    
    Producto* nuevoProducto = new Producto(id, nombre, precio, cantidad);
    if(primero == nullptr){
        primero = nuevoProducto;
    }
    else{
        Producto* ultimo = this->getUltimo();
        if(ultimo != nullptr){
            ultimo->setSiguiente(nuevoProducto);
        } else {
            //Si por alguna razón getUltimo retorna nullptr pero primero no es nullptr,
            //esto indica un problema de integridad, pero asignamos directamente
            primero = nuevoProducto;
        }
    }
    cout << "Producto agregado exitosamente.\n" << endl;
}

Producto* ListaProductos::buscar(string nombreBuscar){
    Producto* nodoTemp = primero;
    if(nodoTemp == nullptr){
        cout << "La lista esta vacia.\n" << endl;
        return nodoTemp;
    }
    while(nodoTemp != nullptr && nodoTemp->getNombre() != nombreBuscar){
        nodoTemp = nodoTemp->getSiguiente();
    }
    if(nodoTemp != nullptr && nodoTemp->getNombre() == nombreBuscar){
        cout << "El producto se encontro en la lista.\n" << endl;
        return nodoTemp;
    }
    else{
        cout << "El producto no se encontro en la lista.\n" << endl;
        return nullptr;
    }
}

Producto* ListaProductos::buscar(int idBuscar){
    Producto* nodoTemp = primero;
    if(nodoTemp == nullptr){
        cout << "La lista esta vacia.\n" << endl;
        return nodoTemp;
    }
    while(nodoTemp != nullptr && nodoTemp->getId() != idBuscar){
        nodoTemp = nodoTemp->getSiguiente();
    }
    if(nodoTemp != nullptr && nodoTemp->getId() == idBuscar){
        cout << "El producto se encontro en la lista.\n" << endl;
        return nodoTemp;
    }
    else{
        cout << "El producto no se encontro en la lista.\n" << endl;
        return nullptr;
    }
}

Producto* ListaProductos::eliminar(string nombreEliminar){
    if(primero == nullptr){
        cout << "La lista esta vacia.\n" << endl;
        return nullptr;
    }
    
    Producto* actual = primero;
    Producto* anterior = nullptr;
    
    //Buscar el producto a eliminar
    while(actual != nullptr && actual->getNombre() != nombreEliminar){
        anterior = actual;
        actual = actual->getSiguiente();
    }
    
    if(actual == nullptr){
        cout << "El producto no se encontro en la lista.\n" << endl;
        return nullptr;
    }
    
    //Eliminar el producto
    if(anterior == nullptr){
        //Eliminar el primer elemento
        primero = actual->getSiguiente();
    }
    else{
        //Eliminar elemento del medio o final
        anterior->setSiguiente(actual->getSiguiente());
    }
    
    cout << "Producto eliminado exitosamente.\n" << endl;
    return actual;
}

void ListaProductos::imprimir(){
    Producto* actual = primero;
    if(actual == nullptr){
        cout << "La lista esta vacia.\n" << endl;
        return;
    }
    
    cout << "=== LISTA DE PRODUCTOS ===" << endl;
    int contador = 1;
    while(actual != nullptr){
        cout << "Producto " << contador << ":" << endl;
        actual->imprimir();
        actual = actual->getSiguiente();
        contador++;
    }
}

int ListaProductos::obtenerTamanio(){
    int tamanio = 0;
    Producto* actual = primero;
    while(actual != nullptr){
        tamanio++;
        actual = actual->getSiguiente();
    }
    return tamanio;
}

int& ListaProductos::obtenerContadorComparaciones(){
    return contadorComparaciones;
}

//Convierte la lista enlazada a un arreglo de punteros a Producto
Producto** ListaProductos::convertirAArreglo(int& tamanio){
    tamanio = obtenerTamanio();
    if(tamanio == 0){
        return nullptr;
    }

    Producto** arreglo = new Producto*[tamanio];
    Producto* actual = primero;
    int indice = 0;

    while(actual != nullptr){
        //Crear una copia del producto para el arreglo
        Producto* copia = new Producto(
            actual->getId(),
            actual->getNombre(),
            actual->getPrecio(),
            actual->getCantidad()
        );
        arreglo[indice] = copia;
        actual = actual->getSiguiente();
        indice++;
    }

    return arreglo;
}

//Reconstruye la lista enlazada desde un arreglo
void ListaProductos::reconstruirDesdeArreglo(Producto** arreglo, int tamanio){
    //Limpiar la lista actual
    Producto* actual = primero;
    while(actual != nullptr){
        Producto* siguiente = actual->getSiguiente();
        delete actual;
        actual = siguiente;
    }
    primero = nullptr;

    //Reconstruir desde el arreglo
    if(tamanio > 0 && arreglo != nullptr){
        primero = new Producto(
            arreglo[0]->getId(),
            arreglo[0]->getNombre(),
            arreglo[0]->getPrecio(),
            arreglo[0]->getCantidad()
        );
        Producto* ultimo = primero;

        for(int i = 1; i < tamanio; i++){
            Producto* nuevo = new Producto(
                arreglo[i]->getId(),
                arreglo[i]->getNombre(),
                arreglo[i]->getPrecio(),
                arreglo[i]->getCantidad()
            );
            ultimo->setSiguiente(nuevo);
            ultimo = nuevo;
        }
    }
}

//Compara dos productos según el atributo especificado (con contador)
bool ListaProductos::compararProductos(Producto* p1, Producto* p2, int atributo, bool ascendente){
    contadorComparaciones++;
    return compararProductosSinContar(p1, p2, atributo, ascendente);
}

//Compara dos productos según el atributo especificado (sin contador)
bool ListaProductos::compararProductosSinContar(Producto* p1, Producto* p2, int atributo, bool ascendente){
    bool resultado;

    switch(atributo){
        case 1: // ID
            resultado = (p1->getId() < p2->getId());
            break;
        case 2: // Nombre
            resultado = (p1->getNombre() < p2->getNombre());
            break;
        case 3: // Precio
            resultado = (p1->getPrecio() < p2->getPrecio());
            break;
        case 4: // Cantidad
            resultado = (p1->getCantidad() < p2->getCantidad());
            break;
        default:
            resultado = false;
    }

    return ascendente ? resultado : !resultado;
}

//Verifica si la lista está ordenada según un atributo
bool ListaProductos::estaOrdenada(int atributo){
    if(primero == nullptr || primero->getSiguiente() == nullptr){
        return true;
    }

    Producto* actual = primero;
    Producto* siguiente = actual->getSiguiente();

    while(siguiente != nullptr){
        if(!compararProductosSinContar(actual, siguiente, atributo, true)){
            return false;
        }
        actual = siguiente;
        siguiente = siguiente->getSiguiente();
    }
    return true;
}

//Ordenamiento por selección
void ListaProductos::ordenarPorSeleccion(int atributo, bool ascendente){
    contadorComparaciones = 0;

    int tamanio;
    Producto** arreglo = convertirAArreglo(tamanio);

    if(arreglo == nullptr || tamanio <= 1){
        if(arreglo != nullptr){
            for(int i = 0; i < tamanio; i++){
                delete arreglo[i];
            }
            delete[] arreglo;
        }
        cout << "La lista esta vacia o tiene un solo elemento.\n" << endl;
        return;
    }

    //Algoritmo de ordenamiento por selección
    for(int i = 0; i < tamanio - 1; i++){
        int indiceExtremo = i;
        for(int j = i + 1; j < tamanio; j++){
            if(compararProductos(arreglo[j], arreglo[indiceExtremo], atributo, ascendente)){
                indiceExtremo = j;
            }
        }
        if(indiceExtremo != i){
            Producto* temp = arreglo[i];
            arreglo[i] = arreglo[indiceExtremo];
            arreglo[indiceExtremo] = temp;
        }
    }

    //Reconstruir la lista
    reconstruirDesdeArreglo(arreglo, tamanio);

    //Liberar memoria del arreglo
    for(int i = 0; i < tamanio; i++){
        delete arreglo[i];
    }
    delete[] arreglo;

    cout << "Ordenamiento por seleccion completado." << endl;
    cout << "Comparaciones realizadas: " << contadorComparaciones << "\n" << endl;
}

//Función auxiliar para merge sort
void ListaProductos::merge(Producto** arreglo, int izquierda, int medio, int derecha, int atributo, bool ascendente){
    int n1 = medio - izquierda + 1;
    int n2 = derecha - medio;

    Producto** izquierdaArr = new Producto*[n1];
    Producto** derechaArr = new Producto*[n2];

    for(int i = 0; i < n1; i++){
        izquierdaArr[i] = arreglo[izquierda + i];
    }
    for(int j = 0; j < n2; j++){
        derechaArr[j] = arreglo[medio + 1 + j];
    }

    int i = 0, j = 0, k = izquierda;

    while(i < n1 && j < n2){
        if(compararProductos(izquierdaArr[i], derechaArr[j], atributo, ascendente)){
            arreglo[k] = izquierdaArr[i];
            i++;
        } else {
            arreglo[k] = derechaArr[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arreglo[k] = izquierdaArr[i];
        i++;
        k++;
    }

    while(j < n2){
        arreglo[k] = derechaArr[j];
        j++;
        k++;
    }

    delete[] izquierdaArr;
    delete[] derechaArr;
}

//Función recursiva para merge sort
void ListaProductos::mergeSortRecursivo(Producto** arreglo, int izquierda, int derecha, int atributo, bool ascendente){
    if(izquierda < derecha){
        int medio = izquierda + (derecha - izquierda) / 2;
        mergeSortRecursivo(arreglo, izquierda, medio, atributo, ascendente);
        mergeSortRecursivo(arreglo, medio + 1, derecha, atributo, ascendente);
        merge(arreglo, izquierda, medio, derecha, atributo, ascendente);
    }
}

//Ordenamiento por mezcla (merge sort)
void ListaProductos::ordenarPorMezcla(int atributo, bool ascendente){
    contadorComparaciones = 0;

    int tamanio;
    Producto** arreglo = convertirAArreglo(tamanio);

    if(arreglo == nullptr || tamanio <= 1){
        if(arreglo != nullptr){
            for(int i = 0; i < tamanio; i++){
                delete arreglo[i];
            }
            delete[] arreglo;
        }
        cout << "La lista esta vacia o tiene un solo elemento.\n" << endl;
        return;
    }

    //Aplicar merge sort
    mergeSortRecursivo(arreglo, 0, tamanio - 1, atributo, ascendente);

    //Reconstruir la lista
    reconstruirDesdeArreglo(arreglo, tamanio);

    //Liberar memoria del arreglo
    for(int i = 0; i < tamanio; i++){
        delete arreglo[i];
    }
    delete[] arreglo;

    cout << "Ordenamiento por mezcla completado." << endl;
    cout << "Comparaciones realizadas: " << contadorComparaciones << "\n" << endl;
}

//Búsqueda lineal por string (nombre)
Producto* ListaProductos::busquedaLineal(int atributo, string valorBuscar){
    if(atributo != 2){
        cout << "Error: Este metodo solo funciona para buscar por nombre.\n" << endl;
        return nullptr;
    }

    Producto* actual = primero;
    int comparaciones = 0;

    while(actual != nullptr){
        comparaciones++;
        if(actual->getNombre() == valorBuscar){
            cout << "Producto encontrado con busqueda lineal." << endl;
            cout << "Comparaciones realizadas: " << comparaciones << "\n" << endl;
            return actual;
        }
        actual = actual->getSiguiente();
    }

    cout << "Producto no encontrado con busqueda lineal." << endl;
    cout << "Comparaciones realizadas: " << comparaciones << "\n" << endl;
    return nullptr;
}

//Búsqueda lineal por int (id o cantidad)
Producto* ListaProductos::busquedaLineal(int atributo, int valorBuscar){
    if(atributo != 1 && atributo != 4){
        cout << "Error: Este metodo solo funciona para buscar por ID o cantidad.\n" << endl;
        return nullptr;
    }

    Producto* actual = primero;
    int comparaciones = 0;

    while(actual != nullptr){
        comparaciones++;
        bool encontrado = false;
        if(atributo == 1 && actual->getId() == valorBuscar){
            encontrado = true;
        } else if(atributo == 4 && actual->getCantidad() == valorBuscar){
            encontrado = true;
        }

        if(encontrado){
            cout << "Producto encontrado con busqueda lineal." << endl;
            cout << "Comparaciones realizadas: " << comparaciones << "\n" << endl;
            return actual;
        }
        actual = actual->getSiguiente();
    }

    cout << "Producto no encontrado con busqueda lineal." << endl;
    cout << "Comparaciones realizadas: " << comparaciones << "\n" << endl;
    return nullptr;
}

//Búsqueda lineal por double (precio)
Producto* ListaProductos::busquedaLineal(int atributo, double valorBuscar){
    if(atributo != 3){
        cout << "Error: Este metodo solo funciona para buscar por precio.\n" << endl;
        return nullptr;
    }

    Producto* actual = primero;
    int comparaciones = 0;

    while(actual != nullptr){
        comparaciones++;
        if(actual->getPrecio() == valorBuscar){
            cout << "Producto encontrado con busqueda lineal." << endl;
            cout << "Comparaciones realizadas: " << comparaciones << "\n" << endl;
            return actual;
        }
        actual = actual->getSiguiente();
    }

    cout << "Producto no encontrado con busqueda lineal." << endl;
    cout << "Comparaciones realizadas: " << comparaciones << "\n" << endl;
    return nullptr;
}

//Búsqueda binaria por string (nombre)
Producto* ListaProductos::busquedaBinaria(int atributo, string valorBuscar){
    if(atributo != 2){
        cout << "Error: Este metodo solo funciona para buscar por nombre.\n" << endl;
        return nullptr;
    }

    //Verificar si está ordenada
    if(!estaOrdenada(atributo)){
        cout << "Advertencia: La lista no esta ordenada por nombre. Ordenando primero..." << endl;
        ordenarPorMezcla(atributo, true);
    }

    int tamanio;
    Producto** arreglo = convertirAArreglo(tamanio);

    if(arreglo == nullptr || tamanio == 0){
        cout << "La lista esta vacia.\n" << endl;
        return nullptr;
    }

    int izquierda = 0, derecha = tamanio - 1;
    int comparaciones = 0;

    while(izquierda <= derecha){
        comparaciones++;
        int medio = izquierda + (derecha - izquierda) / 2;

        if(arreglo[medio]->getNombre() == valorBuscar){
            //Guardar el nombre para buscar en la lista original
            string nombreEncontrado = arreglo[medio]->getNombre();
            
            //Liberar memoria del arreglo temporal
            for(int i = 0; i < tamanio; i++){
                delete arreglo[i];
            }
            delete[] arreglo;
            
            //Buscar en la lista original y devolver el puntero real
            Producto* actual = primero;
            while(actual != nullptr){
                if(actual->getNombre() == nombreEncontrado){
                    cout << "Producto encontrado con busqueda binaria." << endl;
                    cout << "Comparaciones realizadas: " << comparaciones << "\n" << endl;
                    return actual;
                }
                actual = actual->getSiguiente();
            }
            
            return nullptr;
        }

        if(arreglo[medio]->getNombre() < valorBuscar){
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }

    //Liberar memoria
    for(int i = 0; i < tamanio; i++){
        delete arreglo[i];
    }
    delete[] arreglo;

    cout << "Producto no encontrado con busqueda binaria." << endl;
    cout << "Comparaciones realizadas: " << comparaciones << "\n" << endl;
    return nullptr;
}

//Búsqueda binaria por int (id o cantidad)
Producto* ListaProductos::busquedaBinaria(int atributo, int valorBuscar){
    if(atributo != 1 && atributo != 4){
        cout << "Error: Este metodo solo funciona para buscar por ID o cantidad.\n" << endl;
        return nullptr;
    }

    //Verificar si está ordenada
    if(!estaOrdenada(atributo)){
        cout << "Advertencia: La lista no esta ordenada. Ordenando primero..." << endl;
        ordenarPorMezcla(atributo, true);
    }

    int tamanio;
    Producto** arreglo = convertirAArreglo(tamanio);

    if(arreglo == nullptr || tamanio == 0){
        cout << "La lista esta vacia.\n" << endl;
        return nullptr;
    }

    int izquierda = 0, derecha = tamanio - 1;
    int comparaciones = 0;

    while(izquierda <= derecha){
        comparaciones++;
        int medio = izquierda + (derecha - izquierda) / 2;

        int valorMedio;
        int valorGuardado = 0;
        if(atributo == 1){
            valorMedio = arreglo[medio]->getId();
            valorGuardado = arreglo[medio]->getId();
        } else {
            valorMedio = arreglo[medio]->getCantidad();
            valorGuardado = arreglo[medio]->getCantidad();
        }

        if(valorMedio == valorBuscar){
            //Guardar el valor encontrado para buscar en la lista original
            int valorEncontrado = valorGuardado;
            
            //Liberar memoria del arreglo temporal
            for(int i = 0; i < tamanio; i++){
                delete arreglo[i];
            }
            delete[] arreglo;
            
            //Buscar en la lista original y devolver el puntero real
            Producto* actual = primero;
            while(actual != nullptr){
                if((atributo == 1 && actual->getId() == valorEncontrado) ||
                   (atributo == 4 && actual->getCantidad() == valorEncontrado)){
                    cout << "Producto encontrado con busqueda binaria." << endl;
                    cout << "Comparaciones realizadas: " << comparaciones << "\n" << endl;
                    return actual;
                }
                actual = actual->getSiguiente();
            }
            
            return nullptr;
        }

        if(valorMedio < valorBuscar){
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }

    //Liberar memoria
    for(int i = 0; i < tamanio; i++){
        delete arreglo[i];
    }
    delete[] arreglo;

    cout << "Producto no encontrado con busqueda binaria." << endl;
    cout << "Comparaciones realizadas: " << comparaciones << "\n" << endl;
    return nullptr;
}

//Búsqueda binaria por double (precio)
Producto* ListaProductos::busquedaBinaria(int atributo, double valorBuscar){
    if(atributo != 3){
        cout << "Error: Este metodo solo funciona para buscar por precio.\n" << endl;
        return nullptr;
    }

    //Verificar si está ordenada
    if(!estaOrdenada(atributo)){
        cout << "Advertencia: La lista no esta ordenada por precio. Ordenando primero..." << endl;
        ordenarPorMezcla(atributo, true);
    }

    int tamanio;
    Producto** arreglo = convertirAArreglo(tamanio);

    if(arreglo == nullptr || tamanio == 0){
        cout << "La lista esta vacia.\n" << endl;
        return nullptr;
    }

    int izquierda = 0, derecha = tamanio - 1;
    int comparaciones = 0;

    while(izquierda <= derecha){
        comparaciones++;
        int medio = izquierda + (derecha - izquierda) / 2;

        if(arreglo[medio]->getPrecio() == valorBuscar){
            //Guardar el precio para buscar en la lista original
            double precioEncontrado = arreglo[medio]->getPrecio();
            
            //Liberar memoria del arreglo temporal
            for(int i = 0; i < tamanio; i++){
                delete arreglo[i];
            }
            delete[] arreglo;
            
            //Buscar en la lista original y devolver el puntero real
            Producto* actual = primero;
            while(actual != nullptr){
                if(actual->getPrecio() == precioEncontrado){
                    cout << "Producto encontrado con busqueda binaria." << endl;
                    cout << "Comparaciones realizadas: " << comparaciones << "\n" << endl;
                    return actual;
                }
                actual = actual->getSiguiente();
            }
            
            return nullptr;
        }

        if(arreglo[medio]->getPrecio() < valorBuscar){
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }

    //Liberar memoria
    for(int i = 0; i < tamanio; i++){
        delete arreglo[i];
    }
    delete[] arreglo;

    cout << "Producto no encontrado con busqueda binaria." << endl;
    cout << "Comparaciones realizadas: " << comparaciones << "\n" << endl;
    return nullptr;
}
