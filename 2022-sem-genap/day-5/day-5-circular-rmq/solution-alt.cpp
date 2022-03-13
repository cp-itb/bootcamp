// author: Jauhar Wibisono

#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+3;
int n, q;
long long a[maxn];
long long tree[4*2*maxn], lazy[4*2*maxn];

vector<int> parse(string &s){
	vector<int> ret;
	for (int l=0; l<(int)s.length(); ){
		int r = l;
		while (r < (int)s.length() && s[r] != ' ') r++;
		ret.push_back(stoi(s.substr(l, r-l)));
		l = r+1;
	}
	return ret;
}

void build(int l, int r, int v){
	if (l == r) tree[v] = a[l%n];
	else{
		int mid = (l+r)/2;
		build(l, mid, v*2);
		build(mid+1, r, v*2+1);
		tree[v] = min(tree[v*2], tree[v*2+1]);
	}
}

void push(int v){
	lazy[v*2] += lazy[v];
	lazy[v*2+1] += lazy[v];
	tree[v*2] += lazy[v];
	tree[v*2+1] += lazy[v];
	lazy[v] = 0;
}

void update(int l, int r, int v, int lb, int rb, long long val){
	if (r < lb || l > rb) return;
	if (l >= lb && r <= rb) tree[v] += val, lazy[v] += val;
	else{
		push(v);
		int mid = (l+r)/2;
		update(l, mid, v*2, lb, rb, val);
		update(mid+1, r, v*2+1, lb, rb, val);
		tree[v] = min(tree[v*2], tree[v*2+1]);
	} 
}

long long query(int l, int r, int v, int lb, int rb){
	if (r < lb || l > rb) return 1e18;
	if (l >= lb && r <= rb) return tree[v];
	push(v);
	int mid = (l+r)/2;
	return min(query(l, mid, v*2, lb, rb), query(mid+1, r, v*2+1, lb, rb));
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	build(0, 2*n-1, 1);
	memset(lazy, 0, sizeof lazy);
	cin >> q;
	cin.ignore();
	while (q--){
		string s;
		getline(cin, s);
		vector<int> isi = parse(s);
		if (isi.size() == 2){
			int l = isi[0], r = isi[1];
			if (r < l) r += n;
			cout << query(0, 2*n-1, 1, l, r) << '\n';
		}
		else{
			int l = isi[0], r = isi[1];
			long long v = isi[2];
			if (l <= r){
				update(0, 2*n-1, 1, l, r, v);
				update(0, 2*n-1, 1, l+n, r+n, v);
			}
			else{
				update(0, 2*n-1, 1, 0, r, v);
				update(0, 2*n-1, 1, l, r+n, v);
				update(0, 2*n-1, 1, l+n, 2*n-1, v);
			}
		}
		// for (int i=0; i<2*n; i++) cout << query(0, 2*n-1, 1, i, i) << ' ';
		// cout << '\n';
	}
	return 0;
}