#include <bits/stdc++.h>
using namespace std;

const int maxn = 1003;
int n, m;
int a[maxn][maxn];
long long dp[maxn][maxn];
pair<int, int> pre[maxn][maxn];
string rute;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cin >> a[i][j];
		}
	}
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			dp[i][j] = 1e18;
			pre[i][j] = {-1, -1};
		}
	}
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (i == 0 && j == 0) dp[i][j] = a[i][j];
			else if (i == 0){
				dp[i][j] = dp[i][j-1] + a[i][j];
				pre[i][j] = {i, j-1};
			}
			else if (j == 0){
				dp[i][j] = dp[i-1][j] + a[i][j];
				pre[i][j] = {i-1, j};
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + a[i][j];
				if (dp[i-1][j] > dp[i][j-1]) pre[i][j] = {i-1, j};
				else pre[i][j] = {i, j-1};
			}
		}
	}
	cout << dp[n-1][m-1] << '\n';
	rute = "";
	for (int i=n-1, j=m-1, k=0; k<n+m-2; k++){
		auto p = pre[i][j];
		if (p.first < i) rute.push_back('B');
		else rute.push_back('K');
		i = p.first;
		j = p.second;
	}
	reverse(rute.begin(), rute.end());
	cout << rute << '\n';
	return 0;
}