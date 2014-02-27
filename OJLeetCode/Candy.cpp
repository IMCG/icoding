/*There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/
//两边循环。
class Solution {
public:
	int candy(vector<int> &ratings) {
		int n = ratings.size();
		if (n == 1 || n==0)return n;
		vector<int>num(n, 1);
		for (int i = 1; i < n; i++){
			if (ratings[i] > ratings[i - 1])
				num[i] = num[i-1] + 1;
		}
		for (int i = n - 2; i>=0; i--){
			if (ratings[i] > ratings[i + 1] && num[i]<=num[i+1])
				num[i] = num[i + 1] + 1;
		}
		return accumulate(num.begin(), num.end(), 0);
	}
};