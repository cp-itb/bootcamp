#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+3;
int n;
int x[maxn], y[maxn];
long long ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i=0; i<n; i++) cin >> x[i] >> y[i];
	sort(x, x+n);
	sort(y, y+n);
	for (int i=0; i<n; i++) ans += abs(x[i] - x[n/2]) + abs(y[i] - y[n/2]);
	cout << ans << '\n';
	return 0;
}