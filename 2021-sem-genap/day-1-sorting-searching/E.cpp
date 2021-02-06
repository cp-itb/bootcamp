#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    LL a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    LL tot = 0;
    for (LL i=1;i<=n;i++) tot += a[i];
    // potong semua yang didepan, potong atasnya yang di belakang
    LL ans = tot, dep = 0;;
    for (LL i=1;i<=n;i++) {
        dep += a[i];
        tot -= a[i];
        // cout << tot - (n-i+1) * a[i] + dep << " ";
        ans = min(ans, tot - (n-i+1) * a[i] + dep);
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}