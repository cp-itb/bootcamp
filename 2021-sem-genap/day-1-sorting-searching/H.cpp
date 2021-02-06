#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e4 + 5;
const double EPS = 1e-6;
double x[N], y[N];
int n;

double duration(double m) {
    double mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, (x[i] - m) * (x[i] - m) + y[i] * y[i]);
    }
    return mx;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while (cin >> n) {
        if (n == 0) break;
        for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
        double l = -2e5, r = 2e5;
        while (abs(r - l) > EPS) {
            double lm = (2 * l + r) / 3, rm = (l + 2 * r) / 3;
            if (duration(lm) < duration(rm)) {
                r = rm;
            } else {
                l = lm;
            }
        }
        cout << fixed << setprecision(6) << l << ' ' << sqrt(duration(l)) << '\n';
    }
    return 0;
}