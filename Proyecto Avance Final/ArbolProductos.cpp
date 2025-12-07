#include "ArbolProductos.h"
#include <algorithm>
#include <iostream>
using namespace std;

//Destructor
ArbolProductos::~ArbolProductos(){
    liberarArbol(raiz);
}

//Libera toda la memoria del árbol
void ArbolProductos::liberarArbol(NodoArbol* nodo){
    if(nodo != nullptr){
        liberarArbol(nodo->getIzquierdo());
        liberarArbol(nodo->getDerecho());
        delete nodo;
    }
}

//Obtiene la altura de un nodo (retorna 0 si es nullptr)
int ArbolProductos::obtenerAltura(NodoArbol* nodo){
    if(nodo == nullptr){
        return 0;
    }
    return nodo->getAltura();
}

//Calcula el factor de balance de un nodo
int ArbolProductos::obtenerBalance(NodoArbol* nodo){
    if(nodo == nullptr){
        return 0;
    }
    return obtenerAltura(nodo->getIzquierdo()) - obtenerAltura(nodo->getDerecho());
}

//Rotación simple a la derecha (para balancear cuando el subárbol izquierdo es más alto)
NodoArbol* ArbolProductos::rotacionDerecha(NodoArbol* y){
    NodoArbol* x = y->getIzquierdo();
    NodoArbol* T2 = x->getDerecho();

    //Realizar rotación
    x->setDerecho(y);
    y->setIzquierdo(T2);

    //Actualizar alturas
    y->setAltura(max(obtenerAltura(y->getIzquierdo()), obtenerAltura(y->getDerecho())) + 1);
    x->setAltura(max(obtenerAltura(x->getIzquierdo()), obtenerAltura(x->getDerecho())) + 1);

    return x; //Nueva raíz
}

//Rotación simple a la izquierda (para balancear cuando el subárbol derecho es más alto)
NodoArbol* ArbolProductos::rotacionIzquierda(NodoArbol* x){
    NodoArbol* y = x->getDerecho();
    NodoArbol* T2 = y->getIzquierdo();

    //Realizar rotación
    y->setIzquierdo(x);
    x->setDerecho(T2);

    //Actualizar alturas
    x->setAltura(max(obtenerAltura(x->getIzquierdo()), obtenerAltura(x->getDerecho())) + 1);
    y->setAltura(max(obtenerAltura(y->getIzquierdo()), obtenerAltura(y->getDerecho())) + 1);

    return y; //Nueva raíz
}

//Inserta un producto en el árbol de forma balanceada
void ArbolProductos::insertar(int id, string nombre, double precio, int cantidad){
    if(!validarIdUnico(id)){
        return;
    }
    Producto* nuevoProducto = new Producto(id, nombre, precio, cantidad);
    raiz = insertarRecursivo(raiz, id, nombre, precio, cantidad);
    cout << "Producto agregado exitosamente al catalogo.\n" << endl;
}

//Inserción recursiva con balanceo AVL
NodoArbol* ArbolProductos::insertarRecursivo(NodoArbol* nodo, int id, string nombre, double precio, int cantidad){
    //1. Realizar inserción normal de BST
    if(nodo == nullptr){
        Producto* nuevoProducto = new Producto(id, nombre, precio, cantidad);
        return new NodoArbol(nuevoProducto);
    }

    if(id < nodo->getProducto()->getId()){
        nodo->setIzquierdo(insertarRecursivo(nodo->getIzquierdo(), id, nombre, precio, cantidad));
    } else if(id > nodo->getProducto()->getId()){
        nodo->setDerecho(insertarRecursivo(nodo->getDerecho(), id, nombre, precio, cantidad));
    } else {
        //ID duplicado (no debería pasar por la validación)
        return nodo;
    }

    //2. Actualizar altura del nodo ancestro
    nodo->setAltura(1 + max(obtenerAltura(nodo->getIzquierdo()), obtenerAltura(nodo->getDerecho())));

    //3. Obtener el factor de balance
    int balance = obtenerBalance(nodo);

    //4. Si el nodo está desbalanceado, hay 4 casos

    //Caso Izquierda-Izquierda
    if(balance > 1 && id < nodo->getIzquierdo()->getProducto()->getId()){
        return rotacionDerecha(nodo);
    }

    //Caso Derecha-Derecha
    if(balance < -1 && id > nodo->getDerecho()->getProducto()->getId()){
        return rotacionIzquierda(nodo);
    }

    //Caso Izquierda-Derecha
    if(balance > 1 && id > nodo->getIzquierdo()->getProducto()->getId()){
        nodo->setIzquierdo(rotacionIzquierda(nodo->getIzquierdo()));
        return rotacionDerecha(nodo);
    }

    //Caso Derecha-Izquierda
    if(balance < -1 && id < nodo->getDerecho()->getProducto()->getId()){
        nodo->setDerecho(rotacionDerecha(nodo->getDerecho()));
        return rotacionIzquierda(nodo);
    }

    return nodo; //Retornar el nodo (sin cambios)
}

