#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+3;
int n, m;
vector<int> adjl[maxn];
bool vis[maxn];
int ans;

void dfs(int u){
	if (vis[u]) return;
	vis[u] = true;
	for (int v : adjl[u]) dfs(v);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<m; i++){
		int u, v;
		cin >> u >> v;
		adjl[u].push_back(v);
		adjl[v].push_back(u);
	}
	memset(vis, false, sizeof vis);
	ans = 0;
	for (int i=1; i<=n; i++){
		if (!vis[i]){
			ans++;
			dfs(i);
		}
	}
	cout << ans - 1 << '\n';
	return 0;
}