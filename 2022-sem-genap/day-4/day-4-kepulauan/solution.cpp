#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+3;
int n, m, q;
int a[maxn];
vector<int> adjl[maxn];
int vis[maxn];
int mn[maxn];
int par[maxn];

void dfs1(int u, int &cur_mn){
	if (vis[u] == 1) return;
	vis[u] = 1;
	cur_mn = min(cur_mn, a[u]);
	for (int v : adjl[u]) dfs1(v, cur_mn);
}

void dfs2(int u, int cur_mn, int p){
	if (vis[u] == 2) return;
	vis[u] = 2;
	mn[u] = cur_mn;
	par[u] = p;
	for (int v : adjl[u]) dfs2(v, cur_mn, p);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> q;
	for (int i=1; i<=n; i++) cin >> a[i];
	for (int i=0; i<m; i++){
		int u, v;
		cin >> u >> v;
		adjl[u].push_back(v);
		adjl[v].push_back(u);
	}
	memset(vis, 0, sizeof vis);
	for (int i=1; i<=n; i++){
		if (!vis[i]){
			int cur_mn = 1e9;
			dfs1(i, cur_mn);
			dfs2(i, cur_mn, i);
		}
	}
	while (q--){
		int u, v;
		cin >> u >> v;
		cout << (par[u] == par[v] ? 0 : mn[u] + mn[v]) << '\n';
	}
	return 0;
}