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

const int N = 2e5 + 5;

int n;
long long t;
long long a[N];

bool bisa(int x) {
    bool ret = 0;
    for (int i = 1; i + x - 1 <= n; i++) {
        int j = i + x - 1;
        if (a[j] <= 0) ret |= (-a[i] <= t);
        else if (a[i] >= 0) ret |= (a[j] <= t);
        else {
            long long mn = min(2LL * a[j] - a[i], a[j] - 2LL * a[i]);
            ret |= (mn <= t);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l = 0, r = N, ans = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (bisa(m)) {
            l = m + 1;
            ans = m;
        } else {
            r = m - 1;
        }
    }
    cout << ans << '\n';

    return 0;
}