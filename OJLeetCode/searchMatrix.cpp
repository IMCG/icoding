/*Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool searchMatrix(const vector<vector<int>>&matrix, int target)
{
	const size_t m = matrix.size();
	const size_t n = matrix[0].size();
	for (auto& i : matrix)
	{
		//在这里必须要有等号。否则{{1}},搜索1，则return false；
		if (i[i.size() - 1] >= target)
		{
			return binary_search(i.begin(),i.end(), target);
		}
	}
	return false;
}
int main()
{
	vector<vector<int>>matrix={{ 1, 3, 5, 7 }, { 10, 11, 16, 20 },
	{ 23, 30, 34, 50 }};
	cout << boolalpha << searchMatrix(matrix, 3);
}