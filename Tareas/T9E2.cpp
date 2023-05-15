#include <bits/stdc++.h>

using namespace std;

//Juan Angel López

const int MAXN = 10000;

//Creamos una matriz para representar dos cadenas de caracteres de ADN...
int matrix_dp[MAXN][MAXN];

int max_alineacion(string string1, string string2) {
    int n = string1.length(), m = string2.length();

    //se concatenan con un espacio al principio para hacer coincidir las posiciones de la matriz con los índices
    string1 = " " + string1;
    string2 = " " + string2;

    memset(matrix_dp, 0, sizeof(matrix_dp));

    // inserción o eliminación se tiene un -1 en estos casos
    for (int i = 1; i <= n; i++) {
        matrix_dp[i][0] = matrix_dp[i - 1][0] - 1;
    }

    for (int j = 1; j <= m; j++) {
        matrix_dp[0][j] = matrix_dp[0][j - 1] - 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (string1[i] == string2[j]) {
                //Si los caracteres coinciden, obtenemos +2
                matrix_dp[i][j] = matrix_dp[i - 1][j - 1] + 2;
            } else {
                //caso auxiliar 
                matrix_dp[i][j] = 0;
            }
            //Si no coinciden se van restando -1, de igual forma si se insertan o no
            matrix_dp[i][j] = max(matrix_dp[i][j], matrix_dp[i - 1][j] - 1);
            matrix_dp[i][j] = max(matrix_dp[i][j], matrix_dp[i][j - 1] - 1);
        }
    }

    //realizamos la reconstruccion de la siguiente forma, se sigue el camino de menos penalizacion por la matriz
    int resultado = matrix_dp[n][m];
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (matrix_dp[i][j] == matrix_dp[i - 1][j - 1] + 2 && string1[i] == string2[j]) {
            i--;j--;
        } else if (matrix_dp[i][j] == matrix_dp[i - 1][j] - 1) {
            i--;
        } else {
            j--;
        }
    }

    return resultado;
}

int main() {
    string string1 = "GTAGTTCTAA";
    string string2 = "ATTCAAC";

        cout << max_alineacion(string1, string2) << endl; 

    return 0;
}
