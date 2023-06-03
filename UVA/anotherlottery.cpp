#include<bits/stdc++.h>

//Juan Angel López Delgadillo

// UVA 11628 Another Lottery..

using namespace std;

//Función para calcular el máximo común divisor utilizando el algoritmo de Euclides
long long int gcd(long long int a, long long int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

int main() {
    //Se declara un vector para almacenar los números de la matriz bidimensional
    vector<long long int> p(1000000);
    int n, m;
    
    while (true) {
        //se leen los valores de n y m 
        cin >> n >> m;
        
        // Si ambos valores son cero, se utiliza return 0 para finalizar el programa
        if (n == 0 && m == 0)
            return 0;
        
        int i, j, k;
        
        // Bucle for para leer los valores de la matriz
        for (i = 0; i < n; i++) {
            // Bucle fir para leer los números anteriores al último número de cada fila
            for (j = 0; j < m - 1; j++)
                cin >> k;
            
            // Se lee el último número de cada fila y se almacena en el vector p
            cin >> k;
            p[i] = k;
        }
        
        // suma total de los números en la matriz
        long long int sum = 0;
        
        //bucle for para calcular la suma total de los números en la matriz
        for (i = 0; i < n; i++)
            sum += p[i];
        
        // Bucle for para calcular la fracción simplificada de cada número en la matriz
        for (i = 0; i < n; i++) {
            //se almacena cada numero en la variable x
            long long int x = p[i];
            
            //si el nummero es diferente de cero, se calcula el máximo común divisor
            if (x) {
                long long int g = gcd(x, sum);
                
                //se imprime la fracción simplificada utilizando cout
                cout << x / g << " / " << sum / g << '\n';
            } else {
                // Si el número es cero, se imprime directamente 0 / 1
                cout << "0 / 1" << '\n';
            }
        }
    }
    
    return 0;
}
