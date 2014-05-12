//UnsortedSequence
//http://community.topcoder.com/stat?c=problem_statement&pm=11278
#include "algostuff.h"
using namespace std;
//先排序然后下一个全排列
vector<int>getUnsorted(vector<int>s){
	sort(s.begin(), s.end());
	if (next_permutation(s.begin(), s.end()))
		return s;
	return vector<int>();
}
int main()
{
	vector<int>a{ 2, 8, 5, 1, 10, 5, 9, 9, 3, 10, 5, 6, 6, 2, 8, 2, 10 };
	PRINT_ELEMENTS(getUnsorted(a));

	return 0;
}