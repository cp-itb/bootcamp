#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; i++) cin >> a[i];
	vector<int> ans(n, 1);
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			if (a[j] < a[i]) ans[i]++;
		}
	}
	for (int i=0; i<n; i++) cout << ans[i] << (i == n-1 ? '\n' : ' ');
	return 0;
}