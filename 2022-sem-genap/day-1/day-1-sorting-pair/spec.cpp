#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

#define MAXN 200000
#define MAXA 1000000000

class ProblemSpec : public BaseProblemSpec {
protected:
	int n;
	vector<int> a;
	vector<int> ans;

	void InputFormat() {
		LINE(n);
		LINE(a % SIZE(n));
	}

	void OutputFormat() {
		LINE(ans % SIZE(n));
	}

	void GradingConfig() {
		TimeLimit(1);
		MemoryLimit(256);
	}

	void Constraints() {
		CONS(1 <= n && n <= MAXN);
		CONS(noRepetition(a));
		CONS(inRange(a));
	}

private:
	bool noRepetition(vector<int> a){
		int m = a.size();
		sort(a.begin(), a.end());
		a.resize(unique(a.begin(), a.end()) - a.begin());
		return a.size() == m;
	}

	bool inRange(vector<int> a){
		for (int x : a){
			if (x < 1 || x >= MAXA) return false;
		}
		return true;
	}
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
	void SampleTestCase1() {
		Input({
			"5",
			"10 19 2 3 37"
		});
		Output({
			"3 4 1 2 5"
		});
	}

	void BeforeTestCase(){
		a.clear();
	}

	void TestCases() {
		CASE(n = 10, sortedPermutation(n, a, true));
		CASE(n = 10, sortedPermutation(n, a, false));
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
	void sortedPermutation(int n, vector<int> &a, bool asc){
		for (int i=1; i<=n; i++) a.push_back(i);
		if (!asc) reverse(a.begin(), a.end());
	}

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