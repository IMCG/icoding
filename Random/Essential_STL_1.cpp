/*Author:xuesen
*@Date:12/25
*@C++Primer
*/
#include<iostream>
#include<algorithm>
#include<numeric>
#include<functional>
#include<vector>
using namespace std;
const int val = 10;
bool isEven(int n){
	return n % 2 == 0;
}
class TwiceOver {
public:
	bool operator() (int val1, int val2)
{ 
	return val1 == val2/2 ? true : false; }
};
int main()
{
	vector<int> coll(10);
	vector<int> v1;
	/*简单查找算法*/
	find(coll.begin(), coll.end(), val);	//返回迭代器
	count(coll.begin(), coll.end(), val);	//返回次数
	/*Sort*/
	sort(coll.begin(), coll.end());
	sort(coll.begin(), coll.end(), greater<int>());
	/*接受一个谓词With the suffix_if*/
	find_if(coll.begin(), coll.end(), bind2nd(less<int>, 10));
	find_if(coll.begin(), coll.end(), isEven);//一个谓词
	count_if(coll.begin(), coll.end(), isEven);
	replace_if(coll.begin(), coll.end(), isEven, Val);

	/*Many of the algorithms that modify the container they are applied to come in two flavors:
	an inplace version that changes the container, and a version that returns 
	a copy of the container with thechanges applied.
	::The copy version always contains _copy in its name*/
	replace(coll.begin(), coll.end(), oldVal, newVal);
	/*接受一个目标迭代器with the suffix_copy*/
	replace_copy(coll.begin(), coll.end(), v1, oldVal, newVal);

	/*#include<numeric>::accumulate*/
	accumulate(coll.begin(), coll.end(), 0);
	accumulate(coll.begin(), coll.end(), 0, plus<int>());//functional

	/*#include<numeric>::adjacent_difference
	creates a new sequence in which the 
	value of each new element, other than the firstone, represents 
	the difference of the current and the preceding element*/
	adjacent_difference(coll.begin(), coll.end(), v1.begin());
	adjacent_difference(coll.begin(), coll.end(), v1.begin(),
		times<int>());
	/*adjacent_find()
	:looks for the first adjacent pair of duplicate elements*/
	piter = adjacent_find(ia, ia+8);
	iter = adjacent_find(vec.begin(), vec.end(), TwiceOver());
}