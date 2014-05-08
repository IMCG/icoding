//TrafficCongestionDiv2
//DP math
#include <iostream>
#include <vector>
using namespace std;
#define ll long long 
class TrafficCongestionDivTwo{
public:
	ll theMinCars(int treeHeight){
		vector<ll>dp(treeHeight + 1, 1);
	
		for (int i = 2; i <= treeHeight; ++i){
			for (int j = 0; j <= i - 2; ++j){
				dp[i] += 2*dp[j];
			}
		}
		return dp[treeHeight];
	}
};