#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    const int INF = 2e9;

    int n;
    cin >> n;
    stack<int> st;
    while (n--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int x;
            cin >> x;
            int before = (st.empty() ? -INF : st.top());
            st.push(max(x, before));
        } else if (tp == 2) {
            st.pop();
        } else if (tp == 3) {
            cout << st.top() << '\n';
        }
    }

    return 0;
}