#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;

#define FOR(a, b) for (int i = (int) a; i < (int) b; i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
const int INF = INT_MAX;
const int MAXN = 1e6+10;


int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    priority_queue<ll> mx;
    priority_queue<ll, vector<ll>, greater<ll>> mi;
    for(int i=0; i<n; i++){
        ll a;
        cin >> a;
        if(mi.empty()||mx.empty()){
            if(mx.empty()){
                mx.push(a);
            }
            else{
                if(a>mx.top()){
                    mi.push(a);
                }
                else{
                    mi.push(mx.top());
                    mx.pop();
                    mx.push(a);
                }
            }
        }
        else{
            if(a<=mx.top()){
                mx.push(a);
            }
            else if(a>mi.top()){
                mi.push(a);
            }
            else{
                mx.push(a);
            }
            while(mi.size()>mx.size()){
                mx.push(mi.top());
                mi.pop();
            }
            while(mx.size()-1>mi.size()){
                mi.push(mx.top());
                mx.pop();
            }
        }
        if(i%2==0){
            cout << mx.top() << "\n";
        }
        else{
            ll temp = mi.top()+mx.top();
            cout << (temp/2) << (temp%2?".5":"") << "\n";
        }
    }


    return 0;
}