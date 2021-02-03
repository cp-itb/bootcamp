#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] " 

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<bool> vis(m + 1);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        for (int j = l; j <= r; j++) {
            vis[j] = 1;
        }
    }
    vector<int> ans(m + 1, -1);
    int maks = 0, last = 0;
    for (int i = m; i >= 1; i--) {
        if (vis[i]) {
            last = 0;
            continue;
        }
        ++last;
        if (last > maks) {
            for (int j = maks + 1; j <= last; j++) {
                ans[j] = i + j - 1;
            }
            maks = last;
        }
    }
    while (q--) {
        int k;
        cin >> k;
        if (ans[k] == -1) {
            cout << -1 << ' ' << -1 << '\n';
            continue;
        }
        cout << ans[k] - k + 1 << ' ' << ans[k] << '\n'; 
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}