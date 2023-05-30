#include<bits/stdc++.h>

using namespace std;

//Juan Angel López Delgadillo
//UVA 11459 SnakesandLadders (seprientes y escalera}s :D)


//si el tablero es de 100x100, entonces 100000

int main() {
    int cases;
    cin >> cases;

    while (cases--) {
        int players, snakes, rolls;
        cin >> players >> snakes >> rolls;

        vector<int> positions(players, 1); // Vector que almacena la posición actual de cada jugador
        
            //---------------SERPIENTES----------------------
            vector<int> snakeshead(101, 0); // Vector que representa el tablero y almacena las colas de las serpientes
            vector<int> snakestails(101, 0); // Vector que almacena las cabezas de las serpientes

        for (int i = 0; i < snakes; i++) {
            int head, tail;
            cin >> head >> tail;
            snakeshead[head] = tail; // Asignamos el valor de la cola correspondiente a la cabeza de la serpiente
        }

        vector<int> counterrolls(rolls); // Vector que almacena los resultados de los lanzamientos de dados

        for (int i = 0; i < rolls; i++) {
            cin >> counterrolls[i]; // Lectura de los lanzamientos de dados
        }

        int currentplayer = 0; // Índice del jugador actual
        bool gameover = false; // Variable para indicar si el juego ha terminado

        for (int i = 0; i < rolls; i++) {
            if (gameover) continue; // Si el juego ha terminado, pasamos al siguiente lanzamiento

            int roll = counterrolls[i];
            int newPos = positions[currentplayer] + roll;

            if (newPos > 100) newPos = 100; // Limitamos la posición a 100

            // Si hay una serpiente en la posición actual, actualizamos la posición del jugador
            if (snakeshead[newPos] != 0) {
                positions[currentplayer] = snakeshead[newPos];
            } else {
                positions[currentplayer] = newPos;
            }

            // Verificamos si el jugador ha llegado a la posición 100
            if (positions[currentplayer] == 100) gameover = true;

            currentplayer = (currentplayer + 1) % players; // Pasamos al siguiente jugador
        }

        for (int i = 0; i < players; i++) {
            cout << "Position of player " << i + 1 << " is " << positions[i] << ".\n";
        }
    }

    return 0;
}
