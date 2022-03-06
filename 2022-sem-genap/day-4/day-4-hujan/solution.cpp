#include <bits/stdc++.h>
using namespace std;

const int maxn = 1003, maxm = 1003;
int n, m;
string grid[maxn];
int dr[] = {0, -1, 0, 1}, dc[] = {1, 0, -1, 0};
int dist[maxn][maxm];
queue<pair<int, int>> q[2];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; i++) cin >> grid[i];
	memset(dist, -1, sizeof dist);
	q[0].emplace(0, 0);
	for (int i=0; !q[i&1].empty(); i++){
		auto &qq = q[i&1];
		while (!qq.empty()){
			int r = qq.front().first, c = qq.front().second;
			qq.pop();
			if (dist[r][c] != -1) continue;
			dist[r][c] = i;
			for (int j=0; j<4; j++){
				int nr = r + dr[j], nc = c + dc[j];
				if (nr < 0 || nc < 0 || nr >= n || nc >= m || dist[nr][nc] != -1) continue;
				int p = grid[nr][nc] != grid[r][c];
				q[(i&1) ^ p].emplace(nr, nc);
			}
		}
	}
	cout << dist[n-1][m-1] << '\n';
	return 0;
}