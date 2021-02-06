#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 10000;
const int EPS = 5;
int n;
int h[N], c[N];

ll cnt(ll height) {
    ll ret = 0;
    for (int i = 0; i < n; i++) {
        ll dif = abs(h[i] - height);
        ret += 1ll * c[i] * dif;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }
        ll ans = LLONG_MAX;
        ll l = 0, r = 1ll * (*max_element(h, h + n));
        while (r - l > EPS) {
            ll lm = (2 * l + r) / 3;
            ll rm = (l + 2 * r) / 3;
            if (cnt(lm) < cnt(rm)) {
                r = rm;
            } else {
                l = lm;
            }
        }
        while (l <= r) {
            ans = min(ans, cnt(l++));
        }
        cout << ans << '\n';
    }
    return 0;
}