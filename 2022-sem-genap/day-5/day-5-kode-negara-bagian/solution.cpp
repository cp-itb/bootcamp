#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int mxn=2e5;

int n;

void solve() {
    cin >>n;
    map<string, int> mp;
    for(int i=0;i<n;i++) {
        string city, code;
        cin >>city >>code;
        mp[city.substr(0,2)+code]++;
    }
    ll ans=0;
    for(auto [s,ct]: mp) {
        string ps = s.substr(2,2)+s.substr(0,2);
        if(ps!=s && mp.count(ps)) {
            ans += 1ll*ct*mp[ps];
        }
    }
    ans /=2;
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}