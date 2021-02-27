#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 110;
const ll INF = 1e18;

int n, e, t;
int m;
ll dist[N][N];

void floyd(){
    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> e >> t;
    cin >> m;
    for (int i=1;i<=n;i++){
        fill(dist[i], dist[i] + n + 1, INF);
        dist[i][i] = 0;
    }
    for (int i=1;i<=m;i++){
        int a, b;
        ll d;
        cin >> a >> b >> d;
        dist[a][b] = min(dist[a][b], d);
    }
    floyd();
    int ans = 0;
    for (int i=1;i<=n;i++){
        if (dist[i][e] <= t) ans++;
    }
    cout << ans << el;

    return 0;
}