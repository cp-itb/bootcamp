#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using matrix = array<array<int, 2>, 2>;

const int MOD = 1e9 + 7;

inline matrix mul(matrix A, matrix B) {
    matrix ret;
    for (int i = 0; i < 2; i++) { for (int j = 0; j < 2; j++) ret[i][j] = 0; }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                ret[i][j] = (1LL * ret[i][j] + 1LL * A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return ret;
}

inline matrix fpow(matrix A, ll B) {
    matrix ret;
    ret[0][0] = ret[1][1] = 1;
    ret[0][1] = ret[1][0] = 0;
    while (B) {
        if (B & 1) { ret = mul(ret, A); }
        A = mul(A, A), B >>= 1;
    }
    return ret;
}

inline void solve() {
    ll n, mm;
    cin >> n >> mm;
    int m = (mm % MOD);
    matrix M;
    M[0][0] = M[0][1] = m - 1;
    M[1][0] = 1;
    M[1][1] = 0;
    int a[2] = {m, (int) ((1LL * m * m) % MOD)};
    if (n == 1) { cout << a[0]; }
    else if (n == 2) { cout << a[1]; }
    else {
        matrix PM = fpow(M, n - 2);
        int ans = (1LL * PM[0][0] * a[1] + 1LL * PM[0][1] * a[0]) % MOD;
        if (ans < 0) ans += MOD;
        cout << ans;
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}