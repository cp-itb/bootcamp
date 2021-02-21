#include <bits/stdc++.h>

using namespace std;

map<char, char> pasangan = {{'(', ')'}, {'[', ']'}, {'{', '}'}};

void solve() {
    string str;
    cin >> str;
    stack<char> st;
    for (char cc : str) {
        if (st.empty()) {
            st.push(cc);
        } else {
            char x = st.top();
            if (pasangan[x] == cc) {
                st.pop();
            } else {
                st.emplace(cc);
            }
        }
    }
    cout << (st.empty() ? "YES" : "NO") << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}