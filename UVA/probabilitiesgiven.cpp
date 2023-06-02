#include <bits/stdc++.h>

//JUan Angel López Delgadillo
//UVA Uhunt 11181

using namespace std;

double probabilities[20], results[20] = {}, answer, total;
int numElements, subsetSize, used[20] = {};

//La función dfs realiza un recorrido en profundidad utilizando
//una estrategia de backtracking para generar todos los subconjuntos posibles.

void dfs(int index, int count) {
    // Si la cantidad de elementos restantes más la cantidad de elementos ya seleccionados
    // es menor que el tamaño del subconjunto deseado, se detiene la recursión.
    if (count + numElements - index < subsetSize)
        return;

    // Si se ha alcanzado el tamaño del subconjunto deseado,
    // se calcula la probabilidad acumulada y se actualizan los resultados.
    if (count == subsetSize) {
        double rp = 1;
        for (int i = 0; i < numElements; i++) {
            if (used[i])
                rp *= probabilities[i];
            else
                rp *= (1 - probabilities[i]);
        }
        for (int i = 0; i < numElements; i++)
            if (used[i])
                results[i] += rp;
        total += rp;
        return;
    }

    // Selecciona el elemento actual y realiza la recursión con el siguiente elemento.
    used[index] = 1;
    dfs(index + 1, count + 1);

    // No selecciona el elemento actual y realiza la recursión con el siguiente elemento.
    used[index] = 0;
    dfs(index + 1, count);
}

//Leemos las probabilidades de los elementos del conjuntos
void solve() {
    for (int i = 0; i < numElements; i++) {
        cin >> probabilities[i];
        results[i] = 0;
    }

    total = 0;
    dfs(0, 0);

    for (int i = 0; i < numElements; i++)
        cout << fixed << setprecision(6) << (results[i] / total) << endl;
}

int main() {
    int cases = 0;
    while (cin >> numElements >> subsetSize) {
        if (numElements == 0 && subsetSize == 0)
            break;

        cout << "Case " << ++cases << ":" << endl;
        //Invocamos el solve
        solve();
    }

    return 0;
}