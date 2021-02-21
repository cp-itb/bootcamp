// Problem: https://www.hackerrank.com/challenges/merging-communities/problem
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5; // don't forget to change constant

int n, q;
int par[N], sz[N];

void make_set(int u) {
    par[u] = u;
    sz[u] = 1;
}

// find parent
int find_set(int x) {
    if (par[x] == x) return x;
    return par[x] = find_set(par[x]);
}

// merge two sets, return true if they are seperate, false otherwise
bool merge_set(int u, int v) {
    int pu = find_set(u), pv = find_set(v);
    if (pu == pv) return false;
    if (sz[pu] < sz[pv]) swap(pu, pv);
    sz[pu] += sz[pv];
    par[pv] = pu;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    // initialize
    for (int i = 1; i <= n; i++) {
        make_set(i);
    }
    while (q--) {
        char tp; cin >> tp;
        if (tp == 'Q') {
            int u; cin >> u;
            cout << sz[find_set(u)] << '\n';
        } else if (tp == 'M') {
            int u, v;
            cin >> u >> v;
            merge_set(u, v);
        }
    }

    return 0;
}