#include<bits/stdc++.h>
using namespace std;

const long long NMAX = 1e6 + 10;
long long phi[NMAX], add[NMAX], ans[NMAX];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    phi[0] = 0;
    phi[1] = 1;
    for(int i=2; i<NMAX; i++){
        phi[i] = i;
    }
    for(int i=2; i<NMAX; i++){
        if(phi[i] == i){ //i prima, bisa sieve
            for(int j=i; j<NMAX; j+=i){
                phi[j] -= phi[j]/i;
            }
        }
    }

    for(int i=1; i<NMAX; i++){
        add[i] = 0;
    }
    for(int i=1; i<NMAX; i++){
        for(int j=i; j<NMAX; j+=i){
            add[j] += i*phi[j/i];
        }
    }
    for(int i=1; i<NMAX; i++){
        ans[i] += ans[i-1] - i + add[i];
    }

    long long n;
    cin >> n;
    while(n!=0){
        cout << ans[n] << endl;
        cin >> n;
    }
}

