#include <bits/stdc++.h>

using namespace std;

struct s {
    int sum, pre, suf, ans;
};

const int NMAX = 2 * 100 * 1000;

int n, q, k, l, r;
int a[NMAX + 3];
s t[4 * NMAX + 3];

s create(int x) {
    s tmp;
    tmp.sum = tmp.pre = tmp.suf = tmp.ans = x;
    return tmp;
}

s merge(s a, s b) {
    s x;
    x.sum = x.pre = x.suf = x.ans = 0;
    if (a.sum > 0) {
        if (b.sum > 0) {
            x.sum = a.sum + b.sum;
            x.pre = x.suf = x.sum;
        } else {
            x.sum = 0;
            x.pre = max(a.sum, a.sum + b.pre);
            x.suf = b.suf;
        }
    } else {
        x.sum = 0;
        x.pre = a.pre;
        if (b.sum > 0) {
            x.suf = max(b.sum, b.sum + a.suf);
        } else {
            x.suf = b.suf;
        }
    }
    x.ans = max(a.suf + b.pre, max(x.sum, max(a.ans, b.ans)));
    return x;
}

void build(int v, int s, int e) {
    if (s == e) {
        t[v] = create(a[s]);
    } else {
        int m = (s + e) / 2;
        build(2 * v, s, m);
        build(2 * v + 1, m + 1, e);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }
}

s find(int v, int s, int e) {
    if (s > e || l > e || r < s) {
        return create(0);
    }
    if (l <= s && e <= r) {
        return t[v];
    }
    int m = (s + e) / 2;
    return merge(find(2 * v, s, m), find(2 * v + 1, m + 1, e));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> q >> k;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    build(1, 1, 2 * n - 1);
    string tc;
    cin >> tc;
    l = n, r = 2 * n - 1;
    int cnt = 0;
    for (int i = 0; i < (int) tc.size(); i++) {
        if (tc[i] == '?') {
            int z = find(1, 1, 2 * n - 1).ans;
            cout << min(k, z) << "\n";
        } else {
            cnt++;
            if (cnt % n == 0) {
                l += n - 1, r += n - 1;
            } else {
                l--, r--;
            }
        }
    }
    return 0;
}