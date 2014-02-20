/*N-Queens II
 *Now, instead outputting board configurations, 
 *return the total number of distinct solutions.	
 */
 #include <vector>
using namespace std;
//深搜+剪枝
class Solution{
public:
	int totalNQueens(int n){
		this->count = 0;
		this->columns = vector<int>(n, 0);
		this->principal_diagonals = vector<int>(2 * n, 0);
		this->counter_diagonals = vector<int>(2 * n, 0);

		vector<int> C(n, 0);//C[i]表示第i行皇后所在编号
		dfs(0, C);
		return this->count;
	}
private:
	int count;//解的个数
	//这三个变量用于剪枝
	vector<int> columns;//表示放置的皇后占据了那些列
	vector<int> principal_diagonals;//占据了那些主对角线
	vector<int> counter_diagonals;//占据了那些副对角线

	void dfs(int row, vector<int> &C){
		const int N = C.size();
		if (row == N){
			//终止条件
			this->count++;
			return;
		}
		for (int j = 0; j < N; ++j){
			//扩展状态，一列一列的试
			const bool ok = columns[j] == 0 &&
				principal_diagonals[row + j] == 0 &&
				counter_diagonals[row - j + N] == 0;
			if (ok){
				//剪枝：如果合法，继续递归
				C[row] = j;
				columns[j] = principal_diagonals[row + j] =
					counter_diagonals[row - j + N] = 1;
				dfs(row + 1, C);
				//撤销动作,回溯？？
				//C[row]=0;
				columns[j] = principal_diagonals[row + j] =
					counter_diagonals[row - j + N] = 0;
			}
		}
	}
};