#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

#define MAXN 1000
#define MAXA 1000000
#define MINA 0

class ProblemSpec : public BaseProblemSpec {
protected:
	int n, m;
	vector<vector<int>> grid;
	long long ans;
	string sans;

	void InputFormat() {
		LINE(n, m);
		LINES(grid) % SIZE(n);
	}

	void OutputFormat() {
		LINE(ans);
		LINE(sans);
	}

	void GradingConfig() {
		TimeLimit(1);
		MemoryLimit(256);
	}

	void Constraints() {
		CONS(1 <= n && n <= MAXN);
		CONS(1 <= m && m <= MAXN);
		CONS(1 < n*m);
		CONS(eachElementBetween(grid, MINA, MAXA));
	}

private:
	bool eachElementBetween(vector<vector<int>> a, int mn, int mx){
		for (int i=0; i<(int)a.size(); i++){
			for (int j=0; j<(int)a[i].size(); j++){
				if (a[i][j] < mn || a[i][j] > mx) return false;
			}
		}
		return true;
	}
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
	void SampleTestCase1() {
		Input({
			"4 4",
			"1 2 3 1",
			"3 1 1 2",
			"2 1 3 1",
			"1 1 3 2"
		});
		Output({
			"15",
			"BBKKBK"
		});
	}

	void SampleTestCase2() {
		Input({
			"1 2",
			"1 1"
		});
		Output({
			"2",
			"K"
		});
	}

	void BeforeTestCase(){
		grid.clear();
		sans.clear();
	}

	void TestCases() {
		CASE(n = 2, m = 1, grid = vector<vector<int>>(n, vector<int>(m, MINA)));
		for (int i=0; i<10; i++){
			CASE(n = 50, m = 50, randomGrid(n, m, grid, MINA, MAXA));
		}
		for (int i=0; i<5; i++){
			CASE(n = MAXN, m = MAXN, randomGrid(n, m, grid, MINA, MAXA));
		}
		CASE(n = MAXN, m = MAXN, grid = vector<vector<int>>(n, vector<int>(m, MINA)));
		CASE(n = MAXN, m = MAXN, grid = vector<vector<int>>(n, vector<int>(m, MAXA)));
	}

private:
	void randomGrid(int n, int m, vector<vector<int>> &a, int mn, int mx){
		for (int i=0; i<n; i++){
			a.emplace_back();
			for (int j=0; j<m; j++){
				a[(int)a.size() - 1].push_back(rnd.nextInt(mn, mx));
			}
		}
	}
};