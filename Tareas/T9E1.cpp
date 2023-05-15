#include <bits/stdc++.h>

using namespace std;

//Juan Angel López Delgadillo


//La función de preprocesamiento KMP devuelve un vector de enteros y toma como parámetro una referencia  
//constante de una cadna.
vector<int> preprocesamientoKMP(const string& patrones) {
    int m = patrones.length();

    //Inicializamos un vector de enteros
    vector<int> resets(m + 1, -1); //Tamaño m+1, y valores -1
    //vamoh a contar el numero de subcadenas para matchear
    int i = 0, j = -1;
    while (i < m) {
        while (j >= 0 && patrones[i] != patrones[j]) {
            //se reduce j al valor del jesimo lugar de resets
            j = resets[j];
        }
        //Si patrones[i] == patrones[j], se incrementan ambos indices
        i++, j++;
        resets[i] = j;
    }
    return resets;
    // devuelve un vector contiene los valores de los mayores prefijos que son también sufijos de cada posición en el patrón.
}


//recibe una cadena 
int kmpMatch(const string& s) {
    int n = s.length();
    //guardamos la longitud
    vector<int> resets = preprocesamientoKMP(s);
    //Se almacena el nuevo vector una vez que se preprocesa
    int count = n;
    //Recorremos el vector de resets para contar el numero de subcadenas
    for (int i = 1; i <= n; i++) {
        int j = resets[i];
        while (j != -1) {
            count++;
            j = resets[j];
        }
    }
    return count;
}


int main() {

    string s;
        std::cin>>s; 

    int count_subcadenas = kmpMatch(s);
        cout << count_subcadenas << endl; 

    return 0;
}