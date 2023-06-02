#include<bits/stdc++.h>

//Juan Angel López Delgadillo 
//UVA  11489 Integer Game.

using namespace std;

int main()
{
    int testCases, caseNumber = 1;
    cin >> testCases;
    cin.ignore();

    while (testCases--)
    {
        int numbers[1001], numOfNumbers = 0;   // Almacena los números no múltiplos de 3
        int numOfMultiplesOf3 = 0;             // Contador de números múltiplos de 3
        int sum = 0;                           // Suma de los números no múltiplos de 3

        // Leer el número como una cadena de caracteres
        string numberStr;
        cin >> numberStr;

        // Recorrer cada dígito del número
        for (char c : numberStr)
        {
            // Convertir el carácter a entero
            int digit = c - '0';

            // Verificar si el dígito es múltiplo de 3
            if (digit % 3 == 0)
                numOfMultiplesOf3++;
            else
            {
                numbers[numOfNumbers++] = digit; // Almacenar el dígito en el arreglo
                sum += digit;                   // Actualizar la suma de los dígitos no múltiplos de 3
            }
        }

        int who;  // 0 representa S, 1 representa T

        if (numOfMultiplesOf3 % 2)
            who = 0;
        else
            who = 1;

        if (sum % 3 != 0)
        {
            int i;
            for (i = 0; i < numOfNumbers; i++)
            {
                if ((sum - numbers[i]) % 3 == 0)
                    break;
            }

            if (i == numOfNumbers)
                who = 1;
            else
                who++;
        }

        cout << "Case " << caseNumber++ << ": ";
        if (who % 2)
            cout << "T" << endl;
        else
            cout << "S" << endl;
    }

    return 0;
}