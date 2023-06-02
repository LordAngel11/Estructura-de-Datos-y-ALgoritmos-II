#include <bits/stdc++.h>
using namespace std;

//Juan Angel López Delgadillo

//Safe Salutations 991 Uva


// Función para calcular el número de Catalan
int calculateCatalan(int n) {
    if (n <= 1){
        return 1;
    }
    int result = 0;
    for (int i = 0; i < n; i++){
        result += calculateCatalan(i) * calculateCatalan(n - i - 1);
    }
    return result;
}

int main() {
    int num;
    bool isFirst = false;

    while (cin >> num) {
        if (isFirst) {
           std::cout << endl;
        }
        isFirst = true;

        // Calcular y mostrar el numero de Catalan para el número dado
        std::cout << "Número de Catalan para " << num << ": " << calculateCatalan(num) << "\n";
    }

    return 0;
}
