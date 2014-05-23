//贪心算法
//WA  自己默认了雷达坐标是整数点。
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#pragma warning(disable:4996)
#define all(a) a.begin(),a.end()
typedef pair<int, int>se;
vector<se>vec;
int n, d;

//距离的平方
int dist(se a, se b){
	return (int)pow((b.first - a.first), 2) + (int)pow((b.second - a.second), 2);
}
int solve()
{
	int len = vec.size();
	int ans = 0, i = 0;
	while (i < len){
		se cur(vec[i].first, 0);
		while (dist(cur, vec[i]) <= d*d)
			cur.first++;
		cur.first--;

		ans++;
		while (i < len&&dist(cur, vec[i]) <= d*d)
			i++;
	}
	return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE

	int index = 1;
	while (cin >> n >> d ){
		if (!n&&!d)
			return 0;
		int a, b;
		vec.clear();
		while (n--){
			cin >> a >> b;
			vec.push_back(make_pair(a, b));
		}
		sort(all(vec));
		printf("Case %d: %d\n", index++, solve());

		getchar();
	}
	return 0;
}

//考虑每个小岛生成的区间
//如果区间不交叉i++,否则更新end(向左更新)
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
using namespace std;
#pragma warning(disable:4996)
// 区间
struct Section{
	double begin;
	double end;
	bool operator < (const Section& b) const{
		return begin < b.begin;
	}
};
int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif
	int n, d, __id;
	__id = 0;
	while (cin >> n >> d && n > 0)
	{
		int result = 0;
		vector<Section> s(n);
		for (int i = 0; i < n; ++i)
		{
			double x, y;
			cin >> x >> y;
			if (result == -1)
			{
				continue;
			}
			if (y > d)
			{
				// 如果y比半径大，一定不能覆盖
				result = -1;
				continue;
			}
			double r = sqrt(d * d - y * y);
			s[i].begin = x - r;
			s[i].end = x + r;
		}

		if (result == -1)
		{
			cout << "Case " << ++__id << ": " << result << endl;
			continue;
		}

		sort(s.begin(), s.end());
		double end = -numeric_limits<double>::max();
		for (vector<Section>::iterator it = s.begin(); it != s.end(); ++it)
		{
			// cout << it->begin << " " << it->end << endl;
			if (end < it->begin)
			{
				++result;
				end = it->end;
			}
			else if (end > it->end)
			{
				end = it->end;
			}
		}
		cout << "Case " << ++__id << ": " << result << endl;
	}
	return 0;
}