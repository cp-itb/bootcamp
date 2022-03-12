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
    int ans;
    cin >>m;
    vector<int> b(m);
    for(int i=0;i<m;i++) {
        cin >>b[i];
    }
    for(int i=0;i<m;i++) {
        sort(b.begin(),b.begin()+i+1);
        int ct=0;
        for(int j=0;j<=i;j++) {
            if(j==0) {
                ct += b[j]/a;
            } else {
                ct += (b[j]-b[j-1])/a;
            }
        }
        ct += (n-b[i])/a;
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