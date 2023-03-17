#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MAXN = 100005;

vector<int> adj[MAXN];
bool visited[MAXN];
int color[MAXN];
long long blackCount, whiteCount;

void dfs(int u, int c) {
    visited[u] = true;
    color[u] = c;
    if(c == 1) blackCount++;
    else whiteCount++;

    for(int v: adj[u]) {
        if(!visited[v]) {
            dfs(v, 3-c);
        } else if(color[v] == c) {
            cout << 0 << endl;
            exit(0);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    long long answer = 1;
    memset(visited, false, sizeof(visited));
    memset(color, 0, sizeof(color));
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            blackCount = whiteCount = 0;
            dfs(i, 1);
            if(blackCount == 0 && whiteCount == 0) continue;
            if(blackCount == 0 || whiteCount == 0) {
                answer = 2 * answer % MOD;
            } else {
                answer = answer * (1ll << blackCount) % MOD;
                answer = answer * (1ll << whiteCount) % MOD;
            }
        }
    }

    cout << answer << endl;
    return 0;
}
