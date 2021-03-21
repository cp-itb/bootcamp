#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 5;
const long long INF = 1e18;

int n, q;
long long a[N];
long long lazy[4 * N], t[4 * N];
 
long long merge(long long x, long long y) {
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

void updateRange(int v, int s, int e, int l, int r, long long val) {
    if (l > r) return;
    if (s == l && e == r) {
        lazy[v] += val;
        t[v] += val;
        return;
    }
    push(v, s, e);
    int mid = (s + e) / 2;
    updateRange(v * 2, s, mid, l, min(r, mid), val);
    updateRange(v * 2 + 1, mid + 1, e, max(l, mid + 1), r, val);
    t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

long long queryRange(int v, int s, int e, int l, int r) {
    if (l > r) return INF;
    if (l <= s && e <= r) return t[v];
    push(v, s, e);
    int mid = (s + e) / 2;
    long long p1 = queryRange(v * 2, s, mid, l, min(r, mid));
    long long p2 = queryRange(v * 2 + 1, mid + 1, e, max(l, mid + 1), r);
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
    cin.ignore();
    while (q--) {
        string s;
        getline(cin, s);
        int k1 = -1, k2 = -1;
        long long k3 = INF;
        string cur = "";
        for (int i = 0; i < (int) s.size(); i++) {
            if (s[i] == ' ') {
                if (k1 == -1) {
                    k1 = stoi(cur);
                } else if (k2 == -1) {
                    k2 = stoi(cur);
                }
                cur = "";
            } else {
                cur += s[i];
            }
        }
        if (k1 != -1 && k2 == -1) {
            k2 = stoi(cur);
        } else if (k2 != -1) {
            k3 = stoi(cur);
        }
        if (k3 == INF) {
            if (k1 <= k2) {
                cout << queryRange(1, 1, n, k1 + 1, k2 + 1) << '\n';
            } else {
                cout << min(queryRange(1, 1, n, k1 + 1, n), queryRange(1, 1, n, 1, k2 + 1)) << '\n';
            }
        } else {
            if (k1 <= k2) {
                updateRange(1, 1, n, k1 + 1, k2 + 1, k3);
            } else {
                updateRange(1, 1, n, k1 + 1, n, k3);
                updateRange(1, 1, n, 1, k2 + 1, k3);
            }
        }
    }
 
    return 0;
}