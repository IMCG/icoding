//来自编程之美
//Program to findmaximum sum subarray in a given 2D array
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
#define ROW 4
#define COL 5
int sum_cur(vector<vector<int>>&m,int i, int j)
{
	int sum = 0;
	for (int a = 0; a <= i; a++)
	{
		for (int b = 0; b <= j; b++)
		{
			sum += m[a][b];
		}
	}
	return sum;
}
int Sum(vector<vector<int>>&m,size_t i, size_t i_1, size_t j, size_t j_1)
{
	return sum_cur(m, i_1, j_1) + sum_cur(m, i, j) - sum_cur(m, i, j_1) - sum_cur(m, i_1, j);
}
int findMaxSum(vector<vector<int>> &M)
{
	int sum_final = INT_MIN;
	for (size_t i = 0; i < M.size(); i++)
	{
		for (size_t i_1 = i; i_1 < M.size(); i_1++)
		{
			for (size_t j = 0; j < M[0].size(); j++)
			{
				for (size_t j_1 = 0; j_1 < M[0].size(); j_1++)
				{
					sum_final = max(sum_final, Sum(M, i, i_1, j, j_1));
				}
			}
		}
	}
	return sum_final;
}
void Print(vector<vector<int>>&v)
{
	for (auto& a : v)
	{
		for (auto& i : a)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int main()
{
	vector<vector<int>> m = { { 1, 2, -1, -4, -20 },
								{ -8, -3, 4, 2, 1 },
								{ 3, 8, 10, 1, 3 },
								{ -4, -1, 1, 7, -6 } };
	Print(m);
	/*int sum = sum_cur(m, 3, 3) + sum_cur(m, 0, 0) - sum_cur(m, 0, 3) - sum_cur(m, 3, 0);
	cout << sum << endl;*/
	int sum = findMaxSum(m);
	cout << sum;
	return 0;
}


//假设上下边界已经确定了，则可以化为一维的情况
/*@param
  A,数组
  n,m   a,c 为上下边界。
  BC(a,c,i)表示a,c行之间，第i列之间元素的和。
*/
  int MaxSum(int **A,int n,int m)
  {
  	maximum=INT_MIN;
  	for (int a = 1; a <= n; ++a)
  	{
  		for (int c = a; c <= n; ++c)
  		{
  			Start=BC(a,c,m);
  			All=BC(a,c,m);
  			for (int i = 0; i < 1; ++i)
  			{
  				if(Start<0)
  					Start=0;
  				Start+=BC(a,c,i);
  				if(Start>All)
  					All=Start;
  			}
  			if(ALl>maximum)
  				maximum=ALl;
  		}
  	}
  	return maximum;
 }