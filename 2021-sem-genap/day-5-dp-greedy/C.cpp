#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = n; i >= 0; i--) {
        int rem = n - 7 * i;
        if (rem < 0) continue;
        if (rem % 4 != 0) continue;
        cout << string(rem / 4, '4') << string(i, '7') << '\n';
        return 0;
    }
    cout << -1 << '\n';

    return 0;
}