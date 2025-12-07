#include "ListaProductos.h"
#include "ArbolProductos.h"
#include "Cliente.h"
#include "ColaClientes.h"
#include <iostream>
#include <limits>
#include <cctype>
using namespace std;

//Catálogo global de productos de la tienda (usando ABB balanceado)
ArbolProductos* catalogo = new ArbolProductos();

//Cola de clientes del sistema
ColaClientes* colaClientes = new ColaClientes();

//Rutina menu() que coordina las operaciones del sistema
void menu(){
    int opcion;
    bool continuar = true;
    
    while(continuar){
        cout << "\n=== SISTEMA DE VENTAS EN LINEA ===" << endl;
        cout << "1. Agregar producto al catalogo" << endl;
        cout << "2. Insertar cliente" << endl;
        cout << "3. Eliminar cliente (atender cliente)" << endl;
        cout << "4. Ordenar productos de un cliente" << endl;
        cout << "5. Buscar producto en lista de un cliente" << endl;
        cout << "6. Imprimir lista de productos de un cliente" << endl;
        cout << "7. Imprimir catalogo de productos" << endl;
        cout << "8. Salir del sistema" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch(opcion){
            case 1: {
                //Agregar producto al catálogo
                int id;
                string nombre;
                double precio;
                int cantidad;
                
                cout << "\n--- AGREGAR PRODUCTO AL CATALOGO ---" << endl;
                
                //Leer ID con validación
                cout << "Ingrese el ID del producto: ";
                while(!(cin >> id)){
                    cout << "Error: Por favor ingrese un numero valido para el ID: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                
                cout << "Ingrese el nombre del producto: ";
                cin.ignore();
                getline(cin, nombre);
                
                //Leer precio con validación
                cout << "Ingrese el precio del producto: $";
                while(!(cin >> precio)){
                    cout << "Error: Por favor ingrese un numero valido para el precio: $";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                
                //Leer cantidad con validación
                cout << "Ingrese la cantidad disponible: ";
                while(!(cin >> cantidad)){
                    cout << "Error: Por favor ingrese un numero valido para la cantidad: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                
                catalogo->insertar(id, nombre, precio, cantidad);
                break;
            }
            
            case 2: {
                //Insertar cliente
                string nombre, cedula;
                int prioridad;
                
                cout << "\n--- INSERTAR CLIENTE ---" << endl;
                cout << "Ingrese el nombre del cliente: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Ingrese la cedula del cliente: ";
                getline(cin, cedula);
                
                //Verificar si el cliente ya existe
                if(colaClientes->buscarPorCedula(cedula) != nullptr){
                    cout << "Error: Ya existe un cliente con esa cedula.\n" << endl;
                    break;
                }
                
                cout << "Seleccione la prioridad del cliente:" << endl;
                cout << "1. Ordinario" << endl;
                cout << "2. Regular" << endl;
                cout << "3. Adulto mayor / Discapacitado / Embarazada" << endl;
                cout << "Opcion: ";
                cin >> prioridad;
                
                if(prioridad < 1 || prioridad > 3){
                    cout << "Error: Prioridad invalida. Se asignara prioridad 1 (Ordinario).\n" << endl;
                    prioridad = 1;
                }
                
                Cliente* nuevoCliente = new Cliente(nombre, cedula, prioridad);
                
                //Llenar el carrito del cliente desde el catálogo
                if(catalogo->estaVacio()){
                    cout << "El catalogo esta vacio. El cliente se agregara sin productos.\n" << endl;
                } else {
                    cout << "\n--- LLENAR CARRITO DE COMPRAS ---" << endl;
                    catalogo->imprimir();
                    bool agregarProductos = true;
                    
                    while(agregarProductos){
                        string entradaUsuario;
                        cout << "\nIngrese el ID o nombre del producto a agregar al carrito (o 'fin' para terminar): ";
                        cin.ignore();
                        getline(cin, entradaUsuario);
                        
                        //Eliminar espacios en blanco al inicio y final
                        string entradaLimpia = entradaUsuario;
                        //Eliminar espacios al inicio
                        while(!entradaLimpia.empty() && entradaLimpia[0] == ' '){
                            entradaLimpia.erase(0, 1);
                        }
                        //Eliminar espacios al final
                        while(!entradaLimpia.empty() && entradaLimpia[entradaLimpia.length()-1] == ' '){
                            entradaLimpia.erase(entradaLimpia.length()-1, 1);
                        }
                        
                        //Verificar si está vacío
                        if(entradaLimpia.empty()){
                            agregarProductos = false;
                            cout << "Finalizando agregado de productos al carrito...\n" << endl;
                            continue;
                        }
                        
                        //Convertir a minúsculas para comparación con "fin"
                        string entradaLower = entradaLimpia;
                        for(char& c : entradaLower){
                            c = tolower(c);
                        }
                        
                        //Verificar si quiere terminar (debe ser exactamente "fin")
                        if(entradaLower == "fin"){
                            agregarProductos = false;
                            cout << "Finalizando agregado de productos al carrito...\n" << endl;
                            continue;
                        }
                        
                        //Si llegamos aquí, buscar el producto
                        Producto* productoEncontrado = nullptr;
                        
                        //Intentar interpretar como ID (número)
                        bool esNumero = true;
                        for(char c : entradaLimpia){
                            if(!isdigit(c)){
                                esNumero = false;
                                break;
                            }
                        }
                        
                        if(esNumero){
                            //Buscar por ID
                            int idBuscar = stoi(entradaLimpia);
                            productoEncontrado = catalogo->buscar(idBuscar);
                        } else {
                            //Buscar por nombre
                            productoEncontrado = catalogo->buscar(entradaLimpia);
                        }
                        
                        if(productoEncontrado != nullptr){
                            //Agregar una copia del producto al carrito
                            nuevoCliente->getCarritoCompras()->insertarFinal(
                                productoEncontrado->getId(),
                                productoEncontrado->getNombre(),
                                productoEncontrado->getPrecio(),
                                productoEncontrado->getCantidad()
                            );
                            cout << "Producto agregado al carrito.\n" << endl;
                        } else {
                            cout << "Producto no encontrado en el catalogo.\n" << endl;
                        }
                    }
                }
                
                colaClientes->insertar(nuevoCliente);
                cout << "Cliente agregado exitosamente a la cola.\n" << endl;
                break;
            }
            
            case 3: {
                //Eliminar cliente (atender cliente)
                if(colaClientes->estaVacia()){
                    cout << "La cola de clientes esta vacia.\n" << endl;
                    break;
                }
                
                Cliente* clienteAtendido = colaClientes->eliminar();
                
                cout << "\n=== REPORTE DE CLIENTE ATENDIDO ===" << endl;
                clienteAtendido->imprimir();
                cout << "\n--- PRODUCTOS EN EL CARRITO ---" << endl;
                clienteAtendido->getCarritoCompras()->imprimir();
                
                double total = clienteAtendido->calcularTotal();
                cout << "\n--- RESUMEN DE MONTO ---" << endl;
                Producto* actual = clienteAtendido->getCarritoCompras()->getPrimero();
                while(actual != nullptr){
                    double subtotal = actual->getPrecio() * actual->getCantidad();
                    cout << actual->getNombre() << ": $" << actual->getPrecio() 
                         << " x " << actual->getCantidad() << " = $" << subtotal << endl;
                    actual = actual->getSiguiente();
                }
                cout << "\nTOTAL: $" << total << endl;
                cout << "===================================\n" << endl;
                
                delete clienteAtendido;
                break;
            }
            
            case 4: {
                //Ordenar productos de un cliente
                if(colaClientes->estaVacia()){
                    cout << "La cola de clientes esta vacia.\n" << endl;
                    break;
                }
                
                string cedula;
                cout << "\n--- ORDENAR PRODUCTOS DE CLIENTE ---" << endl;
                cout << "Ingrese la cedula del cliente: ";
                cin.ignore();
                getline(cin, cedula);
                
                Cliente* cliente = colaClientes->buscarPorCedula(cedula);
                if(cliente == nullptr){
                    cout << "Cliente no encontrado.\n" << endl;
                    break;
                }
                
                if(cliente->getCarritoCompras()->getPrimero() == nullptr){
                    cout << "El carrito del cliente esta vacio.\n" << endl;
                    break;
                }
                
                int atributo, algoritmo, orden;
                cout << "\nSeleccione el atributo de ordenamiento:" << endl;
                cout << "1. ID" << endl;
                cout << "2. Nombre" << endl;
                cout << "3. Precio" << endl;
                cout << "4. Cantidad" << endl;
                cout << "Opcion: ";
                cin >> atributo;
                
                if(atributo < 1 || atributo > 4){
                    cout << "Error: Atributo invalido.\n" << endl;
                    break;
                }
                
                cout << "\nSeleccione el algoritmo de ordenamiento:" << endl;
                cout << "1. Seleccion" << endl;
                cout << "2. Mezcla (Merge Sort)" << endl;
                cout << "Opcion: ";
                cin >> algoritmo;
                
                cout << "\nSeleccione el orden:" << endl;
                cout << "1. Ascendente" << endl;
                cout << "2. Descendente" << endl;
                cout << "Opcion: ";
                cin >> orden;
                
                bool ascendente = (orden == 1);
                
                if(algoritmo == 1){
                    cliente->getCarritoCompras()->ordenarPorSeleccion(atributo, ascendente);
                } else if(algoritmo == 2){
                    cliente->getCarritoCompras()->ordenarPorMezcla(atributo, ascendente);
                } else {
                    cout << "Error: Algoritmo invalido.\n" << endl;
                }
                break;
            }
            
            case 5: {
                //Buscar producto en lista de un cliente
                if(colaClientes->estaVacia()){
                    cout << "La cola de clientes esta vacia.\n" << endl;
                    break;
                }
                
                string cedula;
                cout << "\n--- BUSCAR PRODUCTO EN CLIENTE ---" << endl;
                cout << "Ingrese la cedula del cliente: ";
                cin.ignore();
                getline(cin, cedula);
                
                Cliente* cliente = colaClientes->buscarPorCedula(cedula);
                if(cliente == nullptr){
                    cout << "Cliente no encontrado.\n" << endl;
                    break;
                }
                
                if(cliente->getCarritoCompras()->getPrimero() == nullptr){
                    cout << "El carrito del cliente esta vacio.\n" << endl;
                    break;
                }
                
                int atributo, tipoBusqueda;
                cout << "\nSeleccione el atributo de busqueda:" << endl;
                cout << "1. ID" << endl;
                cout << "2. Nombre" << endl;
                cout << "3. Precio" << endl;
                cout << "4. Cantidad" << endl;
                cout << "Opcion: ";
                cin >> atributo;
                
                if(atributo < 1 || atributo > 4){
                    cout << "Error: Atributo invalido.\n" << endl;
                    break;
                }
                
                cout << "\nSeleccione el tipo de busqueda:" << endl;
                cout << "1. Lineal" << endl;
                cout << "2. Binaria" << endl;
                cout << "Opcion: ";
                cin >> tipoBusqueda;
                
                Producto* encontrado = nullptr;
                
                if(atributo == 1){ // ID
                    int valor;
                    cout << "Ingrese el ID a buscar: ";
                    cin >> valor;
                    if(tipoBusqueda == 1){
                        encontrado = cliente->getCarritoCompras()->busquedaLineal(atributo, valor);
                    } else {
                        encontrado = cliente->getCarritoCompras()->busquedaBinaria(atributo, valor);
                    }
                } else if(atributo == 2){ // Nombre
                    string valor;
                    cout << "Ingrese el nombre a buscar: ";
                    cin.ignore();
                    getline(cin, valor);
                    if(tipoBusqueda == 1){
                        encontrado = cliente->getCarritoCompras()->busquedaLineal(atributo, valor);
                    } else {
                        encontrado = cliente->getCarritoCompras()->busquedaBinaria(atributo, valor);
                    }
                } else if(atributo == 3){ // Precio
                    double valor;
                    cout << "Ingrese el precio a buscar: $";
                    cin >> valor;
                    if(tipoBusqueda == 1){
                        encontrado = cliente->getCarritoCompras()->busquedaLineal(atributo, valor);
                    } else {
                        encontrado = cliente->getCarritoCompras()->busquedaBinaria(atributo, valor);
                    }
                } else if(atributo == 4){ // Cantidad
                    int valor;
                    cout << "Ingrese la cantidad a buscar: ";
                    cin >> valor;
                    if(tipoBusqueda == 1){
                        encontrado = cliente->getCarritoCompras()->busquedaLineal(atributo, valor);
                    } else {
                        encontrado = cliente->getCarritoCompras()->busquedaBinaria(atributo, valor);
                    }
                }
                
                if(encontrado != nullptr){
                    cout << "\nProducto encontrado:" << endl;
                    encontrado->imprimir();
                }
                break;
            }
            
            case 6: {
                //Imprimir lista de productos de un cliente
                if(colaClientes->estaVacia()){
                    cout << "La cola de clientes esta vacia.\n" << endl;
                    break;
                }
                
                string cedula;
                cout << "\n--- LISTA DE PRODUCTOS DE CLIENTE ---" << endl;
                cout << "Ingrese la cedula del cliente: ";
                cin.ignore();
                getline(cin, cedula);
                
                Cliente* cliente = colaClientes->buscarPorCedula(cedula);
                if(cliente == nullptr){
                    cout << "Cliente no encontrado.\n" << endl;
                    break;
                }
                
                cout << "\nInformacion del cliente:" << endl;
                cliente->imprimir();
                cout << "\n";
                cliente->getCarritoCompras()->imprimir();
                break;
            }
            
            case 7: {
                //Imprimir catálogo
                cout << "\n--- CATALOGO DE PRODUCTOS ---" << endl;
                catalogo->imprimir();
                break;
            }
            
            case 8: {
                //Salir del sistema
                cout << "\nCerrando sistema..." << endl;
                continuar = false;
                break;
            }
            
            default: {
                cout << "\nOpcion invalida. Por favor, seleccione una opcion del 1 al 8." << endl;
                break;
            }
        }
        
        if(continuar){
            cout << "\nPresione Enter para continuar...";
            cin.ignore();
            cin.get();
        }
    }
    
    //Liberar memoria de todas las estructuras de datos
    cout << "\nLiberando memoria..." << endl;
    
    //Eliminar todos los clientes restantes
    while(!colaClientes->estaVacia()){
        Cliente* cliente = colaClientes->eliminar();
        delete cliente;
    }
    
    delete colaClientes;
    delete catalogo;
    
    cout << "Memoria liberada correctamente. Hasta luego!" << endl;
}

//Función main() que invoca el menú
int main(){
    menu();
    return 0;
}

