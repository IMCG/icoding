/*Author:xuesen
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
//binary_search
class Solution{
public:
	vector<int> twoSum(vector<int> &numbers, int target){
		//in order to getting index,i can use unordered_map
		unordered_map<int, int> mymap;
		int num = 0;
		for (size_t j = 0; j < numbers.size(); j++)
			mymap[numbers[j]] = num++;
		vector<int> result;

		auto end = numbers.end();
		for (auto i = numbers.begin(); i < prev(end);
			i = upper_bound(numbers.begin(), prev(end), *i)){
			int tmp = target - *i;
			if (binary_search(next(i), end, tmp)){
				result.push_back(mymap[*i]+1);
				result.push_back(mymap[tmp]+1);
				break;
			}
		}
		return result;
	}
};
//two pointer
class Solution1{
public:
	vector<int> twoSum(vector<int> &numbers, int target){
		vector<int> result;

		int begin = 0;
		int end = numbers.size() - 1;
		while (begin != end){
			int gap = numbers[begin] + numbers[end];
			if (target==gap){
				result.push_back(begin+1);
				result.push_back(end+1);
				break;
			}
			else if (target < gap){
				end--;
			}
			else{
				begin++;
			}
		}
		return result;
	}
};
//hash
/*Input:	[3,2,4], 6
  Output:	1, 1
  Expected:	2, 3    如果target==2*A[i]?
*/
class Solution2{
public:
	vector<int> twoSum(vector<int> &numbers, int target){
		vector<int> result;
		unordered_map<int, int> mapping;
		for (size_t i = 0;i<numbers.size();i++)
			mapping[numbers[i]] = 1;
		for (size_t i = 0; i < numbers.size(); i++){
			int gap = target - numbers[i];
			if (mapping.find(gap) != mapping.end())
			{
				result.push_back(i+1);
				result.push_back(mapping[gap]+1);
				break;
			}
		}
		return result;
	}
};

//AC    细节。。
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
		unordered_map<int, int> tmp;
		int num = 0;
		for (auto& i : numbers)
		{
			tmp[i] = num++;
		}
		int cur;
		for (int i = 0;i<numbers.size();i++)
		{
			cur = target - numbers[i];
			if (tmp.find(cur) != tmp.end() && i!=tmp[cur]){
				return vector<int>{i + 1, tmp[cur] + 1};
				break;
			}
		}
		return vector<int>();
	}
};
void Print(vector<int> result)
{
	for (auto c : result)
		cout << c << " ";
	cout << endl;
}
int main()
{
	int A[] = {2,7,11,15};
	vector<int> numbers(A, A + 4);
	Solution2 ss;
	vector<int> result = ss.twoSum(numbers, 9);
	Print(result);
	return 0;
}