#include<bits/stdc++.h>

//Jun angel López Delgadillo

//11987 UVa Uhunt amost union find

using namespace std;

// No se accedera a esto, solo se imprimira al principio
set<int> conjuntosBase[100005];
int suma[100005];

// Comienza con setAccess[i] = i
int accesoConjunto[100005];

void fusionarConjuntos(int valorEnA, int valorEnB) {
    // Solo se maneja si son diferentes
    if (accesoConjunto[valorEnA] != accesoConjunto[valorEnB]) {
        int conjuntoA = accesoConjunto[valorEnA], conjuntoB = accesoConjunto[valorEnB];

        if (conjuntosBase[conjuntoA].size() >= conjuntosBase[conjuntoB].size()) {
            suma[conjuntoA] += suma[conjuntoB];
            conjuntosBase[conjuntoA].insert(conjuntosBase[conjuntoB].begin(), conjuntosBase[conjuntoB].end());

            // Actualizar a dónde apuntan
            for (set<int>::iterator iter = conjuntosBase[conjuntoB].begin(); iter != conjuntosBase[conjuntoB].end(); ++iter) {
                accesoConjunto[*iter] = conjuntoA;
            }
        } else {
            suma[conjuntoB] += suma[conjuntoA];
            conjuntosBase[conjuntoB].insert(conjuntosBase[conjuntoA].begin(), conjuntosBase[conjuntoA].end());

            // Actualizar a dónde apuntan
            for (set<int>::iterator iter = conjuntosBase[conjuntoA].begin(); iter != conjuntosBase[conjuntoA].end(); ++iter) {
                accesoConjunto[*iter] = conjuntoB;
            }
        }
    }
}

void moverEntreConjuntos(int valorEnDesde, int valorEnHacia) {
    // Solo se maneja si son diferentes
    if (accesoConjunto[valorEnDesde] != accesoConjunto[valorEnHacia]) {
        int desde = accesoConjunto[valorEnDesde], hacia = accesoConjunto[valorEnHacia];

        suma[desde] -= valorEnDesde;
        suma[hacia] += valorEnDesde;

        accesoConjunto[valorEnDesde] = hacia;

        conjuntosBase[desde].erase(valorEnDesde);
        conjuntosBase[hacia].insert(valorEnDesde);
    }
}

int main() {
    int n, m;

    while (cin >> n >> m) {
        // reiniciar
        for (int i = 1; i <= n; ++i) {
            accesoConjunto[i] = i;
            conjuntosBase[i].clear();
            conjuntosBase[i].insert(i);
            suma[i] = i;
        }

        while (m--) {
            int tipo, p, q;
            cin >> tipo;
            if (tipo == 1) {
                cin >> p >> q;
                fusionarConjuntos(p, q);
            } else if (tipo == 2) {
                cin >> p >> q;
                moverEntreConjuntos(p, q);
            } else {
                cin >> p;
                int indice = accesoConjunto[p];
                cout << conjuntosBase[indice].size() << ' ' << suma[indice] << '\n';
            }
        }
    }

    return 0;
}