#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

const int maxn = 100000;
const int maxm = 1000000;

class ProblemSpec : public BaseProblemSpec {
protected:
	int n, m;
	vector<int> a;
	int ans;

	void InputFormat() {
		LINE(n, m);
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
		CONS(1 <= n && n <= maxn);
		CONS(1 <= m && m <= maxm);
		CONS(eachElementBetween(a, 1, m));
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
			"5 10",
			"7 2 3 2 4"
		});
		Output({
			"3"
		});
	}

	void SampleTestCase2() {
		Input({
			"5 15",
			"7 2 3 2 4"
		});
		Output({
			"4"
		});
	}

	void BeforeTestCase(){
		a.clear();
	}

	void TestCases() {
		for (int i=0; i<10; i++){
			CASE(n = rnd.nextInt(100, 1000), m = rnd.nextInt(1, 1000), randomArray(n, a, m));
		}
		for (int i=0; i<5; i++){
			CASE(n = rnd.nextInt(maxn/10, maxn), m = rnd.nextInt(maxm/10, maxm), randomArray(n, a, m));
		}
		CASE(n = maxn, m = maxm, a = vector<int>(n, 999769));
		CASE(n = maxn, m = maxm, a = vector<int>(n, 1));
	}

private:
	void randomArray(int n, vector<int> &a, int mx){
		for (int i=0; i<n; i++){
			a.push_back(rnd.nextInt(1, mx));
		}
	}
};