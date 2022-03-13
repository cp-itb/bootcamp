// author: Jauhar Wibisono

#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+3;
int n;
string s[maxn][2];
map<pair<string, string>, long long> mp;
long long ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i=0; i<n; i++){
		for (int j=0; j<2; j++){
			cin >> s[i][j];
		}
	}
	for (int i=0; i<n; i++) mp[make_pair(s[i][0].substr(0, 2), s[i][1])]++;
	ans = 0;
	for (auto &p : mp){
		string s1 = p.first.first, s2 = p.first.second;
		if (s1 != s2) ans += p.second * mp[make_pair(s2, s1)];
	}
	cout << ans/2 << '\n';
	return 0;
}