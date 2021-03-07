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
const int INF = 1e9 + 10;

int n;
int ar[N];
int lis[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    fill(lis, lis + N, INF);
    lis[0] = 0;
    for (int i=1;i<=n;i++){
        int l = 0, r = n;
        while (l < r){
            int m = (l + r + 1) / 2;
            if (lis[m] <= ar[i]){
                l = m;
            } else{
                r = m - 1;
            }
        }
        lis[l + 1] = min(lis[l + 1], ar[i]);
    }
    int ans = 0;
    for (int i=1;i<=n;i++){
        if (lis[i] != INF) ans = i;
    }
    cout << ans << el;

    return 0;
}