#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

const int maxn = 10, maxa = 50;
const long long maxr = 1e15;

class ProblemSpec : public BaseProblemSpec {
protected:
	int n;
	long long l, r;
	vector<long long> a;
	long long ans;

	void InputFormat() {
		LINE(n, l, r);
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
		CONS(1 <= n <= maxn);
		CONS(1 <= l && l <= r && r <= maxr);
		CONS(eachElementBetween(a, 1, maxa));
	}

private:
	bool eachElementBetween(vector<long long> a, int mn, int mx){
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
			"3 2 10",
			"2 3 4"
		});
		Output({
			"7"
		});
	}

	void SampleTestCase2() {
		Input({
			"1 5 5",
			"1"
		});
		Output({
			"1"
		});
	}

	void BeforeTestCase() {
		a.clear();
	}
	
	void TestCases() {
		CASE(n = l = r = 1, a = vector<long long>(1, 1));
		for (int i=0; i<20; i++){
			long long ra = rnd.nextLongLong(1, 1000);
			long long rb = rnd.nextLongLong(1, 1000);
			if (ra > rb) swap(ra, rb);
			CASE(n = rnd.nextInt(1, maxn), l = ra, r = rb, randomArray(n, a, 1, maxa));
		}
		for (int i=0; i<20; i++){
			long long ra = rnd.nextLongLong(1, maxr);
			long long rb = rnd.nextLongLong(1, maxr);
			if (ra > rb) swap(ra, rb);
			CASE(n = rnd.nextInt(1, maxn), l = ra, r = rb, randomArray(n, a, 1, maxa));
		}
	}
	void randomArray(int n, vector<long long> &a, int mn, int mx){
		for (int i=0; i<n; i++){
			a.push_back(rnd.nextInt(mn, mx));
		}
	}
};