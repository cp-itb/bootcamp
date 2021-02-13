#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using matrix = vector<vector<int>>;

const int MOD = 1e9;


// a1, a2, a3, ..................

// a_1 = b_1
// a_2 = b_2
// ...
// a_k = b_k

// a_n = c_1 * a_(n-1) + .... + c_k * a(n-k)

// |c1 c2 ... ck|    |a_(i-1)|     |a_i      |
// |1  0  ... 0 |    |a_(i-2)|     |a_(i-1)  |
// |0  1  ... 0 | .  |.      |  =  |.        |
// |.  .  .     |    |.      |     |.        |
// |.  .    .   |    |.      |     |.        |
// |0  0  ... 0 |    |a_(i-k)|     |a_i-k+1  |

// |a_k     |  --> 
// |a_(k-1) |
// |.       |    
// |.       | 
// |.       |
// |a_1     |

// |c1 c2 ... ck| ^ t      |a_k     |      |a_(k+t) = a_n |  
// |1  0  ... 0 |          |a_(k-1) |      |a_(k+t-1)     |  
// |0  1  ... 0 |      .   |.       |  =   |.             |  
// |.  .  .     |          |.       |      |.             |  
// |.  .    .   |          |.       |      |.             |  
// |0  0  ... 0 |          |a_1     |      |a_(t+1)       |  


// a_n mod 1e9 ? 


// O(size(A)^3)
// prekondisi: A, B persegi dan ukurannya sama
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

// O(log(B) * size(A)^3)
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

// matrix fpow(matrix A, ll B) {
//     matrix T = fpow(A, B/2);
//     if (B == 1) { return A; }
//     if (B & 1) { return mul(mul(T, T), A); }
//     return mul(T, T);
// }

int k, n;

void solve() {
    cin >> k;
    vector<int> b(k + 1), c(k + 1);
    for (int i = 1; i <= k; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
    }
    matrix M(k, vector<int>(k));
    for (int i = 0; i < k; i++) { M[0][i] = c[i + 1]; }
    for (int i = 1; i < k; i++) { M[i][i - 1] = 1; }
    cin >> n;
    if (n <= k) {
        cout << b[n];
    } else {
        M = fpow(M, n - k);
        ll ans = 0;
        for (int i = 0; i < k; i++) {
            ans = (ans + 1LL * M[0][i] * b[k - i]) % MOD;
        }
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