#include<bits/stdc++.h>

//Juan ANgel Lopez Delgadillo
//Uva 11581 Grid Succesors


using namespace std;

int grid[3][3];

// Función para actualizar la cuadrícula
void updateGrid() {
	int newGrid[3][3];

// Aplicar las operaciones en la cuadrícula
	newGrid[0][0] = (grid[0][1] + grid[1][0]) % 2;
	newGrid[0][1] = (grid[0][0] + grid[1][1] + grid[0][2]) % 2;
	newGrid[0][2] = (grid[0][1] + grid[1][2]) % 2;

	newGrid[1][0] = (grid[0][0] + grid[1][1] + grid[2][0]) % 2;
	newGrid[1][1] = (grid[0][1] + grid[1][0] + grid[1][2] + grid[2][1]) % 2;
	newGrid[1][2] = (grid[1][1] + grid[0][2] + grid[2][2]) % 2;

	newGrid[2][0] = (grid[2][1] + grid[1][0]) % 2;
	newGrid[2][1] = (grid[2][0] + grid[1][1] + grid[2][2]) % 2;
	newGrid[2][2] = (grid[2][1] + grid[1][2]) % 2;

// Actualizar la cuadrícula original con los nuevos valore
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			grid[i][j] = newGrid[i][j];
		}
	}
}

// Función para verificar si la cuadrícula está llena de ceros
bool isZeroGrid() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (grid[i][j] > 0)
				return false;
		}
	}
	return true;
}

int main() {
	int testCases;

	scanf("%d", &testCases);

	while (testCases--) {
        // Leer la cuadrícula de entrada
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				scanf("%1d", &grid[i][j]);
			}
		}

		int answer = -1;
		while (!isZeroGrid()) {
			updateGrid();
			answer++;
		}

		printf("%d\n", answer);
	}

	return 0;
}
