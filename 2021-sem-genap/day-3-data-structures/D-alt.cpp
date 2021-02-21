#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    set<int> st;
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int v;
            cin >> v;
            st.emplace(v);
        } else if (tp == 2) {
            int v;
            cin >> v;
            st.erase(v);
        } else if (tp == 3) {
            cout << *st.begin() << '\n';
        }
    }

    return 0;
}