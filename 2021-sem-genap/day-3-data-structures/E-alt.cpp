#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; long long k;
    cin >> n >> k;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        pq.emplace(x);
    }
    int op = 0;
    while (1) {
        if (!pq.empty() && pq.top() >= k) {
            cout << op << '\n';
            return 0;
        }
        long long new_val = 0;
        for (int it = 1; it <= 2; it++) {
            if (pq.empty()) {
                cout << -1 << '\n';
                return 0;
            }
            new_val += pq.top() * it;
            pq.pop();
        }
        pq.emplace(new_val);
        ++op;
    }

    return 0;
}