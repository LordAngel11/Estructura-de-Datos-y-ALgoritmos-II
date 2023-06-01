#include<bits/stdc++.h>

//Juan Angel Lopez Delgadillo

//Uva Ballot wvaluations 11629 Uhunts

using namespace std;

bool isGuessCorrect(const string& line, map<string, int>& partyVotes) {
    stringstream ss(line);
    string party, sep;
    int sum = 0;

    // Iterar sobre los nombres de los partidos y los separadores "+" en la línea
    do {
        ss >> party >> sep;
        sum += partyVotes[party]; // Sumar los votos del partido al total
    } while (sep == "+");

    int against;
    ss >> against;
    against *= 10; // Convertir el valor "against" a múltiplos de 10
    if (sum == against)
        return sep.find('=') != string::npos; // Verificar igualdad
    else if (sum > against)
        return sep.find('>') != string::npos; // Verificar mayor que
    else // sum < against
        return sep.find('<') != string::npos; // Verificar menor que
}

int main() {
    int numParties, numGuesses;
    cin >> numParties >> numGuesses;

    map<string, int> partyVotes;

    // Leer los votos de los partidos y almacenarlos en el mapa partyVotes
    for (int i = 0; i < numParties; ++i) {
        string partyName;
        int beforeDecimal, afterDecimal;
        char decimalSeparator;
        cin >> partyName >> beforeDecimal >> decimalSeparator >> afterDecimal;
        partyVotes[partyName] = beforeDecimal * 10 + afterDecimal; // Almacenar los votos como múltiplos de 10
    }

    cin.ignore();

    // Procesar los supuestos y determinar si son correctos o incorrectos
    for (int guessNum = 1; guessNum <= numGuesses; ++guessNum) {
        string guess;
        getline(cin, guess);
        cout << "Guess #" << guessNum << " was " <<
            (isGuessCorrect(guess, partyVotes) ? "correct" : "incorrect") << ".\n";
    }

    return 0;
}
