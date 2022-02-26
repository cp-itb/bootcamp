#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

#define MAXN 100000
#define MAXA 1000000

class ProblemSpec : public BaseProblemSpec {
protected:
	int n;
	vector<int> x, y;
	long long ans;

	void InputFormat() {
		LINE(n);
		LINES(x, y) % SIZE(n);
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
		CONS(inRange(x, -MAXA, MAXA));
		CONS(inRange(y, -MAXA, MAXA));
	}

private:
	bool inRange(vector<int> a, int mn, int mx){
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
			"4",
			"-1 0",
			"3 1",
			"3 -1",
			"2 0"
		});
		Output({
			"7"
		});
	}

	void SampleTestCase2() {
		Input({
			"1",
			"100 100"
		});
		Output({
			"0"
		});
	}

	void BeforeTestCase(){
		x.clear();
		y.clear();
	}

	void TestCases() {
		CASE(n = 1, x = vector<int>(1, 0), y = vector<int>(1, 0));
		for (int i=0; i<20; i++){
			int mn = rnd.nextInt(-MAXA, MAXA);
			int mx = rnd.nextInt(-MAXA, MAXA);
			if (mn > mx) swap(mn, mx);
			CASE(n = 50, randomPoints(n, x, y, mn, mx));
		}
		for (int i=0; i<5; i++){
			int mn = rnd.nextInt(-MAXA, MAXA);
			int mx = rnd.nextInt(-MAXA, MAXA);
			if (mn > mx) swap(mn, mx);
			CASE(n = MAXN, randomPoints(n, x, y, -MAXA, MAXA));
		}
		CASE(n = MAXN, extremePoints(n, x, y));
	}

private:
	void randomPoints(int n, vector<int> &x, vector<int> &y, int mn, int mx){
		for (int i=0; i<n; i++){
			x.push_back(rnd.nextInt(mn, mx));
			y.push_back(rnd.nextInt(mn, mx));
		}
	}

	void extremePoints(int n, vector<int> &x, vector<int> &y){
		vector<int> ex = {-MAXA, MAXA};
		for (int i=0; i<n; i++){
			x.push_back(ex[rnd.nextInt(0, 1)]);
			y.push_back(ex[rnd.nextInt(0, 1)]);
		}
	}
};