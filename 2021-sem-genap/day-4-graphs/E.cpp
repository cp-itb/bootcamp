#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e4 + 10;

int n, m;
vector<pair<ll, pii>> edges;
int par[N], sz[N];

int find(int a){
    return (par[a] == a ? a : par[a] = find(par[a]));
}
void make(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}
void init_disjointSet(){
    for (int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    init_disjointSet();
    for (int i=1;i<=m;i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        edges.pb(mp(w, mp(a, b)));
    }
    sort(edges.begin(), edges.end());
    ll ans = 0;
    for (auto edge : edges){
        int a = edge.se.fi;
        int b = edge.se.se;
        ll w = edge.fi;

        if (find(a) == find(b)) continue;
        ans += w;
        make(a, b);
    }
    cout << ans << el;

    return 0;
}