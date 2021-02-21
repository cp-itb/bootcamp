#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    priority_queue<int, vector<int>, greater<int>> p;
    for (int i=1;i<=n;i++) {
        int x;
        cin >> x;
        p.push(x);
    }
    int ans = 0;
    while (!p.empty()) {
        if (p.size() == 1) {
            if (p.top() < k) {
                cout << -1 << endl;
                return 0;
            } else {
                cout << ans << endl;
                return 0;
            }
        } else {
            int t1 = p.top();
            p.pop();
            if (t1 >= k) {
                cout << ans << endl;
                return 0;
            }
            int t2 = p.top();
            p.pop();
            p.push(t1 + t2 * 2);
            ans++;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}