#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long mx, nbmx, n, type, x;
    stack <pair <long long, long long> >  s;
    cin >> n;
    while(n>0){
        cin >> type;
        if(type == 1){
            cin >> x;
            if(s.empty()){
                s.push({x,x});
            }else{
                s.push({x, max(s.top().second, x)});
            }
        }else if(type == 2){
            s.pop();
        }else{
            cout << s.top().second << endl;
        }
        n--;
    }
}

