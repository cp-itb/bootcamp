// author: Jauhar Wibisono

#include <bits/stdc++.h>
using namespace std;

int n, k, a, m;
set<int> st;
int cnt;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k >> a >> m;
	st.insert(0);
	st.insert(n);
	cnt = n/a;
	for (int i=0; i<m; i++){
		int b;
		cin >> b;
		st.insert(b);
		auto it = st.lower_bound(b);
		auto itl = it;
		itl--;
		auto itr = it;
		itr++;
		cnt -= (*itr - *itl) / a;
		cnt += (*it - *itl) / a;
		cnt += (*itr - *it) / a;
		if (cnt < k){
			cout << i << '\n';
			return 0;
		}
	}
	cout << m << '\n';
	return 0;
}