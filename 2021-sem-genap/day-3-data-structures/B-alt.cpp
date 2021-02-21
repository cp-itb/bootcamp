#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    const string EMPTY = "No job for Ada?";

    int q;
    cin >> q;
    bool rev = false;
    deque<int> dq;
    while (q--) {
        string str;
        cin >> str;
        if (str[0] == 'b') { // back
            if (dq.empty()) {
                cout << EMPTY << '\n';
                continue;
            }
            if (!rev) {
                cout << dq.back() << '\n';
                dq.pop_back();
            } else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        } else if (str[0] == 'f') { // front
            if (dq.empty()) {
                cout << EMPTY << '\n';
                continue;
            }
            if (!rev) {
                cout << dq.front() << '\n';
                dq.pop_front();
            } else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        } else if (str[0] == 'r') { // reverse
            rev = !(rev);
        } else if (str[0] == 'p') { // push_back
            int n;
            cin >> n;
            if (!rev)
                dq.push_back(n);
            else
                dq.push_front(n);
        } else if (str[0] == 't') { // toFront
            int n;
            cin >> n;
            if (!rev)
                dq.push_front(n);
            else
                dq.push_back(n);
        }
    }

    return 0;
}