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
	for (int i=m; i>0; i--){
		for (int j=i+i; j<=m; j+=i){
			cnt[j] += cnt[i];
		}
	}
	ans = 0;
	for (int i=1; i<=m; i++) ans = max(ans, cnt[i]);
	cout << ans << '\n';
	return 0;
}