#include<bits/stdc++.h>

//Juan ANgel López Delgadillo

//UVA-11254 COnsecutive integers
using namespace std;

//En este caso se utiliza la suma de la progresión aritmética:
//n = r/2 × (2 × a + r − 1) o a = (2 × n + r − r2)/(2 × r); dado que se conoce n, 
//prueba todos los valores de r desde la raíz cuadrada de 2n hasta 1, 
//detente en el primer a válido

// Función para verificar si el valor de 'a' es válido para la suma
int check_valid(int n, int r)
{
    int a = 2 * n + r - (r * r);
    if (a % (2 * r) == 0)
        return a / (2 * r);
    return -1;
}

int main()
{
    int n;
    while (cin >> n && n >= 0)
    {
        int m = sqrt(2 * n); // Calcular la raíz cuadrada de 2n
        int p = 0;
        for (int i = m; i >= 1; i--)
        {
            int a = check_valid(n, i); // Verificar si hay un valor válido de 'a'
            if (a != -1)
            {
                cout << n << " = " << a << " + ... + " << a + i - 1 << endl;
                break;
            }
        }
    }

    return 0;
}
