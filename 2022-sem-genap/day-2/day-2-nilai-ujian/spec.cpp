#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

const int MAXX = 100;
const int MAXDIGIT = 9;

class ProblemSpec : public BaseProblemSpec {
protected:
	string x;
	int ans;

	void InputFormat() {
		LINE(x);
	}

	void OutputFormat() {
		LINE(ans);
	}

	void GradingConfig() {
		TimeLimit(1);
		MemoryLimit(256);
	}

	void Constraints() {
		CONS(between(x, 0, MAXX));
		CONS(maxDigitsAfterPoint(x, MAXDIGIT));
	}

private:

	bool between(string s, long long mn, long long mx){
		bool udah = false;
		long long vs = 0;
		for (int i=0; i<(int)s.length(); i++){
			if (s[i] == '.') udah = true;
			else{
				vs *= 10;
				vs += s[i] - '0';
				if (udah) mn *= 10, mx *= 10;
			}
		}
		return vs >= mn && vs <= mx;
	}

	bool maxDigitsAfterPoint(string s, int mx){
		int idx = -1;
		for (int i=0; i<(int)s.length(); i++){
			if (s[i] == '.') idx = i;
		}
		if (idx == -1) return false;
		return (int)s.length() - idx - 1 <= mx;
	}
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
	void SampleTestCase1() {
		Input({
			"50.0"
		});
		Output({
			"1"
		});
	}

	void SampleTestCase2() {
		Input({
			"99.5"
		});
		Output({
			"2"
		});
	}

	void SampleTestCase3() {
		Input({
			"0.250"
		});
		Output({
			"4"
		});
	}

	void BeforeTestCase() {
		x.clear();
	}

	void TestCases() {
		CASE(x = "0.000");
		for (int i=0; i<40; i++){
			CASE(randomDouble(x));
		}
	}

private:
	void randomDouble(string &s) {
		long long mx = MAXX;
		int digs = rnd.nextInt(1, MAXDIGIT);
		for (int i=0; i<digs; i++) mx *= 10;
		long long val = rnd.nextLongLong(0, mx);
		for (int i=0; i<digs; i++){
			s.push_back(val % 10 + '0');
			val /= 10;
		}
		s.push_back('.');
		if (val == 0) s.push_back('0');
		else{
			while (val > 0){
				s.push_back(val % 10 + '0');
				val /= 10;
			}
		}
		reverse(s.begin(), s.end());
		// cout << s << '\n';
	}
};