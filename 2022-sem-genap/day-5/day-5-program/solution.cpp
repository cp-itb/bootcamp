#include <bits/stdc++.h>

using namespace std;

#define FOR(a, b) for (int i = (int) a; i < (int) b; i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
struct dat {
    int sum, prefmax, prefmin;
} t[1<<19];

dat combine(dat l, dat r) {
    dat res;
    res.sum = l.sum + r.sum;
    res.prefmax = max(l.prefmax, l.sum + r.prefmax);
    res.prefmin = min(l.prefmin, l.sum + r.prefmin);
    return res;
}

dat make_data(int val) {
    dat res;
    res.sum = val;
    res.prefmin = min(val, 0);
    res.prefmax = max(val, 0);
    return res;
}

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = make_data(a[tl]);
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

dat query(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return make_data(0);
    if (l == tl && r == tr) 
        return t[v];
    int tm = (tl + tr) / 2;
    return combine(query(v*2, tl, tm, l, min(r, tm)), 
                   query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    int a[n];
    for(int i=0; i<n; i++){
        char c;
        cin >> c;
        if(c=='-'){
            a[i] = -1;
        }
        else{
            a[i] = 1;
        }
    }
    build(a, 1, 0, n-1);
    while(m--){
        int l, r;
        cin >> l >> r;
        l--; r--;
        auto p = query(1, 0, n-1, 0, max(l-1, 0));
        auto q = query(1, 0, n-1, min(r+1, n-1), n-1);
        if(l==0){
            if(r==n-1){
                cout << 1 << "\n";
                continue;
            }
            cout << q.prefmax - q.prefmin+1 << "\n";
            continue;
        }
        else if(r==n-1){
            cout << p.prefmax-p.prefmin+1 << "\n";
            continue;
        }
        cout << max(p.prefmax, p.sum+q.prefmax)-min(p.prefmin, p.sum+q.prefmin)+1 << "\n";
    }

    return 0;
}