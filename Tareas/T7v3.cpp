#include <bits/stdc++.h>
using namespace std;

//Juan Angel Lopez Delgadillo

const int MOD = 1000000007;

vector<int> adjList[100005];
int color[100005];

long long int dfs(int u, int c, int &blackCount, int &whiteCount) {
    color[u] = c;
    if(c == 1) blackCount++;
    else whiteCount++;

    long long int cnt = 1;
    for(int v: adjList[u]) {
        if(color[v] == 0) {
            cnt = (cnt * dfs(v, 3-c, blackCount, whiteCount)) % MOD;
        } 
    }

    return (cnt * (1LL << blackCount) % MOD * (1LL << whiteCount) % MOD) % MOD;
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

    memset(color, 0, sizeof(color));
    long long int answer = 1;
    for(int i = 1; i <= n; i++) {
        if(color[i] == 0) {
            int blackCount = 0, whiteCount = 0;
            long long int cnt = dfs(i, 1, blackCount, whiteCount);
            answer = (answer * cnt) % MOD;
        }
    }

    cout << answer << endl;
    return 0;
}
