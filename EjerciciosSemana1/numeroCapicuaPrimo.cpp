#include <iostream>

using namespace std;

int isPrime(int num)
{
    if (num <= 1)
        return false;

    if (num == 2)
    {
        return true;
    }

    if (num % 2 == 0)
        return false;

    for (int i = 3; i * i <= num; i += 2)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

int isCapicua(int num)
{
    int original = num;
    int reversed = 0;
    while (num > 0)
    {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return original == reversed;
}

int main()
{
    int num;

    cout << "Ingrese un numero: ";
    cin >> num;

    if (isPrime(num) && isCapicua(num))
    {
        cout << "El numero es primo capicua al mismo tiempo" << endl;
    }
    else
    {

        if (isPrime(num))
        {
            cout << "El numero es primo" << endl;
        }
        else
        {
            cout << "El numero no es primo" << endl;
        }

        if (isCapicua(num))
        {
            cout << "El numero es capicua" << endl;
        }
        else
        {
            cout << "El numero no es capicua" << endl;
        }
    }

    return 0;
}