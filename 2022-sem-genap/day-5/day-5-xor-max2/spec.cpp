#include<tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

#define MAXN 1e5
#define MAXA 1e9

class ProblemSpec: public BaseProblemSpec {
protected:
    int n;
    vector<int> a;
    int ans;
    void InputFormat() {
        LINE(n);
        LINE(a % SIZE(n));
    }

    void OutputFormat() {
        LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(1); 
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 < n && n <= MAXN);
        CONS(inRange(a));
    }

private:
    bool inRange(vector<int> a) {
        for(int b : a) {
            if(b<1 || b>MAXA) return false;
        }
        return true;
    }
};

class TestSpec: public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "5",
            "5 2 1 4 3"                    
        });
        Output({
            "7"
        });
    }

    void SampleTestCase2() {
        Input({
            "5",
            "9 8 3 5 7"       
        });
        Output({
            "15"
        });
    }

    void BeforeTestCase() {
        a.clear();
    }

    void TestCases() {
        // isi 20 testcase.
        for(int i=0;i<10;i++) {
            CASE(n = 100, randomDistinctArray(n, a));
        }
        for(int i=0;i<10;i++) {
            CASE(n=MAXN, randomDistinctArray(n, a));
        }
    }
private:
    void randomDistinctArray(int n, vector<int> &ar) {
        set<int> udah;
        for(int i=0;i<n;i++) {
            while(true) {
                int ai = rnd.nextInt(1,MAXA);
                if(udah.find(ai)==udah.end()) {
                    ar.push_back(ai);
                    udah.insert(ai);
                    break;
                }
            }
        }
    } 
};