//leetcode 上有好几道题
//Next Permutation自己实现
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;
template<typename BidiIt>
bool nextPermutation(BidiIt first, BidiIt last)
{
	//Get a reversed range to simplify reversed traversal
	const auto rfirst = reverse_iterator<BidiIt>(last);
	const auto rlast = reverse_iterator<BidiIt>(first);

	//Begin from the second last element to the first element
	auto pivot = next(rfirst);

	//Find 'pivot',which is the first element that is no less than its
	//successor,'Prev' is used since 'pivort' is a 'reversed_iterator'
	while (pivot != rlast && !(*pivot < *prev(pivot)))
		++pivot;

	//No such element found,current sequence is already the largest
	//permutation,then rearrage to the first permutation and return false
	if (pivot == rlast){
		reverse(rfirst, rlast);
		return false;
	}
	//Scan from right to left,find the first element that is greater than
	//'pivot'
	auto change = find_if(rfirst, pivot, bind1st(less<int>(), *pivot));
	
	swap(*change, *pivot);
	reverse(rfirst, pivot);

	return true;
}
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
int main()
{
	vector<int>num{ 7, 2, 3, 4, 6, 8 };
	nextPermutation(num.begin(), num.end());
	for (auto& a : num)
	{
		cout << a << " ";
	}
	return 0;
}