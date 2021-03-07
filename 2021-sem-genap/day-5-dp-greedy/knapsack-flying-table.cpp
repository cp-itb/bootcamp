#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;
const int W = 1e5 + 5;

int n, w;
int a[N], b[N];
long long dp[2][W];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        int now = (i & 1);
        int bfr = !(i & 1);
        for (int j = 0; j <= w; j++) {
            dp[now][j] = dp[bfr][j];
            if (a[i] <= j) {
                dp[now][j] = max(dp[now][j], dp[bfr][j - a[i]] + b[i]);
            }
        }
    }
    cout << dp[(n & 1)][w] << '\n';

    return 0;
}