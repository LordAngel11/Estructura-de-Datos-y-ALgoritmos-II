#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
const int LOGN = 20;

int N, Q, root;
int val[MAXN], depth[MAXN], par[MAXN][LOGN];
vector<int> adj[MAXN];

void dfs(int u, int p, int d) {
    depth[u] = d;
    par[u][0] = p;
    for (int i = 1; i < LOGN; i++) {
        par[u][i] = par[par[u][i-1]][i-1];
    }
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d+1);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    for (int i = LOGN-1; i >= 0; --i) {
        if (depth[u] - (1<<i) >= depth[v]) {
            u = par[u][i];
        }
    }
    if (u == v) {
        return u;
    }
    for (int i = LOGN-1; i >= 0; --i) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

int dist(int u, int v) {
    int p = lca(u, v);
    return depth[u] + depth[v] - 2*depth[p];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;
    for (int i = 0; i < N; ++i) {
        cin >> val[i];
    }
    for (int i = 0; i < N-1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(root, root, 0);

    while (Q--) {
        int u, v;
        cin >> u >> v;
        int p = lca(u, v);
        long long ans = val[p];
        //new
        if(u != p){
            ans += val[u];
            u = par[u][0];
        }
        if(v != p){
            ans += val[v];
            v = par[v][0];
        }
        //ans += accumulate(val+u, val+depth[u]-depth[p]+u, 0);
        //ans += accumulate(val+v, val+depth[v]-depth[p]+v, 0);
        cout << ans << "\n";
    }

    return 0;

    }