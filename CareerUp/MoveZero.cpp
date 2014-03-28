/*Given a number in an array form, Come up with an algorithm to push 
all the zeros to the end. 
Expectation : O(n) solution
典型的荷兰国旗问题
*/
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
void Move(vector<int>&arr)
{
	int m = arr.size();
	int left = 0, right = m - 1;
	while (left < right)
	{
		while (arr[left] != 0 && left < right)
			left++;
		while (arr[right] == 0 && left < right)
			right--;
		if (left < right){
			swap(arr[left++], arr[right--]);
		}
	}
}
//Using STL
void Move1(vector<int>&arr)
{
	partition(arr.begin(), arr.end(), bind1st(equal_to<int>(), 0));
	reverse(arr.begin(), arr.end());
}
int main()
{
	vector<int>cur{ 0, 1, 2, 0, 3, 2, 0, 4 };
	Move(cur);
	for (auto& i : cur){
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
