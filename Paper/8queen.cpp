//8皇后
#include <stdio.h>
#include <stdlib.h>

#define N 8
int total = 0;
int C[N];//C[i]表示第i行皇后所在列
void output(){
	int i, j;
	printf("No. %d\n", total);
	for (j = 0; j < N; j++){
		for (i = 0; i < N; i++){
			if (C[i] != j)
				printf("0 ");
			else
				printf("1 ");
		}
		printf("\n");
	}
}
//check
int check(int row, int column){
	int ok = 1;
	for (int i = 0; i < row; i++){
		if (column == C[i] || row - i == column - C[i]
			|| row - i == C[i] - column){
			ok = 0;
			break;
		}
	}
	return ok;
}
void dfs(int row){
	if (row == N){
		++total;
		//output();
		return ;
	}
	for (int j = 0; j < N; j++){
		if (check(row, j)){
			C[row] = j;
			dfs(row + 1);
		}
	}
	return ;
}

int columus[N];
int principal[N * 2];
int counter[N * 2];
bool check2(int row, int column){
	return columus[column] == 0 && principal[row + column] == 0
		&& counter[row - column - N] == 0;
}
void dfs1(int row){
	if (row == N){
		total++;
		return;
	}
	for (int j = 0; j < N; j++){
		if (check2(row, j)){
			C[row] = j;
			columus[j] = principal[row + j] = counter[row - j + N] = 1;
			dfs(row + 1);
			columus[j] = principal[row + j] = counter[row - j + N] = 0;
		}
	}
	return;
}
int main()
{
	dfs1(0);
	printf("%d", total);
	return 0;
}

//N-Queens
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution{
public:
	vector<vector<string>>solveNQueens(int n){
		this->col = vector<int>(n, 0);
		this->pri = vector<int>(n * 2, 0);
		this->cor = vector<int>(n * 2, 0);
		this->total = 0;
		vector<vector<string>>result;
		vector<int>C(n, 0);
		dfs(0, C, result);
		return result;
	}
private:
	int total;
	vector<int>col;//列
	vector<int>pri;//主
	vector<int>cor;//副
	void dfs(int row, vector<int>&C,
		vector<vector<string>>&result)
	{
		const int N = C.size();
		if (row == N){
			total++;
			vector<string>cur;
			for (int i = 0; i < N; i++){
				string s(N, '.');
				for (int j = 0; j < N; j++){
					if (C[i] == j)
						s[j] = 'Q';
				}
				cur.push_back(s);
			}
			result.push_back(cur);
			return;
		}
		for (int j = 0; j < N; j++){
			const bool ok = col[j] == 0 && pri[row + j] == 0
				&& cor[row - j + N] == 0;
			if (ok){
				C[row] = j;
				col[j] = pri[row + j] = cor[row - j + N] = 1;
				dfs(row + 1, C, result);
				col[j] = pri[row + j] = cor[row - j + N] = 0;
			}
		}
		//return;
	}
};
void print(vector<vector<string>>&result){
	for (auto& i : result)
	{

		for (auto& a : i)
		{
			cout << a << endl;
		}
		cout << endl;
	}
}
int main()
{
	Solution s;
	vector<vector<string>>result;
	result = s.solveNQueens(8);
	print(result);

	return 0;
}
//直接输出
class Solution{
public:
	void solve(int n){
		this->C=vector<int>(n, 0);//第i行所在列
		this->total = 0;
		dfs(0);
		return;
	}
private:
	int total;
	vector<int>C;
	void dfs(int row)
	{
		const int N = C.size();
		if (row == N){
			total++;
			output();
			return;
		}
		for (int j = 0; j < N; j++){
			if (check(row,j)){
				C[row] = j;
				dfs(row + 1);
			}
		}
	}
	bool check(int row, int j){
		for (int i = 0; i < row; i++){
			if (j == C[i] || C[i] - j == row - i
				|| C[i] - j == i - row)
				return false;
		}
		return true;
	}
	void output(){
		const int N = C.size();
		cout << "No. " << total << endl;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				if (C[i] != j)
					cout << 0;
				else
					cout << 1;
			}
			cout << endl;
		}
		cout << endl;
	}
};

//深度优先也就这个规律。
#include <iostream>
#include <cmath>
using namespace std;

int columnForRow[8];
int total;
bool check(int row){
	for (int i = 0; i < row; i++){
		int diff = abs(columnForRow[row] - columnForRow[i]);
		if (diff == 0 || diff == row - i)
			return false;
	}
	return true;
}
void output(){
	cout << "NO. " << total << endl;
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (columnForRow[i] == j)
				cout << "@";
			else
				cout << ".";
		}
		cout << endl;
	}
	cout << endl;
}
void PlaceQueen(int row){
	if (row == 8){
		++total;
		output();
		return;
	}
	//可以先填写数字再检查。
	for (int i = 0; i < 8; ++i){
		columnForRow[row] = i;
		if (check(row)){
			PlaceQueen(row + 1);
		}
	}
}
int main()
{
	PlaceQueen(0);
	return 0;
}