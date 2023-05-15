#include <bits/stdc++.h>

using namespace std;

//Juan Angel López Delgadillo

// vamos a hacer una fuunción que cuenta los desplazamientos necesarios al recibir una cadena y un password

int shift_counter(string s, string p) {
    int count = 0;
    for (int i = 0; i <= 25; i++) {
        string decrypted = "";
        // Itera a través de cada carácter de la cadena de entrada p
        for (int j = 0; j < p.length(); j++) {
                // Convierte el carácter a un número entero entre 0 y 25 y aplicamos el dezplazamiento..
            char c = p[j] - 'A'; 
            c = (c + i) % 26; //tecnicamente es 25 aqui :v
            decrypted += c + 'A'; //Conversion 

        }

        //buscamos en la cadena s 
        int found = s.find(decrypted);
            // Si la cadena desencriptada está en la cadena de entrada s
        if (found != string::npos) {
            //Se busca la ocurrencia y si coinciden se aumenta el contador.
            int second_found = s.find(decrypted, found+1);
            if (second_found == string::npos) {
                count++;

            }
        }
    } 
    return count;
}

int main() {
    string s = "TEVMW";
    string p = "PARIS";

    int shifts = shift_counter(s, p);

        cout << shifts << endl;
        
    return 0;
}