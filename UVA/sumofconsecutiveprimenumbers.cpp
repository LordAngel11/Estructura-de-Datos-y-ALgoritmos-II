#include <bits/stdc++.h>
using namespace std;

//Juan Angel López Delgadillo

//UVA 1210 Sum of prime consecutive numbers

bool isComposite[10001];
int primes[10001], result[10001];
int primeCount, sum;

void sieve(int n)
{
    primeCount = 0;
    primes[primeCount++] = 2;

    // Marcar los números compuestos
    for (int i = 3; i <= n; i += 2)
    {
        if (!isComposite[i])
        {
            primes[primeCount++] = i;

            // Marcar los múltiplos de i como compuestos
            if (i <= n / i)
            {
                for (int j = i * i; j <= n; j += i * 2)
                {
                    isComposite[j] = true;
                }
            }
        }
    }
}

void calculateSum()
{
    for (int i = 0; i < primeCount; i++)
    {
        sum = 0;
        for (int j = i; j < primeCount; j++)
        {
            sum += primes[j];

            if (sum > 10001)
            {
                // Si la suma es mayor a 10001, se sale del bucle
                break;
            }

            result[sum]++;
        }
    }
}

int main()
{
    int n;

    sieve(10001);
    calculateSum();

    while (cin >> n && n > 0)
    {
        cout << result[n] << endl;
    }

    return 0;
}
