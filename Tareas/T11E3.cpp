#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;  //Modulo para cálculos hash
const int BASE = 31;  //base para cálculos hash

vector<long long> power;  // vector de potencias precalculadas de BASE
vector<long long> hashed_prefixes;  //vector de prefijos hash de la cadena

void prehashing(string s){
    int n = s.size();
    power.resize(n);
    hashed_prefixes.resize(n + 1);

    // Aqui lo que hacemos en calcular las potencias de BASE
    power[0] = 1;
    for (int i = 1; i < n; i++){
        power[i] = (power[i-1] * BASE) % MOD;
    }

    //Aqui caalculamos los prefijos hash
    for (int i = 0; i < n; i++){
        hashed_prefixes[i+1] = (hashed_prefixes[i] + (s[i] - 'a' + 1) * power[i]) % MOD;
    }
}

int main(){

    int t;
    cin >> t;

    while (t--) {
        int p;
        string s;
        cin >> p >> s;

        //realizamos el prehashing de la cadena
        prehashing(s);

        //calculamos su tamaño y
        int n = s.size();
        int res = 0;  // su looongitud de la subcadena repetida

        // Busca la longitud de la subcadena repetida
        for (int len = 1; len <= n / p; len++) {
            // Comprueba los posibles puntos de inicio para las repeticiones
            for (int start = 0; start <= n - (p * len); start++) {
                int count = 0;
                long long hash1 = (hashed_prefixes[start + len] + MOD - hashed_prefixes[start]) % MOD;
                hash1 = (hash1 * power[n - start - 1]) % MOD;

                // Verifica las repeticiones de la subcadena
                for (int k = 0; k < p; k++) {
                    long long hash2 = (hashed_prefixes[start + (k * len) + len] + MOD - hashed_prefixes[start + (k * len)]) % MOD;
                    hash2 = (hash2 * power[n - (start + (k * len)) - 1]) % MOD;
                    if (hash1 == hash2)
                        count++;
                }

                //si todas las repeticiones coinciden, 
                if (count == p)
                    res = len; //actualiza la longitud de la subcadena
            }
        }

        // La longitud de la subcadena repetida es la longitud de la cadena original multiplicada por el número de repeticiones
        cout << p * res << endl;
    }

    return 0;
}
