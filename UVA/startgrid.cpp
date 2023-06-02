#include<bits/stdc++.h>

//Juan Angel López Delgadillo
//UVA 12488 Start Grid.

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> start(n + 1);  // Arreglo para almacenar la configuración inicial
        vector<int> finish(n + 1); // Arreglo para almacenar la configuración final

        // Leer la configuración inicial
        for (int i = 1; i <= n; i++)
            cin >> start[i];

        // Leer la configuración final
        for (int i = 1; i <= n; i++)
            cin >> finish[i];

        int swaps = 0; // Contador de intercambios
        int loc, num;  // Variables temporales para almacenar información

        // Recorrer cada elemento de la configuración final
        for (int i = 1; i <= n; i++)
        {
            // Buscar el elemento correspondiente en la configuración inicial
            for (int j = 1; j <= n; j++)
            {
                if (finish[i] == start[j])
                {
                    loc = j; // Almacenar la posición del elemento en la configuración inicial
                    num = finish[i]; // Almacenar el valor del elemento
                    break;
                }
            }

            // Desplazar los elementos en la configuración inicial para colocar el elemento en su posición correcta
            for (int j = loc; j > i; j--)
            {
                start[j] = start[j - 1]; // Desplazar el elemento hacia la derecha
                swaps++; // Incrementar el contador de intercambios
            }

            start[i] = num; // Colocar el elemento en su posición correcta
        }

        cout << swaps << endl; // Imprimir el número de intercambios realizados
    }

    return 0;
}
