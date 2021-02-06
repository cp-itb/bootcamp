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
    string s;
    cin >> s;
    int l[30], r[30];
    memset(l, -1, sizeof(l));
    memset(r, -1, sizeof(r));
    for (int i=0;i<s.size();i++) {
        if (r[s[i]-'a'] == -1) {
            r[s[i]-'a'] = i;
        } else {
            l[s[i]-'a'] = max(l[s[i]-'a'], i - r[s[i]-'a']);
            r[s[i]-'a'] = i;
        }
    }
    int ans = INT_MAX;
    for (int i=0;i<26;i++) {
        if (l[i] != -1) {
            ans = min(ans, l[i]);
        }
    }
    if (ans == INT_MAX) ans = s.size() / 2 + 1;
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}