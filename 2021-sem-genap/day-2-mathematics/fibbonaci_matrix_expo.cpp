#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<long long>> matrix;

const int sz = 2;
const long long M = 1e9 + 7;

long long n;
int q;

matrix identitas = {
    {1, 0},
    {0, 1}
};

matrix m = {
    {0, 1}, 
    {1, 1}
};

matrix multiply(matrix& x, matrix& y) {
    matrix ret(sz, vector<long long>(sz, 0));
    // atau ret = {
    //     {0, 0},
    //     {0, 0}
    // }
    // pada kasus ini
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            for (int k = 0; k < sz; k++) {
                ret[i][j] = (ret[i][j] + x[i][k] * y[k][j]) % M;
            }
        }
    }
    return ret;
}

matrix matrixpow(matrix x, long long y) {
    matrix ret = identitas;
    while (y > 0) {
        if (y % 2 == 1) {
            ret = multiply(ret, x);
        }
        y /= 2;
        x = multiply(x, x);
    }
    return ret;
}

long long Fibbonaci(long long x) {
    // (Fx     ) = (0 1)^x  (F_0)
    // (F(x+1) ) = (1 1)    (F_1)
    matrix get = matrixpow(m, x);
    long long F_0 = 1, F_1 = 1;
    return (get[0][0] * F_0 + get[0][1] * F_1) % M;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    while (q--) {
        long long x;
        cin >> x;
        cout << Fibbonaci(x) << '\n';
    }

    return 0;
}
