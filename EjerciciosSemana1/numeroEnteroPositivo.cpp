#include <iostream>
#include <string>

using namespace std;

int main() {
    int numero;
    
    cout << "Ingrese un numero entero positivo: ";
    cin >> numero;
    
    if (numero <= 0) {
        cout << "Error: El numero debe ser positivo." << endl;
        return 1;
    }
    
    string numeroStr = to_string(numero);
    
    cout << "El numero " << numero << " tiene " << numeroStr.length() << " digito(s)." << endl;
    
    return 0;
}
