#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i=0; i<n; i++){
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.rbegin(), a.rend());
	vector<int> ans(n);
	for (int i=0; i<n; i++) ans[a[i].second] = i+1;
	for (int i=0; i<n; i++) cout << ans[i] << (i == n-1 ? '\n' : ' ');
	return 0;
}