#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

#define MAXN 200000
#define MAXM 200000

class ProblemSpec : public BaseProblemSpec {
protected:
	int n, m, s, t;
	vector<int> u, v;
	int ans;

	void InputFormat() {
		LINE(n, m, s, t);
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
		CONS(1 <= s && s <= n);
		CONS(1 <= t && t <= n);
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
			"7 6 1 5",
			"1 2",
			"2 3",
			"3 4",
			"4 5",
			"5 1",
			"7 6"
		});
		Output({
			"2"
		});
	}

	void SampleTestCase2() {
		Input({
			"6 5 1 4",
			"1 2",
			"2 3",
			"3 4",
			"4 1",
			"5 6"
		});
		Output({
			"-1"
		});
	}

	void SampleTestCase3() {
		Input({
			"6 5 1 5",
			"1 2",
			"2 3",
			"3 4",
			"4 1",
			"5 6"
		});
		Output({
			"-1"
		});
	}

	void BeforeTestCase(){
		u.clear();
		v.clear();
	}

	void TestCases() {
		CASE(n = 2, m = 1, s = 1, t = 2, u = vector<int>(1, 1), v = vector<int>(1, 2));
		for (int i=0; i<20; i++){
			CASE(n = 50, m = rnd.nextInt(50, 100), s = rnd.nextInt(1, n), t = rnd.nextInt(1, n), randomUnconnectedGraph(n, m, u, v));
		}
		for (int i=0; i<3; i++){
			CASE(n = MAXN, m = MAXM, s = rnd.nextInt(1, n), t = rnd.nextInt(1, n), randomUnconnectedGraph(n, m, u, v));
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