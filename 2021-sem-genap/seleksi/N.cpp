#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;
    reverse(str.begin(), str.end());
    int n = str.length();
    vector<vector<int>> dp(n, vector<int>(2));
    dp[0][0] = str[0] - '0';
    dp[0][1] = 10 - (str[0] - '0');
    for (int i = 1; i < n; i++) {
        int x = str[i] - '0';
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + 1) + x;
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][1] - 1) + (10 - x);
    }
    cout << min(dp[n - 1][0], dp[n - 1][1] + 1) << '\n';

    return 0;
}