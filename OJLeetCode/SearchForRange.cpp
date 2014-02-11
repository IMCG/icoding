//Search For a range  STL
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//Given[5,7,7,8,8,10]  return [3,4]
class Solution{
public:
	vector<int> searchRange(int A[], int n,int target)
	{
		const int l = distance(A, lower_bound(A, A + n, target));
		const int r = distance(A, prev(upper_bound(A, A + n, target)));
		if (A[l] != target)
			return vector<int> {-1, -1};
		else
			return vector<int> {l, r};
	}
};
int main()
{
	int A[] = { 5, 7, 7, 8, 8, 10 };
	Solution s;
	vector<int> t = s.searchRange(A, 6, 8);
	for (auto& i : t)
	{
		cout << i << " ";
	}
	cout << endl;
}
//自己实现lower_bound   upper_bound  寻找的边界不同
//代码有点问题？
template<typename ForwardIterator,typename T>
ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, T value)
{
	while (first != last)
	{
		auto mid = next(first, distance(first, last) / 2);
		if (value > *mid) first = ++mid;
		else			   last = mid;
	}
	return first;
}
template<typename ForwardIterator, typename T>
ForwardIterator upper_bound(ForwardIterator first, ForwardIterator last, T value)
{
	while (first != last)
	{
		auto mid = next(first, distance(first, last) / 2);
		if (value <= *mid) first = ++mid;		//与lower_bound仅此不同
		else			   last = mid;
	}
	return first;
}

//STL 中的版本。
template<class ForwardIt, class T>
ForwardIt lower_bound(ForwardIt first, ForwardIt last, const T& value)
{
    ForwardIt it;
    typename std::iterator_traits<ForwardIt>::difference_type count, step;
    count = std::distance(first, last);
 
    while (count > 0) {
        it = first; 
        step = count / 2; 
        std::advance(it, step);
        if (*it < value) {
            first = ++it; 
            count -= step + 1; 
        } else count = step;
    }
    return first;
}
