#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+3;
int n, m;
vector<pair<int, long long>> adjl[maxn];
priority_queue<pair<long long, int>> pq;
long long dist[maxn];
bool processed[maxn];
int pre[maxn];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<m; i++){
		int a, b; long long w;
		cin >> a >> b >> w;
		adjl[a].emplace_back(b,w);
		adjl[b].emplace_back(a,w);
	}
	// init dist, processed
	for (int i=1; i<=n; i++){
		dist[i] = 1e18;
		processed[i] = false;
	}
	dist[1] = 0;
	pq.emplace(0, 1);
	// dijkstra
	while (!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		if (processed[u]) continue;
		processed[u] = true;
		for (int i=0; i<(int)adjl[u].size(); i++){
			int v = adjl[u][i].first; long long w = adjl[u][i].second;
			if (dist[u]+w < dist[v]){
				dist[v] = dist[u]+w;
				pre[v] = u;
				pq.emplace(-dist[v], v);
			}
		}
	}
	if (!processed[n]) cout << -1 << "\n";
	else{
		vector<int> ans;
		int cur = n;
		while (cur != 1){
			ans.push_back(cur);
			cur = pre[cur];
		}
		ans.push_back(cur);
		reverse(ans.begin(), ans.end());
		for (int i=0; i<(int)ans.size(); i++) cout << ans[i] << " ";
		cout << "\n";
	}
}