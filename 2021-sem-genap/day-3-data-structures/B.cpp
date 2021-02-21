#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    deque <long long> q;
    string s;
    bool reversed = false;
    long long n, x;
    cin >> n;
    while(n>0){
        cin >> s;
        if(s == "back"){
            if(q.empty()){
                cout << "No job for Ada?" << endl;
            }else if(reversed){
                cout << q.front() << endl;
                q.pop_front();
            }else{
                cout << q.back() << endl;
                q.pop_back();
            }
        }else if(s == "front"){
            if(q.empty()){
                cout << "No job for Ada?" << endl;
            }else if(reversed){
                cout << q.back() << endl;
                q.pop_back();
            }else{
                cout << q.front() << endl;
                q.pop_front();
            }
        }else if(s == "reverse"){
            reversed = !reversed;
        }else if(s == "push_back"){
            cin >> x;
            if(reversed){
                q.push_front(x);
            }else{
                q.push_back(x);
            }
        }else{
            cin >> x;
            if(reversed){
                q.push_back(x);
            }else{
                q.push_front(x);
            }
        }
        n--;
    }
}

