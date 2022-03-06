#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+3;

int n, m, s, t;
vector<int> adjl[maxn];
int dist[maxn][2];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> s >> t;
	for (int i=0; i<m; i++){
		int u, v;
		cin >> u >> v;
		adjl[u].push_back(v);
		adjl[v].push_back(u);
	}
	memset(dist, -1, sizeof dist);
	queue<pair<pair<int, int>, int>> q;
	q.push({{s, 0}, 0});
	while (!q.empty()){
		int u = q.front().first.first, p = q.front().first.second, d = q.front().second;
		q.pop();
		if (dist[u][p] != -1) continue;
		dist[u][p] = d;
		for (int v : adjl[u]) q.push({{v, p^1}, d+1});
	}
	cout << (dist[t][0] == -1 ? -1 : dist[t][0]/2) << '\n';
	return 0;
}