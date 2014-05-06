//约瑟夫环另一种形式 注意pos的初值
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
class ChooseTheBestOne{
public:
	int countNumber(int N){
		vector<int>g(N);
		int i = 1;
		generate(g.begin(), g.end(), [&i](){return i++; });
		int count = 1;
		int pos = 0;
		while (g.size() > 1){
			int rem = ((int)(pow(count++, 3)) + pos - 1) % g.size();
			g.erase(g.begin() + rem);
			pos = rem%g.size();
		}
		return g[0];
	}
};