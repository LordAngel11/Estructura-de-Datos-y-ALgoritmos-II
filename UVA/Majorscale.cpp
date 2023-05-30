#include<bits/stdc++.h>

//Juan Angel López Delgadillo
//UVA 10528

using namespace std;

const string nota[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};

inline int obtenerValor(string n)
{
    // Función para obtener el valor numérico de una nota
    for (int i = 0; i < 12; ++i)
    {
        if (n == nota[i])
            return i;
    }

    return -1;
}

bool esAcordeMayor(bool disponibles[12], int raiz)
{
    const bool mayor[12] = {1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1};

    // Comprueba si un acorde formado a partir de la raíz es mayor
    for (int j = 0; j < 12; ++j)
    {
        if (disponibles[(raiz + j) % 12])
        {
            if (!mayor[j])
                return false;
        }
    }

    return true;
}

int main()
{
    string linea;
    bool disponibles[12];

    while (getline(cin, linea) && linea != "END")
    {
        vector<string> notas;
        istringstream in(linea);
        memset(disponibles, false, sizeof disponibles);

        // Leer las notas de la línea y marcarlas como disponibles
        while (in >> linea)
        {
            notas.push_back(linea);
            disponibles[obtenerValor(linea)] = true;
        }

        int n = 0;
        for (int i = 0; i < 12; ++i)
        {
            // Comprobamos si el acorde formado a partir de la raíz es mayor
            if (esAcordeMayor(disponibles, i))
            {
                if (n++)
                    cout << " ";
                cout << nota[i];
            }
        }

        cout << "\n";
    }

    return 0;
}