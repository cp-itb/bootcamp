#include <bits/stdc++.h>
using namespace std;

long long f(long long n, long long a, long long b, long long c){
	long long ab = a / __gcd(a, b) * b;
	long long ac = a / __gcd(a, c) * c;
	long long bc = b / __gcd(b, c) * c;
	long long abc = ab / __gcd(ab, ac) * ac;
	return n/a + n/b + n/c - n/ab - n/ac - n/bc + n/abc;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long l, r, a, b, c;
	cin >> l >> r >> a >> b >> c;
	cout << f(r, a, b, c) - f(l-1, a, b, c) << '\n';
	return 0;
}