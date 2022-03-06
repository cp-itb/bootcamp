#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

#define MAXN 200000
#define MAXM 200000

class ProblemSpec : public BaseProblemSpec {
protected:
	int n, m;
	vector<int> u, v;
	int ans;

	void InputFormat() {
		LINE(n, m);
		LINES(u, v) % SIZE(m);
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
		CONS(1 <= n && m <= MAXM);
		CONS(eachElementBetween(u, 1, n));
		CONS(eachElementBetween(v, 1, n));
	}

private:
	bool eachElementBetween(vector<int> a, int mn, int mx){
		for (int x : a){
			if (x < mn || x > mx) return false;
		}
		return true;
	}
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
	void SampleTestCase1() {
		Input({
			"5 4",
			"1 2",
			"4 2",
			"1 4",
			"5 3"
		});
		Output({
			"1"
		});
	}

	void SampleTestCase2() {
		Input({
			"2 1",
			"1 2"
		});
		Output({
			"0"
		});
	}

	void BeforeTestCase(){
		u.clear();
		v.clear();
	}

	void TestCases() {
		CASE(n = 2, m = 1, u = vector<int>(1, 1), v = vector<int>(1, 2));
		for (int i=0; i<10; i++){
			CASE(n = 50, m = 50, randomUnconnectedGraph(n, m, u, v));
		}
		for (int i=0; i<10; i++){
			CASE(n = 50, m = rnd.nextInt(50, 50*50), randomUnconnectedGraph(n, m, u, v));
		}
		for (int i=0; i<3; i++){
			CASE(n = MAXN, m = MAXM, randomUnconnectedGraph(n, m, u, v));
		}
	}

private:

	void randomUnconnectedGraph(int n, int m, vector<int>& u, vector<int>& v) {
	    for (int i=0; i<m; i++){
	    	int uu = rnd.nextInt(1, n);
	    	int vv = rnd.nextInt(1, n);
	    	u.push_back(uu);
	    	v.push_back(vv);
	    }
	}
};