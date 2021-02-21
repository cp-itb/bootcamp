#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
int a[N];
int lft[N], rgt[N];
int dp[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    {
        stack<int> st;
        for (int i = 1; i <= n; i++) {
            while (!st.empty() && a[st.top()] >= a[i])
                st.pop();
            lft[i] = (st.empty() ? i : i - st.top());
            st.push(i);
        }
    }
    {
        stack<int> st;
        for (int i = n; i >= 1; i--) {
            while (!st.empty() && a[st.top()] >= a[i])
                st.pop();
            rgt[i] = (st.empty() ? n - i + 1 : st.top() - i);
            st.push(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        int cur_sz = lft[i] + rgt[i] - 1;
        dp[cur_sz] = max(dp[cur_sz], a[i]);
    }
    for (int i = n - 1; i >= 1; i--) {
        dp[i] = max(dp[i], dp[i + 1]);
    }
    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " \n"[i == n];
    }

    return 0;
}