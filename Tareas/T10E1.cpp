#include<bits/stdc++.h>

using namespace std;

//Juan Angel López Delgadillo

//Usaremos esta estructura para almacenar pares de valores enteros
typedef pair<int, int> ii;

#define MAXN 100010

int main() {

    //declaramos el numero de casos
    int numCases;
    cin >> numCases;

    while (numCases--) {
        //Por cada caso, vamos a ir metiendo cadenas de text y calculando sus longitudes
        string pattern;
        cin >> pattern;
        int patternLength = pattern.length();
        string text = pattern + pattern + "{"; // Duplicamos el patrón y añadimos un carácter especial al final
        int textLength = text.length();

        int suffixArray[MAXN], tempSuffixArray[MAXN], rankArray[MAXN], tempRankArray[MAXN], countArray[MAXN], phiArray[MAXN];
        int longestCommonPrefix[MAXN], previousLongestCommonPrefix[MAXN];

        // Inicializamos el arreglo de rangos y el arreglo de sufijos
        for (int i = 0; i < textLength; i++) {
            rankArray[i] = text[i];
            suffixArray[i] = i;
        }
            //Esto lo hacemos con el objetivo de arreglar sufijos en el arreglo
        auto countSort = [&](int k) {
            int maxValue = max(300, textLength);
            // Se inicializa el arreglo en ceros nuevamente
            fill(countArray, countArray + maxValue, 0);

            // Contamos la frecuencia de los rangos
            for (int i = 0; i < textLength; i++)
                countArray[i + k < textLength ? rankArray[i + k] : 0]++;

            int sum = 0;
            // Calculamos las posiciones finales de los rangos en el arreglo
            for (int i = 0; i < maxValue; i++) {
                int temp = countArray[i];
                countArray[i] = sum;
                sum += temp;
            }

            // Ordenamos los sufijos utilizando los rangos
            for (int i = 0; i < textLength; i++)
                tempSuffixArray[countArray[suffixArray[i] + k < textLength ? rankArray[suffixArray[i] + k] : 0]++] = suffixArray[i];

            // Actualizamos el arreglo de sufijos
            for (int i = 0; i < textLength; i++)
                suffixArray[i] = tempSuffixArray[i];
        };

        // Construcción del arreglo de sufijos utilizando el algoritmo SA-IS
        for (int k = 1; k < textLength; k <<= 1) {
            countSort(k);
            countSort(0);

            tempRankArray[suffixArray[0]] = 0;
            int r = 0;
            for (int i = 1; i < textLength; i++) {
                // Asignamos rangos a los sufijos
                tempRankArray[suffixArray[i]] =
                    (rankArray[suffixArray[i]] == rankArray[suffixArray[i - 1]] && rankArray[suffixArray[i] + k] == rankArray[suffixArray[i - 1] + k]) ? r : ++r;
            }

            // Actualizamos el arreglo de rangos
            for (int i = 0; i < textLength; i++)
                rankArray[i] = tempRankArray[i];
        }

        // Busqueda del sufijo más pequeño que comienza con el patrón original
        for (int i = 0; i <= textLength; i++) {
            if (suffixArray[i] < patternLength) {
                cout << suffixArray[i] + 1 << "\n";
                break;
            }
        }
    }

    return 0;
}
