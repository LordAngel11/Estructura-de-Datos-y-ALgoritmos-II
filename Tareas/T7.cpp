#include<bits/stdc++.h>
using namespace std;

//Juan Angel Lopez Delgadillo

#define MOD 1000000007

typedef long long int ll;

//definimos nuestra lista 
vector<int> adjList[100005];
bool visited[100005];  //Vector de TRUE O FALSE si visitamos o no 
int color[100005];
ll blackCount, whiteCount;  //Definimos el conteo de blancos y negros


//Implementacion del dfs con las estructuras hechas previamente
void dfs(int u, int c) {
    visited[u] = true;
    color[u] = c;
    if(c == 1) blackCount++;
    else whiteCount++;

    for(int v: adjList[u]) {
        if(!visited[v]) {
            dfs(v, 3-c);
        } else if(color[v] == c) {
            cout << 0 << endl;
            exit(0);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    ll answer = 1;
    memset(visited, false, sizeof(visited));
    memset(color, 0, sizeof(color));
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            blackCount = whiteCount = 0;
            dfs(i, 1);
            answer = (answer * (ll)(pow(2, blackCount) + pow(2, whiteCount))) % MOD;
        }
    }

    cout << answer << endl;
    return 0;
}