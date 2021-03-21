#include <bits/stdc++.h>

using namespace std;

const int N = 200 * 1000;

long long a[N + 3], bit[N + 3];
int n, q;

void update(int x, long long val) {
    for ( ; x <= N; x += (x & -x)) {
        bit[x] += val;
    }
}

long long query(int x) {
    long long sum = 0;
    for ( ; x > 0; x -= (x & -x)) {
        sum += bit[x];
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[N - n + i];
        update(N - n + i, a[N - n + i]);
    }
    cin >> q;
    while (q--) {
        int k, l, r;
        cin >> k;
        if (k == 1) {
            cin >> l >> r;
            l = N - n + l, r = N - n + r;
            cout << query(r) - query(l - 1) << "\n";
        } else {
            cin >> l;
            update(N - n, l);
            n++;
        }
    }
    return 0;
}