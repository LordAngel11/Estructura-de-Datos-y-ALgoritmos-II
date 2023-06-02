#include <iostream>
using namespace std;

//Juan ANgel López Delgadillo 

//Uva 11038 How Many O's 

// Función para contar la cantidad de ceros en un número n
int countZeros(int n) {
    if (n < 0)
        return 0;
    
    int count = 1;          // Inicialmente hay al menos un cero en el número
    int multiplier = 1;     // Multiplicador para calcular la posición de los dígitos
    int tailZeros = 0;      // Cantidad acumulada de ceros en la parte inferior
    
    while (n) {
        if (n % 10 != 0) {
            // Si el dígito actual no es cero, se suman los ceros en las posiciones superiores
            count += (n / 10) * multiplier;
        } else {
            // Si el dígito actual es cero, se suman los ceros en las posiciones superiores
            // y los ceros en la posición actual hasta el número ntail+1
            count += ((n / 10) - 1) * multiplier + (tailZeros + 1);
        }
        
        // Actualizar la cantidad acumulada de ceros en la parte inferior
        tailZeros += n % 10 * multiplier;
        n /= 10;                // Eliminar el dígito más a la derecha
        multiplier *= 10;       // Actualizar el multiplicador
    }
    
    return count;
}

int main() {
    int m, n;
    
    while (cin >> m >> n && (m >= 0 && n >= 0)) {
        // Calcula la cantidad de ceros en el rango [m, n]
        int countN = countZeros(n);
        int countM = countZeros(m - 1);
        
        // Imprime la cantidad de ceros en el rango [m, n]
        cout << countN - countM << endl;
    }
    
    return 0;
}
