#include<bits/stdc++.h>

//Juan Angel López Delgadillo 
//UVA  10128 Queue

using namespace std;

int main()
{
    // Usamos 20 porque las consultas de prueba contienen más de 13
    long long dp[20][20][20];
    memset(dp, 0, sizeof(dp));
    dp[1][1][1] = 1; // dp[N][P][R]
    // Suponemos que estamos eligiendo el lugar de la persona más baja
    // Él debe estar en el siguiente lugar delantero, siguiente lugar trasero o en cualquier lugar intermedio
    for (int N = 2; N < 14; N++)
    {
        for (int P = 1; P <= N; P++)
        {
            for (int R = 1; R <= N; R++)
            {
                // Elegir cualquier lugar que no esté en ninguno de los extremos, hay N-2 posiciones
                long long medio = dp[N - 1][P][R] * (N - 2);
                // Cualquier extremo
                long long delante = dp[N - 1][P - 1][R];
                long long detrás = dp[N - 1][P][R - 1];
                dp[N][P][R] = medio + delante + detrás;
            }
        }
    }

    int t, n, p, r;
    cin >> t;
    while (t--)
    {
        cin >> n >> p >> r;
        cout << dp[n][p][r] << endl;
    }

    return 0;
}