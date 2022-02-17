#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	int x, len;
	for (int i=0; i<(int)s.length(); i++){
		if (s[i] == '.'){
			len = (int)s.length()-i-1;
			x = stoi(s.substr(i+1, len));
		}
	}
	int pow10 = 1;
	for (int i=0; i<len; i++) pow10 *= 10;
	cout << pow10 / __gcd(x, pow10) << '\n';
	return 0;
}