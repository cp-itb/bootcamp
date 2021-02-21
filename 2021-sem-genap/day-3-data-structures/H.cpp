#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;

int n, q;
int a[N];

struct maxQueue {
    deque<int> dq;

    void add(int x) {
        while (!dq.empty() && dq.back() < x)
            dq.pop_back();
        dq.emplace_back(x);
    }

    void remove(int x) {
        if (!dq.empty() && dq.front() == x)
            dq.pop_front();
    }

    int maxi() {
        if (dq.empty())
            return -INF;
        return dq.front();
    }
};

int solve(int d) {
    maxQueue mq;
    for (int i = 1; i <= d; i++) {
        mq.add(a[i]);
    }
    int mini = mq.maxi();
    for (int i = d + 1; i <= n; i++) {
        mq.remove(a[i - d]);
        mq.add(a[i]);
        mini = min(mini, mq.maxi());
    }
    return mini;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    while (q--) {
        int d;
        cin >> d;
        cout << solve(d) << '\n';
    }

    return 0;
}