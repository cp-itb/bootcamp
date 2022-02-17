#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

const int MAXN = 1000000;

class ProblemSpec : public BaseProblemSpec {
protected:
	int n, x;
	int ans;

	void InputFormat() {
		LINE(n, x);
	}

	void OutputFormat() {
		LINE(ans);
	}

	void GradingConfig() {
		TimeLimit(1);
		MemoryLimit(256);
	}

	void Constraints() {
		CONS(1 <= x && x <= n && n <= MAXN);
	}

};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
	void SampleTestCase1() {
		Input({
			"3 2"
		});
		Output({
			"4"
		});
	}

	void SampleTestCase2() {
		Input({
			"123456 1337"
		});
		Output({
			"968741242"
		});
	}

	void TestCases() {
		CASE(n = x = 1);
		for (int i=0; i<40; i++){
			CASE(n = rnd.nextInt(1, MAXN), x = rnd.nextInt(1, n));
		}
		CASE(n = MAXN, x = 1);
		CASE(n = MAXN, x = MAXN);
	}
};