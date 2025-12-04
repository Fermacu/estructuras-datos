#include "ListaProductos.h"
#include <iostream>
using namespace std;

//Rutina menu() que coordina las operaciones del sistema
void menu(){
    ListaProductos* listaProductos = new ListaProductos();
    int opcion;
    bool continuar = true;
    
    while(continuar){
        cout << "\n=== SISTEMA DE GESTION DE PRODUCTOS ===" << endl;
        cout << "1. Insertar producto al final" << endl;
        cout << "2. Buscar producto por nombre" << endl;
        cout << "3. Eliminar producto por nombre" << endl;
        cout << "4. Imprimir todos los productos" << endl;
        cout << "5. Salir del sistema" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch(opcion){
            case 1: {
                //Insertar producto al final
                int id;
                string nombre;
                double precio;
                int cantidad;
                
                cout << "\n--- INSERTAR PRODUCTO ---" << endl;
                cout << "Ingrese el ID del producto: ";
                cin >> id;
                cout << "Ingrese el nombre del producto: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Ingrese el precio del producto: $";
                cin >> precio;
                cout << "Ingrese la cantidad del producto: ";
                cin >> cantidad;
                
                listaProductos->insertarFinal(id, nombre, precio, cantidad);
                break;
            }
            
            case 2: {
                //Buscar producto por nombre
                string nombreBuscar;
                cout << "\n--- BUSCAR PRODUCTO ---" << endl;
                cout << "Ingrese el nombre del producto a buscar: ";
                cin.ignore();
                getline(cin, nombreBuscar);
                
                Producto* encontrado = listaProductos->buscar(nombreBuscar);
                if(encontrado != nullptr){
                    cout << "\nProducto encontrado:" << endl;
                    encontrado->imprimir();
                }
                break;
            }
            
            case 3: {
                //Eliminar producto por nombre
                string nombreEliminar;
                cout << "\n--- ELIMINAR PRODUCTO ---" << endl;
                cout << "Ingrese el nombre del producto a eliminar: ";
                cin.ignore();
                getline(cin, nombreEliminar);
                
                Producto* eliminado = listaProductos->eliminar(nombreEliminar);
                if(eliminado != nullptr){
                    delete eliminado; //Liberar memoria del producto eliminado
                }
                break;
            }
            
            case 4: {
                //Imprimir todos los productos
                cout << "\n--- LISTA DE PRODUCTOS ---" << endl;
                listaProductos->imprimir();
                break;
            }
            
            case 5: {
                //Salir del sistema
                cout << "\nCerrando sistema..." << endl;
                continuar = false;
                break;
            }
            
            default: {
                cout << "\nOpcion invalida. Por favor, seleccione una opcion del 1 al 5." << endl;
                break;
            }
        }
        
        if(continuar){
            cout << "\nPresione Enter para continuar...";
            cin.ignore();
            cin.get();
        }
    }
    
    //Liberar memoria de la lista completa
    delete listaProductos;
    cout << "Memoria liberada correctamente. Hasta luego!" << endl;
}

//Función main() que invoca el menú
int main(){
    menu();
    return 0;
}
