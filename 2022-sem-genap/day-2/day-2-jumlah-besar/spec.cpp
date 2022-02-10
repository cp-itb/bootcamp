#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

#define MAXN 200000
#define MAXA 1000000000

class ProblemSpec : public BaseProblemSpec {
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
		CONS(1 <= n && n <= MAXN);
		CONS(inRange(a));
	}

private:
	bool inRange(vector<int> a){
		for (int x : a){
			if (x < 1 || x > MAXA) return false;
		}
		return true;
	}
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
	void SampleTestCase1() {
		Input({
			"3",
			"1 2 3"
		});
		Output({
			"24"
		});
	}

	void SampleTestCase2() {
		Input({
			"2",
			"1 1",
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
			CASE(n = 10, randomArray(n, a));
		}
		for (int i=0; i<5; i++){
			CASE(n = MAXN, randomArray(n, a));
		}
	}

private:
	void randomArray(int n, vector<int> &a){
		for (int i=0; i<n; i++){
			a.push_back(rnd.nextInt(1, MAXA));
		}
	}
};