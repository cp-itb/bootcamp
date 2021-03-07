#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

map<int, int> mp;
int n, rem;

void solve() {

    mp[4] = 0;
    mp[8] = 1;
    mp[15] = 2;
    mp[16] = 3;
    mp[23] = 4;
    mp[42] = 5;

    cin >> n;

    vector<int> dp(6);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (mp.find(a) == mp.end()) {
            continue;
        }
        int pos = mp[a];
        if (pos > 0) {
            if (dp[pos - 1]) { dp[pos]++, dp[pos - 1]--; }
        } else if (pos == 0) {
            dp[pos]++;
        }
    }

    rem = n - 6 * dp[5];
    cout << rem << '\n';

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}