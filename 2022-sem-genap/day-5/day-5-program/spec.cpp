#include<tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

#define MAXN 2e5

class ProblemSpec: public BaseProblemSpec {
protected:
    int n, q;
    string s;
    vector<int> l, r;
    vector<int> ans;
    void InputFormat() {
        LINE(n, q);
        LINE(s);
        LINES(l, r) % SIZE(q);
    }

    void OutputFormat() {
        LINES(ans) % SIZE(q);
    }

    void GradingConfig() {
        TimeLimit(1); 
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= n && n <= MAXN);
        CONS(1 <= q && q <= MAXN);
        CONS(isValid(n, s));
        CONS(isValid2(q, n, l, r));
    }

private:
    bool isValid(int sz, string s) {
        if(s.size()!=sz){
            return false;
        }
        else{
            for(auto c: s){
                if(c!='+'&&c!='-'){
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid2(int sz, int n, vector<int> l, vector<int> r) {
        if(l.size()!=sz||r.size()!=sz) return false;
        for(int i=0; i<sz; i++){
            if(!(1<=l[i]&&l[i]<=r[i]&&r[i]<=n)){
                return false;
            }
        }     
        return true;
    }
};

class TestSpec: public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "8 4",
            "-+--+--+",
            "1 8",
            "2 8",
            "2 5",
            "1 1"          
        });
        Output({
            "1",
            "2",
            "4",
            "4"
        });
    }

    void SampleTestCase2() {
        Input({
            "4 10",
            "+-++",
            "1 1",
            "1 2",
            "2 2",
            "1 3",
            "2 3",
            "3 3",
            "1 4",
            "2 4",
            "3 4",
            "4 4"         
        });
        Output({
            "3",
            "3",
            "4",
            "2",
            "3",
            "2",
            "1",
            "2",
            "2",
            "2"
        });
    }

    void BeforeTestCase() {
        l.clear();
        r.clear();
    }

    void TestCases() {
        // isi 20 testcase.
        CASE(n=3, q=6, randomProgram(n, s), l={1, 1, 1, 2, 2, 3}, r={1, 2, 3, 2, 3, 3});
        for(int i=0;i<9;i++) {
            int q1;
            vector<int> l1, r1;
            completePermutation((i+4), q1, l1, r1);
            CASE(n=i+4, q = q1, randomProgram(i+4, s), l = l1, r = r1);
        }
        for(int i=0;i<5;i++) {
            vector<int> l1, r1;
            randomRange(1000, 1000, l1, r1);
            CASE(n=1000, q = 1000, randomProgram(n, s), l=l1, r=r1);
        }
        for(int i=0;i<5;i++) {
            vector<int> l1, r1;
            randomRange(MAXN, MAXN, l1, r1);
            CASE(n = MAXN, q = MAXN, randomProgram(n, s), l=l1, r=r1);
        }
    }
private:
    void completePermutation(int n, int& q, vector<int>&l, vector<int>&r){
        vector<pair<int, int>> v;
        for(int i=1; i<=n; i++){
            for(int j=i; j<=n; j++){
                v.push_back(make_pair(i, j));
            }
        }
        random_shuffle(v.begin(), v.end());
        q = v.size();
        for(int i=0; i<v.size(); i++){
            l.push_back(v[i].first);
            r.push_back(v[i].second);
        }
    }

    void randomProgram(int n, string& s){
        s = "";
        for(int i=0; i<n; i++){
            int t = rnd.nextInt(0, 1);
            if(t){
                s += '+';
            }
            else{
                s += '-';
            }
        }
    }


    void randomRange(int n, int q, vector<int> &l, vector<int>&r){
		set<pair<int, int>> udah;
		while (l.size() < n){
			int x = rnd.nextInt(1, n);
			int y = rnd.nextInt(x, n);
            if(!udah.count(make_pair(x, y))){
                l.push_back(x);
                r.push_back(y);
                udah.insert(make_pair(x, y));
            }
		}
	}
};