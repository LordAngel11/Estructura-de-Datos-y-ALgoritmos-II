#include <bits/stdc++.h>

//Juan Angel López Delgadillo

//UVa 12136 THe schedule of a married man

using namespace std;

// Función para verificar si hay superposición entre dos intervalos de tiempo
bool checkOverlap(int start1, int end1, int start2, int end2) {
    return (max(start1, start2) <= min(end1, end2));
}

int main() {
    int cases;
    cin >> cases;

    for (int caseNum = 1; caseNum <= cases; caseNum++) {
        int start1_hour, start1_min, end1_hour, end1_min;
        int start2_hour, start2_min, end2_hour, end2_min;

        // Leer los tiempos de inicio y fin de las dos reuniones
        scanf("%d:%d %d:%d", &start1_hour, &start1_min, &end1_hour, &end1_min);
        scanf("%d:%d %d:%d", &start2_hour, &start2_min, &end2_hour, &end2_min);

        // Convertir los tiempos a minutos
        int start1 = start1_hour * 60 + start1_min;
        int end1 = end1_hour * 60 + end1_min;
        int start2 = start2_hour * 60 + start2_min;
        int end2 = end2_hour * 60 + end2_min;

        bool isConflict = checkOverlap(start1, end1, start2, end2);

        cout << "Case " << caseNum << ": ";
        if (isConflict) {
            cout << "Mrs Meeting" << endl;
        } else {
            cout << "Hits Meeting" << endl;
        }
    }

    return 0;
}