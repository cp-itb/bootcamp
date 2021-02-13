#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 2;
const int K = 12;

int pre[N][K];
int num_prime[N];

void init() {
    for (int i = 2; i < N; i++) {
        if (num_prime[i]) continue;
        for (int j = i; j < N; j += i) {
            num_prime[j]++;
        }
    }
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < K; j++) {
            pre[i][j] = pre[i - 1][j];
        }
        if (num_prime[i] >= K) continue;
        pre[i][num_prime[i]]++;
    }
}

void solve() {
    int a, b, n;
    cin >> a >> b >> n;
    cout << pre[b][n] - pre[a - 1][n] << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}