/*Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction 
(ie, buy one and sell one share of the stock), design an algorithm 
to find the maximum profit.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//贪心法，分别找到价格最低和最高的一天，低进高出，注意最低一天要在最高一天前
//把原始价格变成查分序列，本体可以是最大m子段和，m=1;
class Solution {
public:
	int maxProfit(vector<int> &prices) {
		//这里一定要有size的判断。
		if (prices.size() < 2)
			return 0;
		int profit = 0;//差价，利润
		int cur_min = prices[0];	//当前最小
		
		for (size_t i = 1; i < prices.size(); i++)
		{
			profit = max(profit, prices[i] - cur_min);
			cur_min = min(cur_min, prices[i]);
		}
		return profit;
	}
};
int main()	
{
	vector<int>prices{ 1, 2, 4};
	Solution s;
	cout<<s.maxProfit(prices);
	return 0;
}