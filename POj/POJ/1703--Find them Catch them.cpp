//Poj 1703
//Find them ,Catch them
//并差集
//2014/05/19
//http://www.hankcs.com/program/cpp/poj-1703-find-them-catch-them.html
//可见所有元素个数为2 * N，如果i表示属于帮派A，那么i + N表示属于帮派B
//和判断几个联通分支的区别
//食物链的简单版本
/*
我们只知道x和y不属于同一集合，但我们不能确定究竟x属于集合A还是集合B，
于是我们保留所有可能性，对x-A和x-B都做了一次记录。
*/
#ifndef ONLINE_JUDGE
#pragma warning(disable : 4996)
#endif
#include <iostream>
using namespace std;

#define MAX_N 100000 * 2 + 16
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


int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
	//freopen("E:\\out.txt", "w", stdout);
#endif
	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		init(N * 2);
		char message;
		int x, y;
		getchar();
		while (M--)
		{
			// cin 会导致TLE，哭笑不得
			// cin >> message >> x >> y;
			// 输入字符的时候请注意
			scanf("%c%d%d%*c", &message, &x, &y);
			if (message == 'A')
			{
				if (same(x, y)){
					cout << "In the same gang." << endl;
				}
				else if (same(x, y + N)){
					cout << "In different gangs." << endl;
				}
				else{
					cout << "Not sure yet." << endl;
				}
			}
			else
			{
				unite(x, y + N);
				unite(x + N, y);
			}
		}
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
	//fclose(stdout);
	//system("E:\\out.txt");
#endif
	return 0;
}