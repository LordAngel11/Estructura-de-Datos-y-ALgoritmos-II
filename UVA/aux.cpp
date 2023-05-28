#include <bits/stdc++.h>

//Juan Angel López Delgadillo
using namespace std;

int main()
{
    long long n, m;
    while (cin >> n >> m)
    {
        long long result = 1;
        // Calculamos el factorial desde (n - m + 1) hasta n
        for (long long i = n - m + 1; i <= n; i++)
        {
            result *= i; // Multiplicamos cada número del rango
            // Eliminamos los ceros a la derecha del resultado
            while (result % 10 == 0)
                result /= 10;
            // Limitamos el tamaño del número para evitar desbordamientos
            result %= 100000000000;
        }
        // Obtenemos el último dígito del resultado
        cout << result % 10 << endl;
    }
    return 0;
}
