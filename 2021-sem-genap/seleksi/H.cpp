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

const int N = 105;

int n, a, b;
bool vis[N];
vector<int> adj[N];

void dfs(int u) {
    vis[u] = 1;
    if (adj[u].empty()) {
        if (u > 1 && !vis[u - 1]) dfs(u - 1);
        if (u < n && !vis[u + 1]) dfs(u + 1);
    } else {
        for (int v : adj[u]) {
            if (vis[v]) continue;
            dfs(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b;
    for (int i = 0; i < b; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
    }
    dfs(1);
    cout << (vis[a] ? "YES" : "NO") << '\n';

    return 0;
}