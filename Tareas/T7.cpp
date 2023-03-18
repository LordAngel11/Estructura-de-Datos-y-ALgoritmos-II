#include<bits/stdc++.h>

using namespace std;

//Juan Angel Lopez Delgadillo

//Implementación DFS

const int MOD = 1000000007;

//Necesitamos una funcion que reciba un vertice de inicio, una matriz de visitados, de colores, y el grafo G en general
bool is_bipartite(int start, std::vector<bool>& visited, std::vector<int>& colors, const std::vector<std::vector<int>>& graph) {

    //Definimos una pila para recorrer el grafo
    std::stack<int> st;
    bool bipartite = true;
    //Como vamos a empezar a recorrer asignamos un booleano True al inicio y lo guardamos en las visitas
    visited[start] = true;
    colors[start] = 0;
    st.push(start);

    //Mientras la pila no este vacía, lo que va a hacer es lo siguiente:
    while (!st.empty()) {
        int curr = st.top();
        st.pop();
        //Recorre todos los vecinos del vértice de inicio y comprueba si el vecino ya ha sido visitado 
        for (auto vecino : graph[curr]) {
            if (visited[vecino] && colors[curr] == colors[vecino]) {//si son iguales, significa que el grafo no es bipartito
                bipartite = false;  //No es bipartito
                continue;
            }
            if (visited[vecino]){ 
                continue;
            }
            //Si el vecino no ha sido visitado, 
            colors[vecino] = 1 - colors[curr]; //establece su color como el opuesto del color del vértice actual 
            visited[vecino] = true; //lo marca como visitado
            st.push(vecino);    //lo agrega a la pila.
        }
    }
    return bipartite;   //regresa true o false dependiendo si el grafo es booleano o no
}

//Vamos a calcular 2^n mod 
int faux(int n) {
    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans = (ans * 2) % MOD;
    }
    return ans;
}
//Esta funcion la vamos a utilizar para calcular la cantidad de arboles binarios.


//Recibe n vertices del grafo y el grafo G
int count_connected_components(int n, const std::vector<std::vector<int>>& graph) {
    //Inicializamos un vector de visitas de tamaño n
    std::vector<bool> visited(n, false);
    //Inicializamos un vector de colores 
    std::vector<int> colors(n, -1);

    //CONTADORES DE COMPONENTES BIPARTITAS Y COMPONENTES CONECTADAS
    int bipartite_components = 0;
    int connected_components = 0;

    //Estos contadores los vamos a verificar con las funciones anteriores

    //Recorresmos el grafo
    for (int i = 0; i < n; i++) {
        if (visited[i]){
            continue;
        }
        //Verificamos si la componente es bipartita, y si regresa true, entonces se cuenta
        if (is_bipartite(i, visited, colors, graph)) {
            bipartite_components++;
        }
        //en caso contrario, aumentamos las componentes conectadas
        connected_components++;
    }
    //En caso de no haber nada, regresa 0
    if (connected_components != bipartite_components) {
        return 0;
    }
    //regresamos las componentes conectadas por medio de la funcion que calcula el tamaño de los subarboles
    return faux(connected_components);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

        int n, m;
        std::cin >> n >> m;

        std::vector<std::vector<int>> graph(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            std::cin >> u >> v;
            graph[u - 1].push_back(v - 1);
            graph[v - 1].push_back(u - 1);
        }

        std::cout << count_connected_components(n, graph) << '\n';

        return 0;
    }
