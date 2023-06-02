#include<bits/stdc++.h>

// Juan Angel López Delgadillo

// UVA 11651 Getting Gold


using namespace std;


#define MAX 55
#define FLOOR '.'     // Carácter que representa un espacio libre en el laberinto
#define PLAYER 'P'   // Carácter que representa al jugador
#define TRAP 'T'     // Carácter que representa una trampa en el laberinto
#define WALL '#'     // Carácter que representa una pared en el laberinto
#define GOLD 'G'     // Carácter que representa una casilla de oro en el laberinto


int width, height;         // Ancho y alto del laberinto
char grid[MAX][MAX];       // Matriz que representa el laberinto
int visited[MAX][MAX];     // Matriz que indica las casillas visitadas durante el recorrido
int goldCount;             // Contador de casillas de oro encontradas


int dx[4] = {0, 0, 1, -1}; // Arreglos de desplazamiento en las direcciones: derecha, izquierda, abajo, arriba
int dy[4] = {1, -1, 0, 0};


// Función recursiva DFS para explorar el laberinto
void dfs(int x, int y) {
    int i, j, nx, ny;
    visited[x][y] = 1;
    if (grid[x][y] == GOLD)
        goldCount++;   // Si encontramos una casilla de oro, incrementamos el contador
    
    // Comprobamos si hay una trampa en las casillas adyacentes
    for (i = 0; i < 4; i++) {
        nx = x + dx[i]; 
        ny = y + dy[i];
        
        if (grid[nx][ny] == TRAP) {
            // Si encontramos una trampa, exploramos en las 4 direcciones para ver si hay un camino sin trampas
            for (j = 0; j < 4; j++) {
                nx = x + dx[j]; 
                ny = y + dy[j];
                if (!visited[nx][ny] && grid[nx][ny] != TRAP)
                    return;  // Si encontramos un camino sin trampas, retrocedemos
            }
        }
    }
    
    // Exploramos las casillas adyacentes que son pisables (suelo o casilla de oro)
    for (i = 0; i < 4; i++) {
        nx = x + dx[i]; 
        ny = y + dy[i];
        if (!visited[nx][ny] && (grid[nx][ny] == FLOOR || grid[nx][ny] == GOLD))
            dfs(nx, ny);
    }
}

int main() {
    int i, j, playerX, playerY;
    
    while (cin >> width >> height) {
        cin.ignore();   // Ignoramos el salto de línea después de leer el ancho y el alto
        
        // Leemos la matriz del laberinto y encontramos la posición inicial del jugador
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++) {
                grid[i][j] = cin.get();
                visited[i][j] = 0;    // Marcamos todas las casillas como no visitadas
                
                if (grid[i][j] == PLAYER) {
                    playerX = i;
                    playerY = j;
                }
            }
            cin.ignore();   // Ignoramos el salto de línea después de leer una fila del laberinto
        }
        
        goldCount = 0;
        dfs(playerX, playerY);   // Llamamos a la función DFS para explorar el laberinto desde la posición inicial
        
        cout << goldCount << '\n';   // Imprimimos la cantidad de casillas de oro encontradas
    }
    
    return 0;
}
