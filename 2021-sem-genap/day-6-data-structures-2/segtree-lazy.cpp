#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int INF = 2e9;

int n, q;
int a[N];
int t[4 * N];
int lazy[4 * N];

int merge(int x, int y) {
    return min(x, y);
}

void build(int v, int s, int e) {
    if (s == e) {
        t[v] = a[s];
        return;
    }
    int mid = (s + e) / 2;
    build(v * 2, s, mid);
    build(v * 2 + 1, mid + 1, e);
    t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

void push(int v, int s, int e) {
    if (lazy[v] == 0 || s == e) return;
    t[v * 2] += lazy[v];
    lazy[v * 2] += lazy[v];
    t[v * 2 + 1] += lazy[v];
    lazy[v * 2 + 1] += lazy[v];
    lazy[v] = 0;
}

// adds [l..r] with val
void update(int v, int s, int e, int l, int r, int val) {
    if (l > r) return;
    if (s == l && e == r) {
        lazy[v] += val;
        t[v] += val;
        return;
    }
    push(v, s, e);
    int mid = (s + e) / 2;
    update(v * 2, s, mid, l, min(r, mid), val);
    update(v * 2 + 1, mid + 1, e, max(l, mid + 1), r, val);
    t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

// gets the 'merge' value from [l..r]
int get(int v, int s, int e, int l, int r) {
    if (l > r) return INF;
    if (l <= s && e <= r) return t[v];
    push(v, s, e);
    int mid = (s + e) / 2;
    int p1 = get(v * 2, s, mid, l, min(r, mid));
    int p2 = get(v * 2 + 1, mid + 1, e, max(l, mid + 1), r);
    return merge(p1, p2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    // builds the segtree
    build(1, 1, n);
    cin >> q;
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int l, r;
            cin >> l >> r;
            // get min [l..r]
            cout << get(1, 1, n, l, r) << '\n';
        } else if (tp == 2) {
            int l, r, val;
            cin >> l >> r >> val;
            // adds [l..r] with val
            update(1, 1, n, l, r, val);
        }
    }

    return 0;
}