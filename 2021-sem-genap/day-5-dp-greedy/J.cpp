#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N  = 1e5 + 10;

int n;
ll MOD;
vector<int> adj[N];
ll dp[N];
vector<ll> le[N], ri[N];

void init_adj(int node, int p){
    vector<int> nadj;
    for (auto x : adj[node]){
        if (x == p) continue;
        init_adj(x, node);
        nadj.pb(x);
    }
    adj[node].swap(nadj);
}
void dfs_dp(int node, int p){
    dp[node] = 1;
    for (auto x : adj[node]){
        dfs_dp(x, node);
        dp[node] = (dp[node] * (dp[x] + 1)) % MOD;
    }
    int len = adj[node].size();
    le[node].resize(len + 2, 1LL);
    ri[node].resize(len + 2, 1LL);
    for (int i=0;i<len;i++){
        le[node][i + 1] = le[node][i] * (dp[adj[node][i]] + 1) % MOD;
    }
    for (int i=len - 1;i>=0;i--){
        ri[node][i + 1] = ri[node][i + 2] * (dp[adj[node][i]] + 1) % MOD;
    }
}
void dfs_reroot(int node, int p, ll fac){
    dp[node] = dp[node] * fac % MOD;
    int len = adj[node].size();
    for (int i=0;i<len;i++){
        dfs_reroot(adj[node][i], node, ((le[node][i] * ri[node][i + 2] % MOD) * fac + 1) % MOD);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> MOD;
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    init_adj(1, 1);
    dfs_dp(1, 1);
    dfs_reroot(1, 1, 1);
    for (int i=1;i<=n;i++){
        cout << dp[i] << el;
    }

    return 0;
}