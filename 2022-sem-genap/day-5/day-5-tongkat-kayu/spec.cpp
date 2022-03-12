#include<tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

#define MAXN 1e9
#define MAXM 2e5

class ProblemSpec: public BaseProblemSpec {
protected:
    int n,k,a,m;
    vector<int> b;
    int ans;
    void InputFormat() {
        LINE(n,k,a);
        LINE(m);
        LINE(b % SIZE(m));
    }

    void OutputFormat() {
        LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1<=n && n<=MAXN && 1<=k && k<=MAXN && 1<=a && a<=MAXN);
        CONS(1ll*k*a <= n);
        CONS(1<=m && m<=MAXM && m <= n-1);
        CONS(inRange(b));
        // syarat unik di TestSpec
    }

private:
    bool inRange(vector<int> b) {
        for(int x: b) {
            if(x<1 || x>n-1) return false;
        }
        return true;
    }
};

class TestSpec: public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input( {
            "10 3 3",
            "5",
            "3 7 5 1 9"
        });
        Output({
            "2"
        });
    }

    void SampleTestCase2() {
        Input( {
            "5 5 1",
            "4",
            "4 3 1 2"
        });
        Output({
            "4"
        });
    }

    void SampleTestCase3() {
        Input({
            "5 1 4",
            "1",
            "2"
        });
        Output({
            "0"
        });
    }
    void BeforeTestCase() {
        b.clear();
    }

    void TestCases() {
        // isi 20 testcase.
        for(int i=0;i<10;i++) {
            CASE(n=10, k=rnd.nextInt(1,n), a=rnd.nextInt(1,n/k), m=rnd.nextInt(1,n-1), randomUniqueArray(m, b));
        }
        for(int i=0;i<5;i++) {
            CASE(n = MAXM+1, k=rnd.nextInt(1,n), a=rnd.nextInt(1,n/k), m=MAXM, randomUniqueArray(m,b));
        }
        for(int i=0;i<5;i++) {
            CASE(n = MAXN, k=rnd.nextInt(1,1000), a=rnd.nextInt((n-MAXM)/k,n/k), m=MAXM, randomUniqueArray(m, b));
        }
    }
private:
    void randomUniqueArray(int m, vector<int> &b) {
        set<int> s;
        for(int i=0;i<m;i++) {
            while(true) {
                int x = rnd.nextInt(1, m);
                if(s.find(x)==s.end()) {
                    b.push_back(x);
                    s.insert(x);
                    break;
                }
            }
        }
    }
};
