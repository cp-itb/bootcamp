#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    int ans = 0;
    while (n > 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else if (n % 3 == 0) {
            n /= 3;
            n *= 2;
        } else if (n % 5 == 0) {
            n /= 5;
            n *= 4;
        } else {
            break;
        }
        ++ans;
    }
    if (n != 1) ans = -1;
    cout << ans << '\n';
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