#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()

const int mxn=1e9, mxm=2e5;
int n,k,a,m;
set<int> s;

void solve() {
    cin >>n >>k >>a;
    s.insert(0);
    s.insert(n);
    int ct = n/a;
    int ans;
    cin >>m;
    for(int i=0;i<m;i++) {
        int b; cin >>b;
        auto it = s.lower_bound(b);
        int r = *it;
        int l = *(--it);
        ct -= (r-l)/a;
        ct += (b-l)/a + (r-b)/a;
        s.insert(b);
        if(ct<k) {
            ans = i;
            cout <<ans <<"\n";
            return;
        }
    }
    ans = m;
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}