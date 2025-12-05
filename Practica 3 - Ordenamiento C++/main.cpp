#include <iostream>
using namespace std;

void mostrarMenu();
void llenarArreglo(int arr[], int& n);
void mostrarArreglo(int arr[], int n);
void ordenarArreglo(int arr[], int n);
void quickSort(int arr[], int inicio, int fin);
int particion(int arr[], int inicio, int fin);

int main() {
    int arreglo[100];
    int n = 0;
    int opcion;
    
    cout << "=== SISTEMA DE ORDENAMIENTO QUICK SORT ===" << endl;
    
    do {
        mostrarMenu();
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                llenarArreglo(arreglo, n);
                break;
                
            case 2:
                if(n > 0) {
                    mostrarArreglo(arreglo, n);
                } else {
                    cout << "\nEl arreglo esta vacio. Llene el arreglo primero." << endl;
                }
                break;
                
            case 3:
                if(n > 0) {
                    ordenarArreglo(arreglo, n);
                } else {
                    cout << "\nEl arreglo esta vacio. Llene el arreglo primero." << endl;
                }
                break;
                
            case 4:
                cout << "\nSaliendo del programa..." << endl;
                break;
                
            default:
                cout << "\nOpcion no valida." << endl;
        }
        
    } while(opcion != 4);
    
    return 0;
}

void mostrarMenu() {
    cout << "\n=== MENU ===" << endl;
    cout << "1. Llenar arreglo" << endl;
    cout << "2. Mostrar arreglo" << endl;
    cout << "3. Ordenar arreglo (Quick Sort)" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

void llenarArreglo(int arr[], int& n) {
    cout << "\nIngrese la cantidad de elementos (maximo 100): ";
    cin >> n;
    
    if(n <= 0 || n > 100) {
        cout << "Cantidad invalida. Debe ser entre 1 y 100." << endl;
        n = 0;
        return;
    }
    
    cout << "Ingrese " << n << " numeros enteros:" << endl;
    for(int i = 0; i < n; i++) {
        cout << "Elemento [" << i << "]: ";
        cin >> arr[i];
    }
    
    cout << "Arreglo llenado exitosamente!" << endl;
}

void mostrarArreglo(int arr[], int n) {
    cout << "\nArreglo: [";
    for(int i = 0; i < n; i++) {
        cout << arr[i];
        if(i < n - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

void ordenarArreglo(int arr[], int n) {
    cout << "\nArreglo antes de ordenar: ";
    mostrarArreglo(arr, n);
    
    quickSort(arr, 0, n - 1);
    
    cout << "Arreglo despues de ordenar: ";
    mostrarArreglo(arr, n);
    cout << "Ordenamiento completado!" << endl;
}

// Algoritmo Quick Sort - divide y venceras
void quickSort(int arr[], int inicio, int fin) {
    if(inicio >= fin) {
        return;  // caso base
    }
    
    int indicePivote = particion(arr, inicio, fin);
    
    // ordenar la parte izquierda
    quickSort(arr, inicio, indicePivote - 1);
    
    // ordenar la parte derecha
    quickSort(arr, indicePivote + 1, fin);
}

// Funcion de particion - separa menores y mayores del pivote
int particion(int arr[], int inicio, int fin) {
    int pivote = arr[fin];  // elijo el ultimo como pivote
    int i = inicio - 1;
    
    // recorro el arreglo y muevo los menores a la izquierda
    for(int j = inicio; j < fin; j++) {
        if(arr[j] <= pivote) {
            i++;
            // intercambio
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    // pongo el pivote en su lugar final
    int temp = arr[i + 1];
    arr[i + 1] = arr[fin];
    arr[fin] = temp;
    
    return i + 1;
}

