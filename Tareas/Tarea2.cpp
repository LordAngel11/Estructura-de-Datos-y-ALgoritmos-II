#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000000
#define level 18

vector<int> tree[MAXN];
int depth[MAXN];
int father[MAXN][level];

/*Vamos a precomputar la profundidad del nodo en el arbol y sus 
padres*/



int main(){

//Numero de nodos en el arbol y numero de preguntas a contestar
int N,Q;

std::cin>>N>>Q;

//std::cout<<N << " " <<Q<<std::endl;

int val_nodes[N];

for(int i = 0; i<N; i++){
    std::cin>>val_nodes[i];
}

//En las siguientes N-1 lineas

for(int i = 0; i < N-1; i++){
    int u,v;
    std::cin >> u >> v;
}

//En las siguientes Q lineas.

for(int i = 0; i < Q; i++){
    int u,d;
    std::cin >> u >> d;
}

/*
for (int i = 0; i < N; i++)
{
    std::cout<<arr[i]<<std::endl;
}
*/

}