#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 2;

int pre[N];
bool not_prime[N];

bool check(int x) {
    vector<int> nums;
    while (x > 0) {
        nums.emplace_back(x % 10);
        if (x % 10 == 0) return true;
        x /= 10;
    }
    int cur = 1, res = 0;
    for (int val : nums) {
        res = val * cur + res;
        if (not_prime[res]) return true;
        cur = cur * 10;
    }
    return false;
}

void init() {
    not_prime[1] = true;
    for (int i = 2; i < N; i++) {
        if (not_prime[i]) continue;
        for (int j = i + i; j < N; j += i) {
            not_prime[j] = true;
        }
    }
    for (int i = 1; i < N; i++) {
        pre[i] = pre[i - 1];
        if (not_prime[i]) continue;
        if (check(i)) continue;
        pre[i]++;
    }
}

void solve() {
    int n;
    cin >> n;
    cout << pre[n] << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}