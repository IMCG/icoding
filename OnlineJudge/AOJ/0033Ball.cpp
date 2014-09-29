//穷举 用二进制枚举即可
#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;

int ball[10];
int main()
{
	int n;
	cin >> n;
	while (n--){
		for (int i = 0; i < 10; i++)
			cin >> ball[i];
		bitset<10>direction;
		int all = 1024;
		while (all-->0){
			direction = static_cast<bitset<10>>(all);
			bool perfect = true;
			int left = 0, right = 0;
			for (int i = 0; i < 10; ++i){
				if (direction[i]){
					if (ball[i]>left)
						left = ball[i];
					else{
						perfect = false;
						break;
					}
				}
				else{
					if (ball[i] > right)
						right = ball[i];
					else{
						perfect = false;
						break;
					}
				}
			}
			if (perfect)
				break;
		}
		puts(all >= 0 ? "YES" : "NO");
	}
	return 0;
}