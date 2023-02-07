#include <bits/stdc++.h>
#define MAXN 200005
#define LOG_MAXN 20
using namespace std;

int n, q, node_val[MAXN], lg2[MAXN];
vector<int> tree[MAXN];
int anc[LOG_MAXN][MAXN];
int level[MAXN];
long long dp[MAXN];

void dfs(int u, int parent) {
  anc[0][u] = parent;
  level[u] = level[parent] + 1;
  for (int i = 1; i <= lg2[level[u]]; i++) {
    anc[i][u] = anc[i-1][anc[i-1][u]];
  }
  for (int i = 0; i < tree[u].size(); i++) {
    int v = tree[u][i];
    if (v != parent) {
      dp[v] = dp[u] + node_val[v];
      dfs(v, u);
    }
  }
}

int LCA(int u, int v) {
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
  return anc[0][u];
}

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) {
    scanf("%d", &node_val[i]);
  }
  for (int i = 0; i < n-1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  dfs(0, -1);
  for (int i = 2; i <= n; i++) {
    lg2[i] = lg2[i/2] + 1;
  }
  while (q--) {
    int u, d;
    scanf("%d%d", &u, &d);
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
