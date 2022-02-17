#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

const long long maxn = 1e15;
const long long maxa = 1e6;

class ProblemSpec : public BaseProblemSpec {
protected:
	long long l, r, a, b, c;
	long long ans;

	void InputFormat() {
		LINE(l, r, a, b, c);
	}

	void OutputFormat() {
		LINE(ans);
	}

	void GradingConfig() {
		TimeLimit(1);
		MemoryLimit(256);
	}

	void Constraints() {
		CONS(1 <= l && l <= r && r <= maxn);
		CONS(1 <= a && a <= maxa);
		CONS(1 <= b && b <= maxa);
		CONS(1 <= c && c <= maxa);
	}

};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
	void SampleTestCase1() {
		Input({
			"2 10 2 3 4"
		});
		Output({
			"7"
		});
	}

	void SampleTestCase2() {
		Input({
			"5 5 1 1 1"
		});
		Output({
			"1"
		});
	}

	void TestCases() {
		CASE(l = r = a = b = c = 1);
		for (int i=0; i<20; i++){
			long long ra = rnd.nextLongLong(1, 1000);
			long long rb = rnd.nextLongLong(1, 1000);
			if (ra > rb) swap(ra, rb);
			CASE(l = ra, r = rb, a = rnd.nextLongLong(1, 1000), b = rnd.nextLongLong(1, 1000), c = rnd.nextLongLong(1, 1000));
		}
		for (int i=0; i<20; i++){
			long long ra = rnd.nextLongLong(1, maxn);
			long long rb = rnd.nextLongLong(1, maxn);
			if (ra > rb) swap(ra, rb);
			CASE(l = ra, r = rb, a = rnd.nextLongLong(1, maxa), b = rnd.nextLongLong(1, maxa), c = rnd.nextLongLong(1, maxa));
		}
	}

};