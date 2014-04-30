//Div 2-250
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class CucumberMarket{
public:
	string check(vector<int>price, int budget, int k){
		//需求出最大个k sort(price.rbegin(),price.rend());
		sort(price.begin(), price.end());
		int num = accumulate(price.end()-k, price.end(), 0);
		return num > budget ? "NO" : "YES";
	}
};
