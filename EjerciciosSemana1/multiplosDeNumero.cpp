#include <iostream>

using namespace std;

int main(){
   int num1, num2; 

    cout << "Ingrese un numero entero: ";
    cin >> num1;

    cout << "Ingrese otro numero entero: ";
    cin >> num2;

    if(num1 <= 0 || num2 <= 0){
        cout << "No se puede dividir por cero." << endl;
        return 1;
    }

    cout << "Los primeros " << num1 << " multiplos de " << num2 << " son: ";
    
    for(int i = 1; i <= num1; i++){
        cout << num2 * i << " ";
    }

    return 0;
}