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

const int N = 2e5 + 5; // don't forget to change constant
int par[N], sz[N], ans[26];

void make_set(int u) {
    par[u] = u;
    sz[u] = 1;
}

// find parent
int find_set(int x) {
    if (par[x] == x) return x;
    return par[x] = find_set(par[x]);
}

// merge two sets, return true if they are seperate, false otherwise
bool merge_set(int u, int v) {
    int pu = find_set(u), pv = find_set(v);
    if (pu == pv) return false;
    if (sz[pu] < sz[pv]) swap(pu, pv);
    sz[pu] += sz[pv];
    par[pv] = pu;
    return true;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++) {
        memset(ans, 0, sizeof(ans));
        string p;
        cin >> p;
        string s = p;
        for (int i=0;i<=s.size();i++) make_set(i);
        int q;
        cin >> q;
        vector<pii> query;
        while (q--) {
            int type, si;
            cin >> type >> si;
            query.pb({type, si});
            if (type == 2) s[si] = '#';
        }
        s += '#';
        for (int i=0;i<s.size();i++) {
            if (s[i] == s[i+1] && s[i] != '#') {
                merge_set(i, i+1);
                ans[s[i] - 'A'] = max(ans[s[i] - 'A'], sz[find_set(i)]);
            }
        }
        for (int i=0;i<s.size();i++) {
            if (ans[s[i]-'A'] == 0) ans[s[i]-'A'] = 1;
        }
        // cout << s << endl;
        // for (int i=0;i<26;i++) cout << ans[i] << " ";
        // cout << endl;
        reverse(query.begin(), query.end());
        vector<int> answer;
        for (pii que : query) {
            if (que.fi == 1) {
                answer.pb(sz[find_set(que.se)]);
            } else {
                s[que.se] = p[que.se];
                if (que.se >= 1 && s[que.se - 1] != '#' && s[que.se - 1] == s[que.se]) merge_set(que.se - 1, que.se);
                if (que.se <= s.size() - 1 && s[que.se + 1] != '#' && s[que.se + 1] == s[que.se]) merge_set(que.se + 1, que.se);
                ans[s[que.se] - 'A'] = max(ans[s[que.se] - 'A'], sz[find_set(que.se)]);
                // cout << s << endl;
                // for (int i=0;i<s.size();i++) cout << par[i] << " ";
                // cout << endl;
                // for (int i=0;i<s.size();i++) cout << sz[find_set(i)] << " ";
                // cout << endl;
            }
        }
        cout << "Case " << t << ": " << '\n';
        reverse(answer.begin(), answer.end());
        for (auto an : answer) cout << an << '\n';
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}