//Busca un producto por ID
Producto* ArbolProductos::buscar(int id){
    NodoArbol* resultado = buscarRecursivoPorId(raiz, id);
    if(resultado != nullptr){
        cout << "Producto encontrado en el catalogo.\n" << endl;
        return resultado->getProducto();
    } else {
        cout << "Producto no encontrado en el catalogo.\n" << endl;
        return nullptr;
    }
}

//Búsqueda recursiva por ID
NodoArbol* ArbolProductos::buscarRecursivoPorId(NodoArbol* nodo, int id){
    if(nodo == nullptr || nodo->getProducto()->getId() == id){
        return nodo;
    }

    if(id < nodo->getProducto()->getId()){
        return buscarRecursivoPorId(nodo->getIzquierdo(), id);
    }

    return buscarRecursivoPorId(nodo->getDerecho(), id);
}

//Busca un producto por nombre (búsqueda en todo el árbol)
Producto* ArbolProductos::buscar(string nombre){
    Producto* resultado = buscarRecursivoPorNombre(raiz, nombre);
    if(resultado != nullptr){
        cout << "Producto encontrado en el catalogo.\n" << endl;
        return resultado;
    } else {
        cout << "Producto no encontrado en el catalogo.\n" << endl;
        return nullptr;
    }
}

//Búsqueda recursiva por nombre (recorre todo el árbol)
Producto* ArbolProductos::buscarRecursivoPorNombre(NodoArbol* nodo, string nombre){
    if(nodo == nullptr){
        return nullptr;
    }

    //Buscar en el nodo actual
    if(nodo->getProducto()->getNombre() == nombre){
        return nodo->getProducto();
    }

    //Buscar en el subárbol izquierdo
    Producto* izquierdo = buscarRecursivoPorNombre(nodo->getIzquierdo(), nombre);
    if(izquierdo != nullptr){
        return izquierdo;
    }

    //Buscar en el subárbol derecho
    return buscarRecursivoPorNombre(nodo->getDerecho(), nombre);
}

//Elimina un producto del árbol
bool ArbolProductos::eliminar(int id){
    if(raiz == nullptr){
        cout << "El catalogo esta vacio.\n" << endl;
        return false;
    }

    bool encontrado = buscarRecursivoPorId(raiz, id) != nullptr;
    if(!encontrado){
        cout << "Producto no encontrado en el catalogo.\n" << endl;
        return false;
    }

    raiz = eliminarRecursivo(raiz, id);
    cout << "Producto eliminado exitosamente del catalogo.\n" << endl;
    return true;
}

