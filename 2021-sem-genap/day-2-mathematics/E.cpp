#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long C[101][101], n, m;
    for(int i=0; i<101; i++){
        C[i][0] = 1;
        for(int j=1; j<i; j++){
            C[i][j] = C[i-1][j] + C[i-1][j-1];
        }
        C[i][i] = 1;
    }
    cin >> n >> m;
    while(n>0 || m>0){
        cout << n << " things taken " << m << " at a time is " << C[n][m] << " exactly." << endl;
        cin >> n >> m;
    }
}

