// author: Jauhar Wibisono

#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+3;
int n, q;
string s;
int pref[maxn];
int mn[4*maxn], mx[4*maxn], lazy[4*maxn];

void build(int l, int r, int v){
	if (l == r) mn[v] = mx[v] = pref[l];
	else{
		int mid = (l+r)/2;
		build(l, mid, v*2);
		build(mid+1, r, v*2+1);
		mn[v] = min(mn[v*2], mn[v*2+1]);
		mx[v] = max(mx[v*2], mx[v*2+1]);
	}
}

void push(int v){
	mn[v*2] += lazy[v];
	mn[v*2+1] += lazy[v];
	mx[v*2] += lazy[v];
	mx[v*2+1] += lazy[v];
	lazy[v*2] += lazy[v];
	lazy[v*2+1] += lazy[v];
	lazy[v] = 0;
}

void update(int l, int r, int v, int lb, int rb, int val){
	if (lb > rb) return;
	if (l > rb || r < lb) return;
	if (l >= lb && r <= rb) mn[v] += val, mx[v] += val, lazy[v] += val;
	else{
		push(v);
		int mid = (l+r)/2;
		update(l, mid, v*2, lb, rb, val);
		update(mid+1, r, v*2+1, lb, rb, val);
		mn[v] = min(mn[v*2], mn[v*2+1]);
		mx[v] = max(mx[v*2], mx[v*2+1]);
	}
}

int query_max(int l, int r, int v, int lb, int rb){
	if (l > rb || r < lb) return -1e9;
	if (l >= lb && r <= rb) return mx[v];
	push(v);
	int mid = (l+r)/2;
	return max(query_max(l, mid, v*2, lb, rb), query_max(mid+1, r, v*2+1, lb, rb));
}

int query_min(int l, int r, int v, int lb, int rb){
	if (l > rb || r < lb) return 1e9;
	if (l >= lb && r <= rb) return mn[v];
	push(v);
	int mid = (l+r)/2;
	return min(query_min(l, mid, v*2, lb, rb), query_min(mid+1, r, v*2+1, lb, rb));
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q >> s;
	pref[0] = 0;
	for (int i=1; i<=n; i++) pref[i] = pref[i-1] + (s[i-1] == '+' ? 1 : -1);
	build(0, n, 1);
	memset(lazy, 0, sizeof lazy);
	while (q--){
		int l, r;
		cin >> l >> r;
		if (r < n) update(0, n, 1, r+1, n, -(pref[r] - pref[l-1]));
		int mxl = query_max(0, n, 1, 0, l-1), mxr = (r == n ? -1e9 : query_max(0, n, 1, r+1, n));
		int mnl = query_min(0, n, 1, 0, l-1), mnr = (r == n ? 1e9 : query_min(0, n, 1, r+1, n));
		cout << max(mxl, mxr) - min(mnl, mnr) + 1 << '\n';
		if (r < n) update(0, n, 1, r+1, n, pref[r] - pref[l-1]);
	}
	return 0;
}

/*
8 4
-+--+--+
1 8
2 8
2 5
1 1
*/