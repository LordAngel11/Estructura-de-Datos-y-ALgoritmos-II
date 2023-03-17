#include<bits/stdc++.h>
using namespace std;

//Juan Angel Lopez Delgadillo

const int mod = 1e9 + 7;

vector<int> adj[100005];
bool visited[100005];
int color[100005];
long long blackCount, whiteCount;

void dfs(int u, int c) {
    visited[u] = true;
    color[u] = c;
    if (c == 1) blackCount++;
    else whiteCount++;

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, 3 - c);
        } else if (color[v] == c) {
            cout << 0 << endl;
            exit(0);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    long long answer = 1;
    memset(visited, false, sizeof(visited));
    memset(color, 0, sizeof(color));
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            blackCount = whiteCount = 0;
            dfs(i, 1);
            answer = (answer * (1LL << blackCount) % mod * (1LL << whiteCount) % mod) % mod;
        }
    }

    cout << answer << endl;

    return 0;
}