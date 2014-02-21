/*Given an array S of n integers, find three integers in S such that the sum is 
closest to a given number, target. Return the sum of the three integers. 
You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		int min_gap = INT_MAX;
		int result = 0;
		for (auto i = num.begin(); i < prev(num.end(), 2);
			i = upper_bound(i, prev(num.end(), 2), *i))
		{
			auto b = next(i);
			auto c = prev(num.end());
			while (b < c)
			{
				const int sum = *i + *b + *c;
				const int gap = abs(sum - target);
				if (gap < min_gap){
					min_gap = gap;
					result = sum;
				}
				/*if (sum < target) b++;
				else			  c--;*/
				//熟练运用upper_bound lower_bound 函数
				if (sum < target)
					b = upper_bound(b, c, *b);
				else
					c = prev(lower_bound(b, c, *c));

			}
		}
		return result;
	}
};

// @2 Time Limit Exceeded
class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		auto begin = num.begin();
		auto end = num.end();
		int min_gap = INT_MAX;
		int result = 0;
		for (auto i = begin; i < prev(end, 2); i = upper_bound(i, prev(end, 2), *i))
		{
			for (auto j = next(i); j < prev(end); j = upper_bound(j, prev(end), *j))
			{
				// int temp = target - *i - *j;
				// if (binary_search(next(j), end, temp))
				// 	return target;
				for (auto k = next(j); k < end; k++)
				{
					const int sum = *i + *j + *k;
					const int gap = abs(sum - target);
					if (gap<min_gap)
					{
						result = sum;
						min_gap = gap;
					}
				}
			}
		}
		return result;
	}
};