#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

#define MAXN 1e6
#define MAXA 1e9

class ProblemSpec: public BaseProblemSpec {
protected:
    int n;
    vector<int> a;
    vector<string> ans;
    void InputFormat() {
        LINE(n);
        LINE(a % SIZE(n));
    }

    void OutputFormat() {
        LINES(ans) % SIZE(n);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= n && n <= MAXN);
        CONS(inRange(a));
    }

private:
    bool inRange(vector<int> a) {
        for(int x: a) {
            if(x<0 || x>MAXA) return false;
        }
        return true;
    }
};

class TestSpec: public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "5",
            "4 3 2 10 1"
        });
        Output({
            "4",
            "3.5",
            "3",
            "3.5",
            "3"
        });
    }

    void SampleTestCase2() {
        Input({
            "3",
            "3 2 1"        
        });
        Output( {
            "3",
            "2.5",
            "2"
        });
    }

    void BeforeTestCase() {
        a.clear();
    }

    void TestCases() {
		for (int i=0; i<5; i++){
			CASE(n = 1000, randomPermutation(n, a));
			CASE(n = 1000, randomArray(n, a));
		}
		for (int i=0; i<5; i++){
			CASE(n = MAXN, randomPermutation(n, a));
			CASE(n = MAXN, randomArray(n, a));
		}
    }
private:
    void randomPermutation(int n, vector<int> &a){
		for (int i=1; i<=n; i++) a.push_back(i);
		rnd.shuffle(a.begin(), a.end());
	}

	void randomArray(int n, vector<int> &a){
		set<int> udah;
		while (a.size() < n){
			int x = rnd.nextInt(1, MAXA);
			if (!udah.count(x)){
				udah.insert(x);
				a.push_back(x);
			}
		}
	}
};