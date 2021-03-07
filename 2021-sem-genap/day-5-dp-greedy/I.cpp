#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;

int n, m;
vector<int> adj[N];
int indeg[N];
int dp[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        indeg[b]++;
    }
    queue<int> q;
    for (int i=1;i<=n;i++){
        if (indeg[i] == 0){
            q.push(i);
        }
    }
    while (!q.empty()){
        int node = q.front();
        q.pop();
        for (auto x : adj[node]){
            dp[x] = max(dp[x], dp[node] + 1);
            if (--indeg[x] == 0){
                q.push(x);
            }
        }
    }
    int ans = 0;
    for (int i=1;i<=n;i++){
        ans = max(ans, dp[i]);
    }
    cout << ans << el;

    return 0;
}