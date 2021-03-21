#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int INF = 2e9;

int n, q;
int a[N];
int t[4 * N];

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

void update(int v, int s, int e, int pos, int val) {
    if (s == e && s == pos) {
        t[v] = val;
        a[pos] = val;
        return;
    }
    int mid = (s + e) / 2;
    if (pos <= mid)
        update(v * 2, s, mid, pos, val);
    else
        update(v * 2 + 1, mid + 1, e, pos, val);
    t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

int get(int v, int s, int e, int l, int r) {
    if (e < l || s > r) return INF;
    if (l <= s && e <= r) return t[v];
    int mid = (s + e) / 2;
    int p1 = get(v * 2, s, mid, l, r);
    int p2 = get(v * 2 + 1, mid + 1, e, l, r);
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
    build(1, 1, n);
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        ++l, ++r;
        cout << get(1, 1, n, l, r) << '\n';
    }

    return 0;
}