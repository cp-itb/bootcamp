#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+3, mod = 1e9+7;

int mod_pow(int a, int b){
	int ret = 1;
	for (int i=0; i<b; i++) ret = 1LL * ret * a % mod;
	return ret;
}

int n, a[maxn];
int ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	ans = 0;
	for (int i=0; i<n; i++) ans = (ans + a[i]) % mod;
	ans = 1LL * ans * mod_pow(2, n-1) % mod;
	cout << ans << '\n';
	return 0;
}