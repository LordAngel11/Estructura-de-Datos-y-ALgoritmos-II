#include<bits/stdc++.h>

//Juan Angel López DElgadillo 

//UVA 11053 Flavius Josephus Reoloaded

using namespace std;

int main() {
    long long n, a, b;

    while (cin >> n >> a >> b) {
        map<int, int> count;  // Mapa para contar la frecuencia de los valores generados
        long long next = 0;  // Valor inicial
        int ret = n;  // Contador de valores únicos antes de repetirse

        while (true) {
            next = (a * (next * next % n) % n + b) % n;  // Cálculo del siguiente valor
            int &v = count[next];  // Referencia al contador del valor actual
            v++;  // Incrementar el contador para el valor actual

            if (v == 2)
                ret--;  // Si el contador es igual a 2, se ha encontrado un valor repetido y se decrementa el contador de valores únicos

            if (v == 3)
                break;  // Si el contador es igual a 3, se ha completado un ciclo y se sale del bucle
        }

        cout << ret << '\n';  // Imprimir la cantidad de valores únicos antes de repetirse
    }

    return 0;
}
