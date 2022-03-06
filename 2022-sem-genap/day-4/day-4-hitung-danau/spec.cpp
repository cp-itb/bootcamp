#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

#define MAXN 1000
#define MAXM 1000

class ProblemSpec : public BaseProblemSpec {
protected:
	int N, M;
    vector<string> grid;
    int ans;

	void InputFormat() {
	  LINE(N, M);
      LINES(grid) % SIZE(N);
	}

    void OutputFormat() {
    	LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(2);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= N && N <= MAXN);
        CONS(1 <= M && M <= MAXM);
        CONS(isValidGrid(N, M, grid));
    }

private:
    bool isValidGrid(int n, int m, vector<string> grid){
        if (grid.size() != n || grid[0].length() != m) return false;
        for (auto r : grid){
            for (char c : r){
                if (c != '#' && c != '.') return false;
            }
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
        	"4 5",
            ".###.",
            "###..",
            "#..##",
            "#####"
        });
        Output({
        	"3"
        });
    }

    void SampleTestCase2() {
        Input({
            "1 1",
            "."
        });
        Output({
            "1"
        });
    }

    void SampleTestCase3() {
        Input({
            "1 1",
            "#"
        });
        Output({
            "0"
        });
    }

    void BeforeTestCase(){
    	grid.clear();
    }

    void TestCases() {
        // small tc
        for (int i=1; i<=2; i++){
            CASE(N = 6, M = 6, generateGrid(N,M,0,grid));
        }
        for (int i=1; i<=3; i++){
            CASE(N = 6, M = 6, generateGrid(N,M,30,grid));
        }
        for (int i=1; i<=3; i++){
            CASE(N = 6, M = 6, generateGrid(N,M,75,grid));
        }
        // medium tc
        for (int i=1; i<=2; i++){
            CASE(N = rnd.nextInt(1, 50), M = rnd.nextInt(1, 50), generateGrid(N,M,20,grid));
            CASE(M = rnd.nextInt(1, 50), N = rnd.nextInt(1, 50), generateGrid(N,M,80,grid));
        }
        // large tc
        for (int i=1; i<=2; i++){
            CASE(N = rnd.nextInt(1, MAXN), M = rnd.nextInt(1, MAXM), generateGrid(N,M,20,grid));
            CASE(M = rnd.nextInt(1, MAXN), N = rnd.nextInt(1, MAXM), generateGrid(N,M,80,grid));
        }
        for (int i=1; i<=3; i++){
            CASE(N = MAXN, M = MAXM, generateGrid(N, M, 50, grid));
        }
        // flat grid
        CASE(N = 1, M = MAXM, generateGrid(N,M,50,grid));
        CASE(N = MAXN, M = 1, generateGrid(N,M,50,grid));
        CASE(N = 2, M = MAXM, generateGrid(N,M,50,grid));
        CASE(N = MAXN, M = 2, generateGrid(N,M,50,grid));
    }

private:
    void generateGrid(int n, int m, int ratio, vector<string> &grid){
        grid.resize(n);
        for (int i=0; i<n; i++){
            grid[i].resize(m);
            for (int j=0; j<m; j++){
                int gacha = rnd.nextInt(1,100);
                if (gacha <= ratio) grid[i][j] = '#';
                else grid[i][j] = '.';
            }
        }
    }
};