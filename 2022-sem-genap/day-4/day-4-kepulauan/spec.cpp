#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

#define MAXN 200000
#define MAXM 200000
#define MAXQ 200000
#define MAXA 1000000

class ProblemSpec : public BaseProblemSpec {
protected:
	int n, m, q;
	vector<int> a, u, v, qu, qv;
	vector<int> ans;

	void InputFormat() {
		LINE(n, m, q);
		LINE(a % SIZE(n));
		LINES(u, v) % SIZE(m);
		LINES(qu, qv) % SIZE(q);
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
		CONS(1 <= n && m <= MAXM);
		CONS(eachElementBetween(a, 1, MAXA));
		CONS(eachElementBetween(u, 1, n));
		CONS(eachElementBetween(v, 1, n));
		CONS(eachElementBetween(qu, 1, n));
		CONS(eachElementBetween(qv, 1, n));
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
			"5 4 3",
			"1 2 3 4 5",
			"1 2",
			"4 2",
			"1 4",
			"5 3",
			"1 2",
			"3 5",
			"1 5"
		});
		Output({
			"0",
			"0",
			"4"	
		});
	}

	void BeforeTestCase(){
		a.clear();
		u.clear();
		v.clear();
		qu.clear();
		qv.clear();
	}

	void TestCases() {
		for (int i=0; i<3; i++){
			CASE(n = 100, m = 100, q = MAXQ, randomVal(n, a, 1, MAXA), randomUnconnectedGraph(n, m, u, v), randomQueries(n, q, qu, qv));
		}
		CASE(n = MAXN, m = MAXM, q = MAXQ, randomVal(n, a, 1, MAXA), randomUnconnectedGraph(n, m, u, v), randomQueries(n, q, qu, qv));
	}

private:

	void randomVal(int n, vector<int> &a, int mn, int mx){
		for (int i=0; i<n; i++) a.push_back(rnd.nextInt(mn, mx));
	}

	void randomUnconnectedGraph(int n, int m, vector<int>& u, vector<int>& v) {
	    for (int i=0; i<m; i++){
	    	int uu = rnd.nextInt(1, n);
	    	int vv = rnd.nextInt(1, n);
	    	u.push_back(uu);
	    	v.push_back(vv);
	    }
	}

	void randomQueries(int n, int q, vector<int>& u, vector<int>& v) {
	    for (int i=0; i<q; i++){
	    	int uu = rnd.nextInt(1, n);
	    	int vv = rnd.nextInt(1, n);
	    	u.push_back(uu);
	    	v.push_back(vv);
	    }
	}
};