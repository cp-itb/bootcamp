#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+3, maxm = 1e6+3;
int n, m;
int cnt[maxm];
int ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	memset(cnt, 0, sizeof cnt);
	for (int i=0; i<n; i++){
		int a;
		cin >> a;
		cnt[a]++;
	}
	ans = 0;
	for (int i=1; i<=m; i++){
		int tmp = 0;
		for (int j=1; j*j<=i; j++){
			if (i % j == 0){
				tmp += cnt[j];
				if (j * j != i) tmp += cnt[i/j];
			}
		}
		ans = max(ans, tmp);
	} // O(m sqrt(m))
	cout << ans << '\n';
}