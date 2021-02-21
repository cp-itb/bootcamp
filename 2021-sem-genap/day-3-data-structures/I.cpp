#include<bits/stdc++.h>

using namespace std;

int w, h, n;
set<int> sw, sh;
multiset<int> msw, msh;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> w >> h >> n;
    sw.insert(0); sw.insert(w);
    sh.insert(0); sh.insert(h);
    msw.insert(w);
    msh.insert(h);
    for (int i = 1; i <= n; i++) {
        char x;
        int y;
        cin >> x >> y;
        if (x == 'H') {
            auto it = sh.lower_bound(y);
            it--;
            int k1 = *it;
            it = sh.upper_bound(y);
            int k2 = *it;
            int dif = k2 - k1;
            sh.insert(y);
            auto it2 = msh.find(dif);
            msh.erase(it2);
            msh.insert(y - k1); msh.insert(k2 - y);
        } else if (x == 'V') {
            auto it = sw.lower_bound(y);
            it--;
            int k1 = *it;
            it = sw.upper_bound(y);
            int k2 = *it;
            int dif = k2 - k1;
            sw.insert(y);
            auto it2 = msw.find(dif);
            msw.erase(it2);
            msw.insert(y - k1); msw.insert(k2 - y);
        }
        auto it1 = msh.end();
        auto it2 = msw.end();
        it1--, it2--;
        long long k1 = *it1, k2 = *it2;
        cout << k1 * k2 << '\n';
    }

    return 0;
}