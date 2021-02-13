#include <bits/stdc++.h>

using namespace std;

int phi(int n) {
    int ret = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ret -= ret / i;
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) ret -= ret / n;
    return ret;
}

void solve() {
    int x;
    cin >> x;
    cout << phi(x) << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}