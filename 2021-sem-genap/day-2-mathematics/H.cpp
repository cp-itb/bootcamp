#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using matrix = vector<vector<int>>;

const int MOD = 1e9 + 7;

matrix F;
int n, m;

matrix mul(matrix A, matrix B) {
    int n = (int)A.size();
    matrix ret(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                ret[i][j] = (1LL * ret[i][j] + 1LL * A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return ret;
}

matrix fpow(matrix A, ll B) {
    int n = (int)A.size();
    matrix ret(n, vector<int>(n));
    for (int i = 0; i < n; i++) { ret[i][i] = 1; }
    while (B) {
        if (B & 1) { ret = mul(ret, A); }
        A = mul(A, A);
        B >>= 1;
    }
    return ret;
}

int get_fibo(int a) {
    if (a <= 1) return a;
    matrix FP = fpow(F, a - 1);
    return FP[0][0];
}

void solve() {
    cin >> n >> m;
    int fm = get_fibo(m + 2);
    int fn = get_fibo(n + 1);
    int ans = (fm - fn) % MOD;
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    F = {{1, 1}, {1, 0}};

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}