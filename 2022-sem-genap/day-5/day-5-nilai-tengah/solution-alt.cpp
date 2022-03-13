// author: Jauhar Wibisono

#include <bits/stdc++.h>
using namespace std;

struct node{
	node *l, *r;
	int val;
	node(): l(nullptr), r(nullptr), val(0) {}
	node(int _val): l(nullptr), r(nullptr), val(_val) {}
	node(node *_l, node *_r): l(_l), r(_r), val(0) {
		if (l) val += l->val;
		if (r) val += r->val;
	}
};

typedef node * pnode;

const int maxn = 1e6+3, maxa = 1e9;
int n;
pair<int, pair<int, int>> a[maxn];
pnode roots[maxn];

pnode build(int l, int r){
	// cout << l << ' ' << r << '\n';
	if (l == r) return new node(0);
	int mid = (l+r)/2;
	return new node(build(l, mid), build(mid+1, r));
}

pnode update(int l, int r, pnode p, int pos){
	if (l == r) return new node(p->val + 1);
	int mid = (l+r)/2;
	if (pos <= mid) return new node(update(l, mid, p->l, pos), p->r);
	else return new node(p->l, update(mid+1, r, p->r, pos));
}

int mth_element(int l, int r, pnode p, int m){
	if (l == r) return l;
	int mid = (l+r)/2;
	if (p->l->val >= m) return mth_element(l, mid, p->l, m);
	else return mth_element(mid+1, r, p->r, m - p->l->val);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> a[i].first;
		a[i].second.first = i;
	}
	sort(a+1, a+n+1);
	for (int i=1; i<=n; i++) a[i].second.second = i;
	sort(a+1, a+n+1, [](pair<int, pair<int, int>> aa, pair<int, pair<int, int>> bb){
		return aa.second.first < bb.second.first;
	});
	roots[0] = build(1, maxn);
	for (int i=1; i<=n; i++) roots[i] = update(1, maxn, roots[i-1], a[i].second.second);
	sort(a+1, a+n+1);
	for (int i=1; i<=n; i++){
		if (i&1) cout << a[mth_element(1, maxn, roots[i], i/2+1)].first << '\n';
		else{
			int ans = a[mth_element(1, maxn, roots[i], i/2)].first + a[mth_element(1, maxn, roots[i], i/2+1)].first;
			cout << (ans/2) << ((ans&1) ? ".5" : "") << '\n'; 
		}
	}
	return 0;
}