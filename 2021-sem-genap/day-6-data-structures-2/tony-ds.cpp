#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, q;
int a[N];
int pre[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> q;
    while (q--) {
        int l, r, val;
        cin >> l >> r >> val;
        pre[l] += val;
        pre[r + 1] -= val;
    }
    for (int i = 1; i <= n; i++) {
        pre[i] += pre[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        a[i] = a[i] + pre[i];
        cout << a[i] << " \n"[i == n];
    }

    return 0;
}