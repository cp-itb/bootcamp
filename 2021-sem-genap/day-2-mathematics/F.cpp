#include<bits/stdc++.h>
using namespace std;

long long mod = 1e9+7;

long long modInverse(long long a, long long m)
{
    int m0 = m;
    int y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        // q is quotient
        int q = a / m;
        int t = m;

        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
        x += m0;

    return x;
}

long long fac[1000005];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    fac[0] = 1;
    for(int i=1; i<1000005; i++){
        fac[i] = (fac[i-1]*i)%mod;
    }
    long long t, n, tot, k[1005];
    long long ans;
    cin >> t;
    while(t>0){
        cin >> n;
        tot = 0;
        for(int i=0; i<n; i++){
            cin >> k[i];
            tot += k[i];
        }
        ans = 1;
        for(int i=n-1; i>=0; i--){
            ans = ans * fac[tot-1] % mod;
            ans = ans * modInverse(fac[k[i]-1], mod) % mod;
            ans = ans * modInverse(fac[tot-k[i]], mod) % mod;
            tot -= k[i];
        }
        cout << ans << endl;
        t--;
    }
}

