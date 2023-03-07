#include <iostream>

//Juan Angel López Delgadillo

#include <vector>

using namespace std;
const int MAXN = 1e5 + 5;
int n, q;       //Input del programa
int a[MAXN];    //valores del arbol
vector<int> adj[MAXN];      //lista de adjacencia 
int timer;             //tiempo de acceso a los nodos
int tin[MAXN], tout[MAXN];     //vectores de tiempo de acceso para el DFS
int depth[MAXN];              //profundidad del arbol
int up[MAXN][20];             //matriz donde se guardan los ancestros del arbol
long long sum[MAXN];          // el arreglo de las sumas del arbol

// Vamos a implementar el dfs, donde u es el nodo actual y p es el nodo padre del nodo u
void dfs(int u, int p) {
    tin[u] = ++timer;       //contador de tiempo de entrada
    up[u][0] = p;
    for (int i = 1; i < 20; i++) {
        up[u][i] = up[up[u][i-1]][i-1];         //actualizamos la matriz de los ancestros
    }
    for (int v : adj[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;        //vamos descendiendo la profundidad del arbol
        sum[v] = sum[u] + a[v];
        dfs(v, u);                      //recursividad del Dfs
    }
    tout[u] = ++timer;             //actualizamos el tiempo de salida
}

//Vamos a implementar una función booleana para verificar los ancestros
bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

//Nuestro LCA va a explotar la funcion auxiliar en su implementación 
int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = 19; i >= 0; i--) {
        if (!is_ancestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}

//calcula la suma de los valores de los nodos en el camino entre los nodos u y v en el árbol. 
long long get_path_sum(int u, int v) {
    int l = lca(u, v);
    return sum[u] + sum[v] - 2LL * sum[l] + a[l];
}

int main() {
    //Input del programa
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //realizamos el dfs
    dfs(0, 0);
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << get_path_sum(u, v) << '\n';     //Imprimimos cada suma
    }
    return 0;
}

