#include <bits/stdc++.h>

//Juan Angel López Delgadillo
// 10895 - Matrix Transpose

using namespace std;

int main() {

  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int m, n;  // dimensión de la matriz
 
  while(cin >> m >> n) {

    // Crear un vector de vectores para almacenar las coordenadas de salida
    auto cordout = new vector<int>[n];
    // Crear un vector de vectores para almacenar la matriz de salida
    auto matout = new vector<int>[n];

    // Leer las filas de la matriz de entrada
    for (int i = 0; i < m; i++) {
      int r;
      cin >> r;

      int col = i;
      int row;
      list<int> aux;
      // Leer las coordenadas de entrada y almacenarlas en cordout
      for (int k = 0; k < r; k++) {
        cin >> row;
        cordout[row - 1].emplace_back(col + 1);
        aux.push_back(row - 1);
      }
      // Leer los números de entrada y almacenarlos en matout
      for (auto place : aux) {
        int item;
        cin >> item;
        matout[place].emplace_back(item);
      }
    }

    // Imprimir las dimensiones de la matriz de salida
    cout << n << " " << m << "\n";

    // Imprimir las coordenadas y los valores de la matriz de salida
    for (int i = 0; i < n; i++) {
      int notEmpty = cordout[i].size();
      cout << notEmpty;
      for (auto elem : cordout[i]) {
        cout << " " << elem;
      }
      cout << "\n";
      for (int j = 0; j < notEmpty; j++) {
        if (j == 0)
          cout << matout[i][j];
        else
          cout << " " << matout[i][j];
      }
      cout << "\n";
    }
    
  }

}
