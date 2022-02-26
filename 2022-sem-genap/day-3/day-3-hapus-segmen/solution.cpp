#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+3;
int n;
pair<int, int> a[maxn];
int ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i].first >> a[i].second;
	sort(a, a+n, [](pair<int, int> aa, pair<int, int> bb){
		if (aa.second != bb.second) return aa.second < bb.second;
		return aa.first < bb.first;
	});
	int r = -1e9-3;
	ans = 0;
	for (int i=0; i<n; i++){
		if (a[i].first > r){
			ans++;
			r = a[i].second;
		}
	}
	cout << n - ans << '\n';
	return 0;
}