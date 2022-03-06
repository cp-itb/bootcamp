#include <bits/stdc++.h>
using namespace std;

const int maxn = 1003, maxm = 1003;
int n, m;
string grid[maxn];
int dr[] = {0, -1, 0, 1}, dc[] = {1, 0, -1, 0};
int ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; i++) cin >> grid[i];
	ans = 0;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (grid[i][j] == '.'){
				ans++;
				queue<pair<int, int>> q;
				q.emplace(i, j);
				while (!q.empty()){
					int r = q.front().first, c = q.front().second;
					q.pop();
					if (r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == '#') continue;
					grid[r][c] = '#';
					for (int k=0; k<4; k++) q.emplace(r + dr[k], c + dc[k]);
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}