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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    const int N = 2e5 + 5;
    
    int n;
    cin >> n;
    vector<vector<int>> vals(N);
    for (int i = 0; i < n; i++) {
        int a, c;
        cin >> a >> c;
        vals[c].emplace_back(a);
    }
    for (int val = 1; val < N; val++) {
        int len = vals[val].size();
        for (int i = 1; i < len; i++) {
            if (v[i - 1] > v[i]) {
                cout << "NO" << '\n';
                return 0;
            }
        }
    }
    cout << "YES" << '\n'

    return 0;
}