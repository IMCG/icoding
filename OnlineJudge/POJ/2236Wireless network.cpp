//并差集
//当都修理好，并且距离够是才unite
//竟然AC
#ifndef ONLINE_JUDGE
#pragma warning(disable : 4996)
#endif
#include <iostream>
using namespace std;

#define MAX_N 1005
int parent[MAX_N];
int height[MAX_N];

void init(const int& n)
{
	for (int i = 0; i < n; ++i){
		parent[i] = i;
		height[i] = 0;
	}
}

int find(const int& x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	if (height[x] < height[y]){
		parent[x] = y;
	}
	else{
		parent[y] = x;
		if (height[x] == height[y]){
			++height[x];
		}
	}
}

bool same(const int& x, const int& y)
{
	return find(x) == find(y);
}

pair<int, int>computer[MAX_N];
bool status[MAX_N];
int N, d;

int square(int x){
	return x*x;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	cin >> N >> d;
	for (int i = 0; i < N; ++i)
		cin >> computer[i].first >> computer[i].second;
	init(N);
	char operation;
	int x, y;
	while (cin >> operation){
		if (operation == 'O')
		{
			cin >> x;
			//跟下标从0还是1开始有关系
			--x;
			status[x] = true;
			for (int i = 0; i < N; ++i){
				if (i != x&&status[i] && 
					square(computer[x].first - computer[i].first)
					+ square(computer[x].second - computer[i].second) 
					<= square(d))
					unite(x, i);
			}
		}
		else
		{
			cin >> x >> y;
			--x, --y;
			if (same(x, y))
				cout << "SUCCESS\n";
			else
				cout << "FALL\n";
		}
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif // !ONLINE_JUDGE

	return 0;
}
//平方计算太多了，初始化的时候算一次记录在一个二维数组中就够了。
//有可能超时
bool able[MAX_N][MAX_N];
for (int i = 0; i < N; ++i)
    {
        for (int x = i; x < N; ++x)
        {
            if (square(computer[x].first - computer[i].first) 
            	+ square(computer[x].second - computer[i].second) <= square(d))
            {
                able[i][x] = true;
                able[x][i] = true;
            }
        }
    }
    //下面改动即可
    if (status[i] && able[x][i])
    {
   		 unite(x, i);
    }