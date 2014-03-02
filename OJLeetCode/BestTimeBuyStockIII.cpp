/*Say you have an array for which the ith element is the price of a given 
stock on day i.
Design an algorithm to find the maximum profit. You may complete at most 
two transactions.
Note:
You may not engage in multiple transactions at the same time (ie, you 
must sell the stock before you buy again).
*/
//f(i)[0--i]  g(i)[i--n-1]
class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if (prices.size() < 2)return 0;
		const int n = prices.size();
		vector<int>f(n, 0);
		vector<int>g(n, 0);
		//
		for (int i = 1,valley = prices[0]; i < n; i++){
			valley = min(valley, prices[i]);
			f[i] = max(f[i - 1], prices[i] - valley);
		}
		for (int i = n - 2, peek = prices[n - 1]; i >= 0; i--){
			peek = max(peek, prices[i]);
			g[i] = max(g[i], peek - prices[i]);
		}
		int max_profit = 0;
		for (int i = 0; i < n; i++)
			max_profit = max(max_profit, f[i] + g[i]);
		return max_profit;
	}
};