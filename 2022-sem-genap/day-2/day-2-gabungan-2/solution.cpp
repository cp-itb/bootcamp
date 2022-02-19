#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; long long l, r;
	cin >> n >> l >> r;
	vector<long long> a(n);
	for (int i=0; i<n; i++) cin >> a[i];
	long long ans = 0;
	for (int i=1; i<(1<<n); i++){
		long long k = 0;
		for (int j=0; j<n; j++){
			if (i & (1<<j)){
				if (k == 0) k = a[j];
				else k = k / __gcd(k, a[j]) * a[j];
			}
		}
		if (__builtin_popcount(i)&1) ans += r/k - (l-1)/k;
		else ans -= r/k - (l-1)/k;
	}
	cout << ans << '\n';
	return 0;
}