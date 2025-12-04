#include "Pila.h"
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

//Función para determinar la precedencia de los operadores
int obtenerPrecedencia(char operador){
    if(operador == '*' || operador == '/'){
        return 2;
    }
    else if(operador == '+' || operador == '-'){
        return 1;
    }
    return 0;
}

//Función para verificar si un carácter es un operador
bool esOperador(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

//Función para convertir expresión infija a postfija (RPN)
string infijaAPostfija(string expresion){
    Pila* pilaOperadores = new Pila();
    string postfija = "";
    
    for(int i = 0; i < expresion.length(); i++){
        char c = expresion[i];
        
        //Ignorar espacios
        if(c == ' '){
            continue;
        }
        
        //Si es letra o dígito, agregarlo a la salida
        if(isalnum(c)){
            postfija += c;
            postfija += ' ';
        }
        //Si es paréntesis de apertura
        else if(c == '('){
            pilaOperadores->push(c);
        }
        //Si es paréntesis de cierre
        else if(c == ')'){
            while(!pilaOperadores->estaVacia() && pilaOperadores->peek() != '('){
                postfija += pilaOperadores->pop();
                postfija += ' ';
            }
            if(!pilaOperadores->estaVacia()){
                pilaOperadores->pop();
            }
        }
        //Si es un operador
        else if(esOperador(c)){
            while(!pilaOperadores->estaVacia() && 
                  obtenerPrecedencia(pilaOperadores->peek()) >= obtenerPrecedencia(c)){
                postfija += pilaOperadores->pop();
                postfija += ' ';
            }
            pilaOperadores->push(c);
        }
    }
    
    //Vaciar la pila
    while(!pilaOperadores->estaVacia()){
        postfija += pilaOperadores->pop();
        postfija += ' ';
    }
    
    delete pilaOperadores;
    return postfija;
}

//Función para validar paréntesis balanceados
bool validarParentesis(string expresion){
    Pila* pilaParentesis = new Pila();
    
    for(int i = 0; i < expresion.length(); i++){
        char c = expresion[i];
        
        if(c == '('){
            pilaParentesis->push(c);
        }
        else if(c == ')'){
            if(pilaParentesis->estaVacia()){
                delete pilaParentesis;
                return false;
            }
            pilaParentesis->pop();
        }
    }
    
    bool resultado = pilaParentesis->estaVacia();
    delete pilaParentesis;
    return resultado;
}

//Rutina menu() que coordina las operaciones del sistema
void menu(){
    int opcion;
    bool continuar = true;
    
    while(continuar){
        cout << "\n=== SISTEMA DE PILAS - EXPRESIONES ARITMETICAS ===" << endl;
        cout << "1. Convertir expresion infija a postfija" << endl;
        cout << "2. Validar parentesis balanceados" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();
        
        switch(opcion){
            case 1: {
                string expresion;
                cout << "\nIngrese la expresion infija: ";
                getline(cin, expresion);
                
                if(!validarParentesis(expresion)){
                    cout << "Error: Parentesis no balanceados.\n" << endl;
                    break;
                }
                
                string postfija = infijaAPostfija(expresion);
                cout << "Expresion infija:   " << expresion << endl;
                cout << "Expresion postfija: " << postfija << endl;
                break;
            }
            
            case 2: {
                string expresion;
                cout << "\nIngrese la expresion: ";
                getline(cin, expresion);
                
                if(validarParentesis(expresion)){
                    cout << "Los parentesis ESTAN balanceados.\n" << endl;
                }
                else{
                    cout << "Los parentesis NO ESTAN balanceados.\n" << endl;
                }
                break;
            }
            
            case 3: {
                cout << "\nCerrando sistema..." << endl;
                continuar = false;
                break;
            }
            
            default: {
                cout << "Opcion invalida.\n" << endl;
                break;
            }
        }
        
        if(continuar){
            cout << "\nPresione Enter para continuar...";
            cin.get();
        }
    }
}

//Función main() que invoca el menú
int main(){
    menu();
    return 0;
}

