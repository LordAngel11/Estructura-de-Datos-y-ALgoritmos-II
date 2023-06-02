#include<bits/stdc++.h>

//Juan ANgel López Delgadillo

//UVA-12085 Mobile Casanova

using namespace std;

unsigned int phoneNumbers[100005];

int main()
{
    int numCases, caseNum = 1;
    
    while (cin >> numCases, numCases)
    {
        // Leer los números de teléfono
        for (int i = 0; i < numCases; ++i)
            cin >> phoneNumbers[i];
        phoneNumbers[numCases] = 0; // Nunca coincide con el número anterior
        
        cout << "Case " << caseNum++ << ":\n";
        
        for (int i = 0; i < numCases; ++i)
        {
            if (phoneNumbers[i] + 1 != phoneNumbers[i + 1])
                cout << '0' << phoneNumbers[i] << '\n';
            else
            {
                cout << '0' << phoneNumbers[i] << '-';
                int subsequent = i + 1;
                // Buscar el siguiente número consecutivo en la secuencia
                for (; phoneNumbers[subsequent] + 1 == phoneNumbers[subsequent + 1]; ++subsequent)
                    ;
                unsigned int start = phoneNumbers[i], end = phoneNumbers[subsequent];
                
                // Encontrar el módulo que define la diferencia entre los números
                unsigned int mod = 10;
                for (; start - (start % mod) != end - (end % mod); mod *= 10)
                    ;
                
                // Imprimir el resultado teniendo en cuenta el módulo
                cout << (end % mod) << '\n';
                i = subsequent;
            }
        }
        
        cout << '\n';
    }
    return 0;
}

