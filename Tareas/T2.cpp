#include <bits/stdc++.h>

/*Juan Angel López Delgadillo*/

//Definimos nuestras constantes con el objetivo de tener el maximo de nodos en el arbol
#define MAXN 200005
#define LOG_MAXN 20 //Logmax es la cantidad maxima para representar el arbol en binario.
using namespace std;

//n nodos y q querys
int n, q, node_val[MAXN], lg2[MAXN];  //almacenamos los nodos en un arreglo
vector<int> tree[MAXN];     //generamos un vector de enteros
//Aqui es donde vamos a generar una sparsing table en forma de matriz para almacenar los ancestros de cada nodo del arbol
int anc[LOG_MAXN][MAXN];
int level[MAXN]; //Almacenamos el numero de niveles del arbol
long long dp[MAXN]; //almacenamos el valor total de cada nodo


//Vamos a usar esta función de DFS para recorrer el arbol a profundidad
//Mientras recorremos el arbol calculamos el valor d total de cada nodo hasta la raiz
void dfs(int u, int parent) {
  anc[0][u] = parent;
  level[u] = level[parent] + 1;
  for (int i = 1; i <= lg2[level[u]]; i++) {
    anc[i][u] = anc[i-1][anc[i-1][u]];
  }
  for (int i = 0; i < tree[u].size(); i++) {
    int v = tree[u][i];
    if (v != parent) {
      //Aqui vamos almacenando el valor total en el arreglo dp
      dp[v] = dp[u] + node_val[v];
      dfs(v, u);
    }
  }
}
//Ahora dados dos nodos u,v \in N-1 vamos a utilizar el siguiente algoritmo para encontrar
//el ancestro común mas cercano entre dos nodos en el árbol.
int LCA(int u, int v) {
  //Aqui vamos a utilizar el arreglo de los niveles del arbol para hacer unas comparaciones
  if (level[u] < level[v]) swap(u, v);
  int d = level[u] - level[v];
  for (int i = lg2[d]; i >= 0; i--) {
    if (d & (1 << i)) {
      u = anc[i][u];
    }
  }
  if (u == v) return u;
  for (int i = lg2[level[u]]; i >= 0; i--) {
    if (anc[i][u] != anc[i][v]) {
      u = anc[i][u];
      v = anc[i][v];
    }
  }
  //Regresa el ancestro mas cercano al nodo
  return anc[0][u];
}

int main() {
  //Dados n y q se almacena todo lo del input
  std::cin>>n>>q;
  for (int i = 0; i < n; i++) {
    std::cin>>node_val[i];
  }
  for (int i = 0; i < n-1; i++) {
    //Se ingresan los valores u,v
    int u, v;
    std::cin>>u>>v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  dfs(0, -1);
  for (int i = 2; i <= n; i++) {
    lg2[i] = lg2[i/2] + 1;
  }
  while (q--) {
    int u, d;
    std::cin>>u>>d;
    int node = u;
    long long ans = node_val[node];
    while (d-- && node != 0) {
      int p = anc[0][node];
      ans += node_val[p];
      node = p;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
