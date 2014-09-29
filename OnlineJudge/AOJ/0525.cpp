//二进制枚举
//当枚举一种情况的时候，可以不用考虑其他的
#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;
bitset<10000> cookie[10];
int main(int argc, char *argv[])
{
	int R, C;
	while (cin >> R >> C && R > 0)
	{
		int i, j;
		for (i = 0; i < R; ++i)
		{
			for (j = 0; j < C; ++j)
			{
				bool upwards;
				cin >> upwards;
				cookie[i][j] = upwards;
			}
		}
		//good job
		// 在横向一共有2^R种变换
		int permute_r = 1 << R;
		int result = 0;
		for (i = 0; i < permute_r; ++i)
		{
			// 完成当前的变换
			for (j = 0; j < R; ++j)
			{
				// 这一行是否应当翻个面
				if (i & (1 << j))
				{
					cookie[j].flip();
				}
			}
			// 对每一列分别算出朝上和朝下的煎饼个数，取其最大值
			int possible_answer = 0;
			for (j = 0; j < C; ++j)
			{
				int up_cookie_count = 0;
				for (int k = 0; k < R; ++k)
				{
					if (cookie[k][j])
					{
						++up_cookie_count;
					}
				}
				possible_answer += max(up_cookie_count, R - up_cookie_count);
			}
			// 结果取最大值
			result = max(result, possible_answer);
			// 复原
			for (j = 0; j < R; ++j)
			{
				if (i & (1 << j))
				{
					cookie[j].flip();
				}
			}
		}
		cout << result << endl;
	}
	return 0;
}