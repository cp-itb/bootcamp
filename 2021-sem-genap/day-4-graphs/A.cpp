    #include <bits/stdc++.h>

    using namespace std;

    const int N = 1e3 + 5;

    int n;
    vector<int> adj[N];
    bool vis[N];

    void init() {
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            vis[i] = 0;
        }
    }

    vector<int> BFS(int s) {
        vector<int> ret;
        for (int i = 1; i <= n; i++) {
            vis[i] = 0;
        }
        queue<int> q;
        ret.emplace_back(s);
        q.emplace(s);
        vis[s] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (vis[v]) continue;
                vis[v] = 1;
                q.emplace(v);
                ret.emplace_back(v);
            }
        }
        return ret;
    }

    vector<int> DFS(int s) {
        vector<int> ret;
        for (int i = 1; i <= n; i++) {
            vis[i] = 0;
        }
        function<void(int)> dfs = [&](int u) {
            vis[u] = 1;
            ret.emplace_back(u);
            for (int v : adj[u]) {
                if (vis[v]) continue;
                dfs(v);
            }
        };
        dfs(s);
        return ret;
    }

    void solve() {
        cin >> n;
        init();
        for (int rep = 1; rep <= n; rep++) {
            int u, m;
            cin >> u >> m;
            for (int i = 0; i < m; i++) {
                int v;
                cin >> v;
                adj[u].emplace_back(v);
            }
        }
        int s, tp;
        while (cin >> s >> tp) {
            if (s == 0 && tp == 0) break;
            vector<int> ans = (tp == 0 ? DFS(s) : BFS(s));
            int len = ans.size();
            for (int i = 0; i < len; i++) {
                cout << ans[i] << " \n"[i == len - 1];
            }
        }
    }

    int main() { 
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int tc;
        cin >> tc;
        for (int T = 1; T <= tc; T++) {
            cout << "graph " << T << '\n';
            solve();
        }

        return 0;
    }