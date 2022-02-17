#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+3;
const long long mod = 998244353;
long long facto[maxn];
long long n, x;

void init(){
	facto[0] = 1;
	for (int i=1; i<maxn; i++) facto[i] = facto[i-1] * i % mod;
}

long long mod_pow(long long aa, long long bb){
	long long ret = 1;
	for (; bb; bb>>=1){
		if (bb&1) ret = ret * aa % mod;
		aa = aa * aa % mod;
	}
	return ret;
}

long long mod_inv(long long aa){
	return mod_pow(aa, mod-2);
}

long long comb(long long aa, long long bb){
	return facto[aa] * mod_inv(facto[aa-bb]) % mod * mod_inv(facto[bb]) % mod;	
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	init();
	cin >> n >> x;
	cout << ((mod_pow(2, n) - comb(n, x) - 1) % mod + mod) % mod << '\n';
	return 0;
}