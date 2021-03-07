#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;
const int W = 1e5 + 5;

int n, w;
int a[N], b[N];
long long dp[N][W];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            dp[i][j] = dp[i - 1][j];
            if (a[i] <= j) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i]] + b[i]);
            }
        }
    }
    cout << dp[n][w] << '\n';

    return 0;
}