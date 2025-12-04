#include <iostream>

using namespace std;

int main() {
    double num1, num2, resultado;
    char operacion;
    
    cout << "Calculadora de Operaciones Aritmeticas!"<< endl;

    cout << "Ingrese el primer numero: ";
    cin >> num1;

    cout << "Ingrese el segundo numero: ";
    cin >> num2;

    cout << "Ingrese el simbolo de la operacion (+, -, *, /): ";
    cin >> operacion;
    
    switch (operacion) {
        case '+':
            resultado = num1 + num2;
            cout << "El resultado de la suma es: " << num1 << " + " << num2 << " = " << resultado << endl;
            break;
            
        case '-':
            resultado = num1 - num2;
            cout << "El resultado de la resta es: " << num1 << " - " << num2 << " = " << resultado << endl;
            break;
            
        case '*':
            resultado = num1 * num2;
            cout << "El resultado de la multiplicacion es: " << num1 << " * " << num2 << " = " << resultado << endl;
            break;
            
        case '/':
            if (num2 == 0) {
                cout << "No se puede dividir por cero." << endl;
            } else {
                resultado = num1 / num2;
                cout << "El resultado de la division es: " << num1 << " / " << num2 << " = " << resultado << endl;
            }
            break;
            
        default:
            cout << "Operacion invalida. Solo se permiten los simbolos : +, -, *, /" << endl;
            break;
    }
    
    return 0;
}
