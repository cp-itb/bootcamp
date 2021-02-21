#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n;
    string input, ans;
    cin >> n;
    while(n>0){
        stack <char> s;
        cin >> input;
        ans = "YES";
        for(int i=0; i<input.length(); i++){
            if(input[i] == ')'){
                if(!s.empty() && s.top() == '('){
                    s.pop();
                }else{
                    ans = "NO";
                }
            }else if(input[i] == '}'){
                if(!s.empty() && s.top() == '{'){
                    s.pop();
                }else{
                    ans = "NO";
                }
            }else if(input[i] == ']'){
                if(!s.empty() && s.top() == '['){
                    s.pop();
                }else{
                    ans = "NO";
                }
            }else{
                s.push(input[i]);
            }
        }
        if(s.empty()){
            cout << ans << endl;
        }else{
            cout << "NO" << endl;
        }
        n--;
    }
}

