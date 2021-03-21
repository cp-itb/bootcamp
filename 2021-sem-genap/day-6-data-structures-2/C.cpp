#include <bits/stdc++.h>

using namespace std;

int n, m, p, b, a[1 << 18], seg[(1 << 18) * 4];

void build(int pos, int l, int r, bool op) {
    if (l == r) {
        seg[pos] = a[l];
    } else {
        int mid = (l + r) / 2;
        build(pos * 2, l, mid, !op);
        build(pos * 2 + 1, mid + 1, r, !op);

        if (op)
            seg[pos] = seg[pos * 2] | seg[(pos * 2) + 1];
        else
            seg[pos] = seg[pos * 2] ^ seg[(pos * 2) + 1];
    }
}

void update(int pos, int l, int r, bool op, int target) {
    if (l == r) {
        seg[pos] = a[l];
    } else {
        int mid = (l + r) / 2;
        if (target <= mid) {
            update(pos * 2, l, mid, !op, target);
        } else {
            update((pos * 2) + 1, mid + 1, r, !op, target);
        }

        if (op)
            seg[pos] = seg[pos * 2] | seg[(pos * 2) + 1];
        else
            seg[pos] = seg[pos * 2] ^ seg[(pos * 2) + 1];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < (1 << n); i++) {
        cin >> a[i];
    }
    build(1, 0, (1 << n) - 1, n & 1);
    while (m--) {
        cin >> p >> b;
        a[p - 1] = b;
        update(1, 0, (1 << n) - 1, n & 1, p - 1);
        cout << seg[1] << '\n';
    }

    return 0;
}