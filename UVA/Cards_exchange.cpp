#include<bits/stdc++.h>

//Juan Angel Lopez Delgadillo 
//UVA 11678 Cards Exchange
using namespace std;


int main() {
    int Alice_deck, Bety_deck, actual, Alice_count, Bety_count;

    while ((cin >> Alice_deck >> Bety_deck) && (Alice_deck || Bety_deck)) {
        Alice_count = Bety_count = 0;
        map<int, bool> deck_cartas;  // Mapa para almacenar las cartas y su disponibilidad

        // Lectura de las cartas de Alice
        for (int i = 0; i < Alice_deck; i++) {
            cin >> actual;

            if (deck_cartas.find(actual) == deck_cartas.end()) {
                Alice_count++;  // Incrementar el contador de cartas únicas de Alice
                deck_cartas[actual] = true;  // Marcar la carta como presente en el mazo de Alice
            }
        }

        // Lectura de las cartas de Betty
        for (int i = 0; i < Bety_deck; i++) {
            cin >> actual;

            map<int, bool>::iterator iter = deck_cartas.find(actual);

            if (iter == deck_cartas.end()) {
                deck_cartas[actual] = false;  // Marcar la carta como presente en el mazo de Betty
                Bety_count++;  // Incrementar el contador de cartas únicas de Betty
            } else if (iter->second) {
                iter->second = false;  // Marcar la carta como ya intercambiada
                Alice_count--;  // Decrementar el contador de cartas únicas de Alice
            }
        }

        cout << (Alice_count < Bety_count ? Alice_count : Bety_count) << '\n';  // Imprimir el resultado
    }

    return 0;
}