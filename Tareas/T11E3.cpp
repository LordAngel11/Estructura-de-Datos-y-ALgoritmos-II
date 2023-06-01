#include <bits/stdc++.h>
using namespace std;

int m = 1000000007, q = 31;

vector<long long> pi;
vector<long long> hashed_prefixes;

void prehashing(string s){
    for (int i = 1; i < s.size(); i++)
    pi[i] = (pi[i-1] * q) % m;

    for (int i = 0; i < s.size(); i++)
    hashed_prefixes[i+1] = (hashed_prefixes[i] + (s[i] - 'a' + 1) * pi[i]) % m;
}

int main(){
    int n, p;
    string s;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p >> s;
        
        //Hacemos el pre hasheo de la cadena
        pi.assign(s.size(),1);
        hashed_prefixes.assign(s.size()+1,0);
        prehashing(s);

        int count, hash1, hash2, res = 0;
        //Buscamos dividir una subcadena de s en p cadenas iguales
        //estas entonces tendran a lo mas tamano s.size()/p
        for(int i = 1; i <= s.size()/p; i++){
            //Aqui vemos los posibles comienzos para nuestras repeticiones
            //de la subcadena dentro de la cadena original
            for(int j = 0; j <= s.size()-(p*i); j++){
                count = 0;
                //Hasheo para la subcadena actual
                hash1 = (hashed_prefixes[j+i] + m - hashed_prefixes[j])%m;
                hash1 = (hash1*pi[s.size()-j-1])% m;
                //Vamos dando saltos de tamano p
                for(int k = 0; k < p; k++){
                    //Si la cadena se repite aumentamos el contador
                    hash2 = (hashed_prefixes[j+(k*i)+i] + m - hashed_prefixes[j+(k*i)])%m;
                    hash2 = (hash2*pi[s.size()-(j+(k*i))-1])%m;
                    if(hash1 == hash2) count++;
                }
                //Cuando tengamos p repeticiones tenemos una subcadena solucion
                if(count == p) res = i;
            }
        }
        //El tamano regresado seria el tamano de la cadena por la cantidad de veces que se repite
        cout << p*res << endl;
    }
    return 0;
}