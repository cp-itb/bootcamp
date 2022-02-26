#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int EXIT_AC = 42;
const int EXIT_WA = 43;

int wa() {
    exit(EXIT_WA);
}

int ac() {
    exit(EXIT_AC);
}

int main(int argc, char* argv[]) {
    ifstream tc_in(argv[1]);
    ifstream tc_out(argv[2]);
    string feedback_path = argv[3];
    feedback_path += "/judgeerror.txt";
    ofstream feedback(feedback_path);

    int n, m;
    tc_in >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            tc_in >> a[i][j];
        }
    }

    long long ans;
    if (!(cin >> ans)) {
        feedback << "no input" << endl;
        return wa();
    }
    long long jans;
    tc_out >> jans;
    if (ans != jans) {
        feedback << "wrong max value" << endl;
        return wa();
    }

    string sans;
    if (!(cin >> sans)){
        feedback << "insufficient input" << endl;
        return wa();
    }
    if (sans.length() != n+m-2){
        feedback << "wrong route length" << endl;
        return wa();
    }

    int r = 0, c = 0;
    long long sum = a[r][c];
    for (char ch : sans){
        if (ch == 'K') c++;
        else if (ch == 'B') r++;
        else{
            feedback << "invalid char" << endl;
            return wa();
        }
        sum += a[r][c];
    }

    if (sum != ans){
        feedback << "route sum does not match ans" << endl;
        feedback << "route sum = " << sum << endl;
        return wa(); 
    }

    return ac();
}