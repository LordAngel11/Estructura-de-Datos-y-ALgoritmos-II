#include <bits/stdc++.h>

    //Juan Angel López Delgadillo
using namespace std;

const int MOD = 1000000007;
const int base_pre = 31;

//Vector de enteros enorme
vector<long long> power_of_base;
vector<long long> hashedprefxs;

//Hashing de polinomios
void prehashing(string s){

    //Primero almacenamos el tamaño de la cadena
    int n = s.size();

    //reajustamos los vectores.
    power_of_base.resize(n + 1);
    hashedprefxs.resize(n + 1);

    power_of_base[0] = 1;

    //Evaluamos en base 31 el polinomio
    for (int i = 1; i <= n; i++)
        power_of_base[i] = (power_of_base[i - 1] * base_pre) % MOD;

    for (int i = 0; i < n; i++)
        hashedprefxs[i + 1] = (hashedprefxs[i] + (s[i] - 'a' + 1) * power_of_base[i]) % MOD;
}

//Funcion para hallar las subcadenas repetidas
void find_repeated_substrings(string s){
    int n = s.size();

    //Recorremos todos los subarreglos 
    for (int i = 1; i <= n / 2; i++){
        //En este caso para subarreglos mayores a la mitad del tamaño no se consideran,
        //dada la iteración

        //contador maximo
        int max_count = 0;
        //Aqui vamos a implementar un hasheo de cada subarreglo
        unordered_map<long long, int> map;

        // Recorremos todos los subarreglos de tamaño i en la cadena s
        for (int j = 0; j + i - 1 < n; j++){
            // Calculamos el valor hash del subarreglo actual
            long long hashed_substr = (hashedprefxs[j + i] - hashedprefxs[j] + MOD) % MOD;
            hashed_substr = (hashed_substr * power_of_base[n - j - i]) % MOD;

            // Si se repite el subarreglo, actualizamos el contador correspondiente en el mapa
            if (map.count(hashed_substr) != 0){
                map[hashed_substr]++;
                max_count = max(max_count, map[hashed_substr]);
            }
            // Si no, creamos una nueva entrada en el mapa con un contador de valor 1
            else{
                map[hashed_substr] = 1;
            }
        }

        // Imprimimos solo si las repeticiones son mayores que 1
        if (max_count > 1){
        cout << max_count << endl;
        }
        
        else break;
    }
}

int main(){
    string s;
    cin >> s;

    prehashing(s);
    find_repeated_substrings(s);

    return 0;
}
