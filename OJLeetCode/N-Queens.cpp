/*The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that 
no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, 
where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/
//深搜
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution{
public:
	vector<vector<string>> solveNQueens(int n){
		this->columns = vector<int>(n, 0);
		this->principal_diagonals = vector<int>(2 * n, 0);
		this->counter_diagonals = vector<int>(2 * n, 0);

		vector<vector<string>>result;
		vector<int> C(n, 0);
		dfs(0, C, result);
		return result;
	}
private:
	//三个剪枝变量
	vector<int> columns;//占据了那些列
	vector<int> principal_diagonals;//主对角线
	vector<int> counter_diagonals;//副对角线

	void dfs(int row, vector<int>&C, vector<vector<string>>&result){
		const int N = C.size();
		if (row == N){//终止条件也是收敛条件。可行解
			vector<string> solution;
			for (int i = 0; i < N; i++){
				string s(N, '.');
				for (int j = 0; j < N; ++j){
					if (j == C[i])
						s[j] = 'Q';
				}
				solution.push_back(s);
			}
			result.push_back(solution);
			return;
		}

		for (int j = 0; j < N; j++){//扩展状态
			const bool ok = columns[j] == 0 &&
				principal_diagonals[row + j] == 0
				&& counter_diagonals[row - j + N] == 0;
			if (ok){//扩展动作
				C[row] = j;
				columns[j] = principal_diagonals[row + j] =
					counter_diagonals[row - j + N] = 1;
				dfs(row + 1, C, result);
				//撤销动作
				//C[row]=0;
				columns[j] = principal_diagonals[j + row] =
					counter_diagonals[row - j + N] = 0;
			}
		}
	}
};
void print(vector<vector<string>>&result)
{
	for (auto& a : result)
	{
		for (auto& i : a)
		{
			cout << i << endl;
		}
		cout << endl;
	}
	cout << endl;
}
int main()
{
	Solution s;
	vector<vector<string>>result = s.solveNQueens(8);
	print(result);
	return 0;
}