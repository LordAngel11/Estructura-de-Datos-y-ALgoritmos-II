#include <bits/stdc++.h>

//Juan Angel López Delgadillo

//UVA 11728 Another task
using namespace std;

int main() {
    int testCase = 0; // Contador para los casos de prueba
    int targetSum, sum, ans, i, j; // Variables para almacenar la suma objetivo, sumas parciales y resultados

    while (cin >> targetSum && targetSum != 0) { // Leer la suma objetivo hasta que sea 0
        ans = -1; // Valor inicial del resultado
        testCase++; // Incrementar el contador de casos de prueba
        cout << "Case " << testCase << ": "; // Imprimir el número de caso

        if (targetSum == 1) { // Si la suma objetivo es 1, el resultado es 1
            cout << targetSum << endl;
        } else {
            for (i = targetSum - 1; i >= 1; i--) { // Comenzar desde la suma objetivo menos uno e ir decrementando
                sum = i; // Inicializar la suma parcial con el valor actual de i

                for (j = 1; j <= i / 2; j++) { // Calcular las sumas parciales
                    if (i % j == 0) { // Si j es un divisor de i
                        sum += j; // Sumar j a la suma parcial
                    }
                }

                if (sum == targetSum) { // Si la suma parcial es igual a la suma objetivo
                    ans = i; // Asignar el valor de i al resultado
                    break; // Salir del bucle
                }
            }

            cout << ans << endl; // Imprimir el resultado
        }
    }

    return 0;
}