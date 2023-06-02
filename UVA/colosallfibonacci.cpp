#include <bits/stdc++.h>

//Juan Angel López Delgadillo

//UVA 11582 Colossal Fibonacci numbers
using namespace std;

int testCases;
unsigned long long num1, num2;
int num3;
int fib[1000000 + 500];

// Función para calcular la potencia modular
unsigned long long modPow(unsigned long long base, unsigned long long exponent, unsigned long long modulus)
{
    if (exponent == 0)
        return 1;
    unsigned long long result = modPow(base, exponent / 2, modulus);
    result = (result * result) % modulus;
    if (exponent % 2 == 1)
        result = (result * base) % modulus;
    return result;
}

int main()
{
    cin >> testCases; // Leer el número de casos de prueba
    while (testCases--)
    {
        cin >> num1 >> num2 >> num3; // Leer los valores de num1, num2 y num3
        fib[0] = 0;
        fib[1] = 1 % num3;
        int period = 1;
        // Calcular la secuencia de Fibonacci módulo num3 hasta encontrar un período
        for (int i = 2; i < num3 * num3 + 100; i++)
        {
            fib[i] = (fib[i - 1] + fib[i - 2]) % num3;
            if (fib[i - 1] == fib[0] && fib[i] == fib[1])
            {
                period = i - 1; // Almacenar el tamaño del período
                break;
            }
        }
        // Calcular el resultado final usando potencia modular
        unsigned long long result = modPow(num1 % period, num2, (unsigned long long)period);
        cout << fib[result] << endl; // Imprimir el resultado final
    }

    return 0;
}
