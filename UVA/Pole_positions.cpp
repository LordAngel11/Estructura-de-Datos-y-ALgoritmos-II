#include<bits/stdc++.h>

//Juan ANgel Lopez Delgadillo
//Uva 12150 Pole Positions

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n) {
        int positions[10005] = {};  // Arreglo para almacenar las posiciones finales de los autos
        int error = 0;  // Variable para indicar si hay un error en la configuración de los autos
        int carNumber, relativePosition, i;
        for (i = 0; i < n; i++) {
            scanf("%d %d", &carNumber, &relativePosition);
            if (i + relativePosition < 0){
             error = 1; 
                }
              // Verificar si la posición final está fuera del rango permitido
            if (i + relativePosition >= n){ error = 1; } // Verificar si la posición final está fuera del rango permitido
            if (!error && positions[i + relativePosition]){ error = 1;}  // Verificar si hay duplicados en las posiciones finales
            if (error){
                continue;
                }
            positions[i + relativePosition] = carNumber;  // Asignar la posición final al auto correspondiente
        }
        if (error) {
            puts("-1");  // Imprimir -1 si hay una configuración inválida
            continue;
        }
        printf("%d", positions[0]);  // Imprimir la posición final del primer auto
        for (i = 1; i < n; i++)
            printf(" %d", positions[i]);  // Imprimir las posiciones finales de los demás autos
        puts("");
    }
    return 0;
}