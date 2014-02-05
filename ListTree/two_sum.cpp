#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
	void TwoSum(int A[], int n,int target)
	{
		int begin = 0;
		int end = n - 1;
		while(begin != end)
		{
			int sum = A[begin] + A[end];
			if (target == sum)
			{
				cout << begin << "" << end;
				break;
			}
			else if (target < sum)
			{
				end--;
			}
			else
				begin++;

		}
	}
	void twoSum(vector<int> coll,int target)
	{
		vector<vector<int> >result;
		auto last = coll.end();
		for (auto i = coll.begin(); i < prev(last);
			i = upper_bound(i, prev(last), *i))
		{
			if (binary_search(next(i),coll.end(),target-*i))
			{
				cout << *i << "" << target - *i;
				break;
			}
		}
	}
};
class Solution{
public:
	vector<int> twoSum(vector<int> numbers, int target)
	{
		unordered_map<int, int> mapping;
		vector<int>result;
		for (int i = 0; i<numbers.size(),i++)
			mapping[numbers[i]] = 1;
		for (int i = 0; i < numbers.size(), i++)
		{
			const int gap = target - numbers[i];
			if (mapping.find(gap) != mapping.end())
			{
				result.push_back(i + 1);
				result.push_back(mapping[gap] + 1);
				break;
			}
		}
		return result;
	}
	
};
int main()
{
	int A[] = { 2, 7, 11, 15 };
	vector<int> coll(A, A + 4);
	Solution s;
	s.twoSum(coll, 9);
}