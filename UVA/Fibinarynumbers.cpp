#include<bits/stdc++.h>

//Juan ANgel López Delgadillo

//Uva 763 Fibinary numbers
using namespace std;

int main() {
    char input[110];  // Cadena de entrada para los nuumeros
    int isFirst = 0;  // Variable para controlar si es el primer caso

    while (cin >> input) {  // Leer una cadena de números
        int sum[115] = {};  // Arreglo para almacenar el resultado de la suma
        int i, j, len;

        len = strlen(input);  // Obtener la longitud de la cadena

        // Convertir los caracteres en números y sumarlos al arreglo sum
        for (i = len - 1, j = 0; i >= 0; i--, j++)
            sum[j] += input[i] - '0';

        cin >> input;  // Leer la siguiente cadena de números
        len = strlen(input);  // Obtener la longitud de la cadena

        // Convertir los caracteres en números y sumarlos al arreglo sum
        for (i = len - 1, j = 0; i >= 0; i--, j++)
            sum[j] += input[i] - '0';

        if (isFirst)
            cout << endl;
        isFirst = 1;

        int carry = 0;  // Variable para llevar un seguimiento de las llevadas
        for (i = 0; i <= 110; i++) {
            if (sum[i] && sum[i + 1]) {  // Realizar una llevada si hay números en las posiciones i e i+1
                sum[i]--;
                sum[i + 1]--;
                sum[i + 2]++;
                carry = 1;  // Se realizó una llevada, se activa la bandera
            }
            if (sum[i] > 1) {  // Realizar una llevada si hay un número mayor a 1 en la posición i
                sum[i] -= 2;
                if (i == 0)
                    sum[1]++;
                else if (i == 1)
                    sum[2]++, sum[0]++;
                else
                    sum[i + 1]++, sum[i - 2]++;
                carry = 1;  // Se realizó una llevada, se activa la bandera
            }
            if (i == 109 && carry == 1) {  // Reiniciar el bucle si se realizó una llevada en la última posición
                carry = 0;
                i = -1;
            }
        }

        // Encontrar la posición más alta donde hay un número distinto de cero
        for (i = 110; i > 0; i--) {
            if (sum[i])
                break;
        }

        // Imprimir los números desde la posición más alta hasta la posición 0
        for (; i >= 0; i--)
            cout << sum[i];

        cout << endl;
    }

    return 0;
}
