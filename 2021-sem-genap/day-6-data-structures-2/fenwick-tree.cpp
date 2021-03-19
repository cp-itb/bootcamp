#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, q;
long long a[N];
long long bit[N];

void add(int x, long long val) {
    // adds from range [x...n] with val
    for ( ; x <= n; x += x & -x)
        bit[x] += val;
}

long long get(int x) {
    long long ret = 0;
    for ( ; x > 0; x -= x & -x)
        ret += bit[x];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        add(i, a[i]);
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        // gets the sum of [l...r]
        cout << get(r) - get(l - 1) << '\n';
    }

    return 0;
}