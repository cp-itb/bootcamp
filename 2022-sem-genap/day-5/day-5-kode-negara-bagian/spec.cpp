#include<tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

#define MAXN 2e5

class ProblemSpec: public BaseProblemSpec {
protected:
    int n;
    vector<string> city, code;
    int ans;
    void InputFormat() {
        LINE(n);
        LINES(city, code) % SIZE(n);
    }

    void OutputFormat() {
        LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(1); 
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= n && n <= MAXN);
        CONS(inRange(city));
        CONS(inRange2(code));
    }

private:
    bool inRange(vector<string> s) {
        for(string si : s) {
            if(si.length()<2 || si.length()>10) return false;
            for(char c : si) {
                if(c<'A' || c >'Z') return false;
            }
        }
        return true;
    }

    bool inRange2(vector<string> s) {
        for(string si : s) {
            if(si.length()!=2) return false;
            for(char c : si) {
                if(c<'A' || c >'Z') return false;
            }
        }        
        return true;
    }
};

class TestSpec: public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "6",
            "MIAMI FL",
            "DALLAS TX",
            "FLINT MI",
            "CLEMSON SC",
            "BOSTON MA",
            "ORLANDO FL"            
        });
        Output({
            "1"
        });
    }

    void SampleTestCase2() {
        Input({
            "2",
            "BOSTON BO",
            "BOGOR BO"           
        });
        Output({
            "0"
        });
    }

    void BeforeTestCase() {
        city.clear();
        code.clear();
    }

    void TestCases() {
        // isi 20 testcase.
        CASE(n=3, city={"MIMIMI","MIAMI","FLINT"}, code={"FL","FL","MI"});
        for(int i=0;i<9;i++) {
            CASE(n=100, randomCity(n,city), randomCode(n,code));
        }
        for(int i=0;i<5;i++) {
            CASE(n=1000, randomCity(n,city), randomCode(n,code));
        }
        for(int i=0;i<5;i++) {
            CASE(n=MAXN, randomCity(n,city), randomCode(n,code));
        }
    }
private:
    void randomCity(int n, vector<string> &vs) {
        for(int i=0;i<n;i++) {
            int l = rnd.nextInt(2,10);
            string s = "";
            for(int j=0;j<l;j++) {
                s += (char)('A'+rnd.nextInt(0,25));
            }
            vs.push_back(s);
        }
    }

    void randomCode(int n, vector<string> &vs) {
        for(int i=0;i<n;i++) {
            int l = 2;
            string s = "";
            for(int j=0;j<l;j++) {
                s += (char)('A'+rnd.nextInt(0,25));
            }
            vs.push_back(s);
        }
    }    
};