//Eliminación recursiva con balanceo AVL
NodoArbol* ArbolProductos::eliminarRecursivo(NodoArbol* nodo, int id){
    //1. Realizar eliminación normal de BST
    if(nodo == nullptr){
        return nodo;
    }

    if(id < nodo->getProducto()->getId()){
        nodo->setIzquierdo(eliminarRecursivo(nodo->getIzquierdo(), id));
    } else if(id > nodo->getProducto()->getId()){
        nodo->setDerecho(eliminarRecursivo(nodo->getDerecho(), id));
    } else {
        //Nodo a eliminar encontrado
        if(nodo->getIzquierdo() == nullptr || nodo->getDerecho() == nullptr){
            //Nodo con 0 o 1 hijo
            NodoArbol* temp = nodo->getIzquierdo() ? nodo->getIzquierdo() : nodo->getDerecho();

            if(temp == nullptr){
                //Sin hijos
                temp = nodo;
                nodo = nullptr;
            } else {
                //Un hijo
                //Copiar los datos del hijo al nodo
                nodo->setProducto(temp->getProducto());
                nodo->setIzquierdo(temp->getIzquierdo());
                nodo->setDerecho(temp->getDerecho());
                nodo->setAltura(temp->getAltura());
            }
            delete temp;
        } else {
            //Nodo con 2 hijos: obtener el sucesor inorden (menor en el subárbol derecho)
            NodoArbol* temp = obtenerMinimo(nodo->getDerecho());
            //Copiar los datos del sucesor al nodo
            nodo->setProducto(temp->getProducto());
            //Eliminar el sucesor
            nodo->setDerecho(eliminarRecursivo(nodo->getDerecho(), temp->getProducto()->getId()));
        }
    }

    //Si el árbol tenía solo un nodo, retornar
    if(nodo == nullptr){
        return nodo;
    }

    //2. Actualizar altura
    nodo->setAltura(1 + max(obtenerAltura(nodo->getIzquierdo()), obtenerAltura(nodo->getDerecho())));

    //3. Obtener el factor de balance
    int balance = obtenerBalance(nodo);

    //4. Si el nodo está desbalanceado, hay 4 casos

    //Caso Izquierda-Izquierda
    if(balance > 1 && obtenerBalance(nodo->getIzquierdo()) >= 0){
        return rotacionDerecha(nodo);
    }

    //Caso Izquierda-Derecha
    if(balance > 1 && obtenerBalance(nodo->getIzquierdo()) < 0){
        nodo->setIzquierdo(rotacionIzquierda(nodo->getIzquierdo()));
        return rotacionDerecha(nodo);
    }

    //Caso Derecha-Derecha
    if(balance < -1 && obtenerBalance(nodo->getDerecho()) <= 0){
        return rotacionIzquierda(nodo);
    }

    //Caso Derecha-Izquierda
    if(balance < -1 && obtenerBalance(nodo->getDerecho()) > 0){
        nodo->setDerecho(rotacionDerecha(nodo->getDerecho()));
        return rotacionIzquierda(nodo);
    }

    return nodo;
}

//Obtiene el nodo con el menor ID en un subárbol
NodoArbol* ArbolProductos::obtenerMinimo(NodoArbol* nodo){
    NodoArbol* actual = nodo;
    while(actual->getIzquierdo() != nullptr){
        actual = actual->getIzquierdo();
    }
    return actual;
}

//Imprime el árbol en orden inorden (muestra productos ordenados por ID)
void ArbolProductos::imprimir(){
    if(raiz == nullptr){
        cout << "El catalogo esta vacio.\n" << endl;
        return;
    }
    cout << "=== CATALOGO DE PRODUCTOS (Ordenado por ID) ===" << endl;
    imprimirRecursivo(raiz);
    cout << endl;
}

//Impresión recursiva en orden inorden
void ArbolProductos::imprimirRecursivo(NodoArbol* nodo){
    if(nodo != nullptr){
        imprimirRecursivo(nodo->getIzquierdo());
        nodo->getProducto()->imprimir();
        imprimirRecursivo(nodo->getDerecho());
    }
}

//Verifica si el árbol está vacío
bool ArbolProductos::estaVacio(){
    return raiz == nullptr;
}

//Verifica si un ID es único
bool ArbolProductos::validarIdUnico(int id){
    if(buscarRecursivoPorId(raiz, id) != nullptr){
        cout << "Error: El ID " << id << " ya existe en el catalogo.\n" << endl;
        return false;
    }
    return true;
}

//Método auxiliar para compatibilidad - retorna el producto con menor ID
Producto* ArbolProductos::getPrimero(){
    if(raiz == nullptr){
        return nullptr;
    }
    NodoArbol* minimo = obtenerMinimo(raiz);
    return minimo->getProducto();
}



