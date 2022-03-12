#include<tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

#define MAXN 2e5
#define MAXA 1e6

class ProblemSpec: public BaseProblemSpec {
protected:
    int n,m, inc, rmq;
    vector<int> a;
    vector<vector<int>> lrv;
    vector<int> ans;
    void InputFormat() {
        LINE(n);
        LINE(a % SIZE(n));
        LINE(m);
        LINES(lrv) % SIZE(m);
    }

    void OutputFormat() {
        LINE(ans) % SIZE(rmq);
    }

    void GradingConfig() {
        TimeLimit(1.5); 
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= n && n <= MAXN);
        CONS(inRange(a));
        CONS(1 <= m && m <= MAXN);
        CONS(inRange2(lrv));
    }

private:
    bool inRange(vector<int> a) {
        for(int x: a) {
            if(x<0 || x>n-1) return false;
        }
        return true;
    }

    bool inRange2(vector<vector<int>> lrv) {
        for(vector<int> lrvi : lrv) {
            if(lrvi.size()==3) {
                if(lrvi[0]<0 || lrvi[0]>n-1) return false;
                if(lrvi[1]<0 || lrvi[1]>n-1) return false;
                if(lrvi[2]<-1*MAXA || lrvi[2]>MAXA) return false;
            } else if(lrvi.size()==2) {
                if(lrvi[0]<0 || lrvi[0]>n-1) return false;
                if(lrvi[1]<0 || lrvi[1]>n-1) return false;
            }
        }
        return true;
    }
};

class TestSpec: public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "4",
            "1 2 3 4",
            "4",
            "3 0",
            "3 0 -1",
            "0 1",
            "2 1"            
        });
        Output({
            "1",
            "0",
            "0"
        });
    }

    void SampleTestCase2() {
        Input({
            "2",
            "-1 -1",
            "9",
            "0 0",
            "0 0 4",
            "0 0",
            "1 1",
            "0 0 -2",
            "0 0 0",
            "0 0 7",
            "0 0 -4",
            "0 0"          
        });
        Output( {
            "-1",
            "3",
            "-1",
            "4"
        });
    }

    void BeforeTestCase() {
        a.clear();
        lrv.clear();
    }

    void TestCases() {
        // isi 20 testcase.
        CASE(n=1, a={-1}, inc=rnd.nextInt(1,5), rmq=rnd.nextInt(1,5), m=inc+rmq, randomOp(inc, rmq, lrv));
        for(int i=0;i<9;i++) {
            CASE(n=100, randomArray(n, a), inc=rnd.nextInt(1,100), rmq=rnd.nextInt(1,100), m=inc+rmq, randomOp(inc, rmq, lrv));
        }
        for(int i=0;i<9;i++) {
            CASE(n=MAXN/2, randomArray(n,a), inc=rnd.nextInt(1,MAXN/2), rmq=MAXN-inc, m=inc+rmq, randomOp(inc, rmq, lrv));
        }
        CASE(n=MAXN, randomArray(n,a), inc=rnd.nextInt(1,MAXN/2), rmq=MAXN-inc, m=inc+rmq, randomOp(inc, rmq, lrv));
    }
private:
    void randomOp(int inc, int rmq, vector<vector<int>> &lrv) {
        while(inc>0 && rmq>0) {
            if(rnd.nextInt(0,1)) {
                inc--;
                lrv.push_back({rnd.nextInt(0,n-1), rnd.nextInt(0,n-1), rnd.nextInt(-1*MAXA,MAXA)});
            } else {
                rmq--;
                lrv.push_back({rnd.nextInt(0,n-1), rnd.nextInt(0,n-1)});
            }
        }
        while(inc>0) {
            inc--;
            lrv.push_back({rnd.nextInt(0,n-1), rnd.nextInt(0,n-1), rnd.nextInt(-1*MAXA,MAXA)});
        }
        while(rmq>0) {
            rmq--;
            lrv.push_back({rnd.nextInt(0,n-1), rnd.nextInt(0,n-1)});
        }
    }
    void randomArray(int n, vector<int> &a) {
        for(int i=0;i<n;i++) {
            a.push_back(rnd.nextInt(-1*MAXA,MAXA));
        }
    }
};