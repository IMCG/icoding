/*Write an algorithm such that if an element in an MxN matrix is 0, its entire 
row and column is set to 0.
*/
#include<iostream>
#include<vector>
using namespace std;
void print(vector<vector<int>>&result)
{
	for (auto& a : result)
	{
		for (auto& i : a)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void ChangeToZero(vector<vector<int>>&v)
{
	vector<int>a(v.size());
	vector<int>b(v[0].size());
	//Store the row and colume index with value 0
	for (size_t i = 0; i < v.size(); i++)
	{
		for (size_t  j = 0; j < v[0].size(); j++)
		{
			if (v[i][j] == 0){
				a[i] = 1;
				b[j] = 1;
			}
		}
	}
	for (size_t i = 0; i < v.size(); i++)
	{
		for (size_t j = 0; j < v[0].size(); j++)
		{
			if (a[i] == 1 || b[j] == 1)
				v[i][j] = 0;
		}
	}
}
int main()
{
	vector<vector<int>>result{ { 1, 2, 3, 4 }, { 2, 3, 0, 5 },{1, 0, 3, 4}, { 5, 2, 3, 5 } };
	print(result);
	ChangeToZero(result);
	print(result);

	return 0;
}