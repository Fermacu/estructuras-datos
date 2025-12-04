#include <iostream>

using namespace std;

int main() {
    int tamano;
    
    cout << "Ingrese el tamano del arreglo: ";
    cin >> tamano;
    
    if (tamano <= 0) {
        cout << "Error: El tamano del arreglo debe ser positivo." << endl;
        return 1;
    }
    
    int arreglo[tamano];
    
    cout << "Ingrese " << tamano << " numeros enteros:" << endl;
    for (int i = 0; i < tamano; i++) {
        cout << "Elemento " << (i + 1) << ": ";
        cin >> arreglo[i];
    }
    
    cout << "\nArreglo original: ";
    for (int i = 0; i < tamano; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
    
    for (int i = 0; i < tamano / 2; i++) {
        int temp = arreglo[i];
        arreglo[i] = arreglo[tamano - 1 - i];
        arreglo[tamano - 1 - i] = temp;
    }
    
    cout << "Arreglo invertido: ";
    for (int i = 0; i < tamano; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
    
    return 0;
}
