#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int) (x).size()

template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;

int n;
int a[mxn];

void solve() {
    cin >>n;
    for(int i=0;i<n;i++) {
        cin >>a[i];
    }
    stack<int> st;
    int ans = 0;
    st.push(a[0]);
    for(int i=1;i<n;i++) {
        max_self(ans, st.top()^a[i]);
        while(sz(st) && a[i]>st.top()) {
            st.pop();
            if(sz(st)) {
                max_self(ans, st.top()^a[i]);
            }
        }
        st.push(a[i]);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}