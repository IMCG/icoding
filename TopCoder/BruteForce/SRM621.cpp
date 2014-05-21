// Single Round Match 621 Round 1 - Division II, Level Two
//NumbersChallenge
//暴力搜索，小数据通过，大数据直接挂掉
//数组范围取小了
#include <iostream>
#include <vector>
bool have[0x3f3f3f3f];
using namespace std;
int MinNumber(vector<int>&S){
	memset(have, 0, sizeof(have));
	int len = S.size();
	int num = 1 << len;
	while (--num){
		int sum = 0;
		for (int i = 0; i < len; ++i){
			if (num&(1 << i))
				sum += S[i];
		}
		have[sum] = 1;
	}
	for (int i = 1; i < 200006; ++i)
		if (!have[i])
			return i;
	return 0;
}
int main()
{
	vector<int>S{ 94512, 2, 87654, 81316, 6, 5, 6, 37151, 6, 139, 1, 36, 307, 1, 377, 101, 8, 37, 58, 1 };
	cout << MinNumber(S) << "\n";
	return 0;
}