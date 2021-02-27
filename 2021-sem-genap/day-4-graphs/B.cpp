#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+3;
int n, a[maxn];
long long c[maxn];
int state[maxn]; // 0 belum proses, 1 lagi proses, 2 udah proses
long long ans = 0;

void dfs(int u){
	state[u] = 1;
	if (state[a[u]] == 0){
		dfs(a[u]);
	}
	else if (state[a[u]] == 1){
		// a[u]..u itu cycle, taruh mousetrap
		int cur = a[u];
		long long mn = 1e18;
		while (cur != u){
			mn = min(mn, c[cur]);
			cur = a[cur];
		}
		mn = min(mn, c[cur]);
		ans += mn;
	}
	state[u] = 2;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	for (int i=1; i<=n; i++) cin >> c[i];
	for (int i=1; i<=n; i++) cin >> a[i];
	memset(state, 0, sizeof state);
	for (int u=1; u<=n; u++){
		if (state[u] == 0) dfs(u);
	}
	cout << ans << "\n";
}