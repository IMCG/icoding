//design a stack can return min of o(1)
#include<iostream>
#include<stack>
#include<vector>

const int row_num=5;
const int col_num=5;
using namespace std;
int main()
{
	int **ary = new int *[row_num];
	for(int i=0;i<row_num;++i)
		ary[i]=new int[col_num];

	vector<vector<int> > ary(row_num,vector<int> (col_num,0));

}