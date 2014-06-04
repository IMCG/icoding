//Flip Game
//起初不知道怎么计算距离
//状态压缩 BFS 好题呀  (可以暴力枚举)
//POJ 1753
//啥几把玩野错了
//all 0
bool achieve(){
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (map[i][j])
				return false;
	return true;
}
//all 1
bool iachieve(){
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (!map[i][j])
				return false;
	return true;
}
// 
//便于翻牌
bool map[4][4];
int dx[5]{ -1, 1, 0, 0, 0 };
int dy[5]{0, 0, 0, 1, -1};
//判断清一色 good
bool judge(){
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (map[i][j] != map[0][0])
				return false;
	return true;
}

//当只需改变1个的时候error
#include <iostream>
#include <queue>
#include <algorithm>
#include <bitset>
#pragma warning(disable:4996)
using namespace std;
typedef pair<int, int> pi;
bool map[4][4];
int directon[4][2] = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };
//0^1->1  1^1->0
bool safe(int x, int y){
	return x >= 0 && x < 4 && y >= 0 && y < 4;
}
void change(int x, int y){
	map[x][y] ^= 1;
	for (int i = 0; i < 4; ++i){
		int a = x + directon[i][0];
		int b = y + directon[i][1];
		if (safe(a, b))
			map[a][b] ^= 1;
	}
}
//all
bool judge(){
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (map[i][j] != map[0][0])
				return false;
	return true;
}
void solve(){
	if (judge()){
		printf("%d\n", 0);
		return;
	}
	int num = 1 << 16;
	bitset<16>bit;
	int min_ans = 20;
	while (--num){
		int ans = 0;
		bit = static_cast<bitset<16> >(num);
		for (int i = 0; i < 16; ++i){
			if (bit[i]){
				int a = i / 4;
				int b = i % 4;
				change(a, b);
				ans++;
			}
		}
		if (judge())
			min_ans = min(min_ans, ans);
	}
	min_ans == 20 ? printf("Impossible") : printf("%d\n", min_ans);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // ONLINE_JUDGE

	char ch;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j){
			cin >> ch;
			map[i][j] = ch == 'w' ? 0 : 1;
		}
	solve();
	return 0;
}
//4个方向&位运算tricky
//每个数值是一个状态
#include <iostream>
#include <queue>
#pragma warning(disable:4996)
using namespace std;
const int MAX = 70000;
//哈希 可以用set代替
// https://github.com/phrock/acm/blob/master/poj/1753/2.cpp
bool used[MAX];
typedef pair<int, int>pii;
queue<pii>q;
//当然也可以先转换为坐标在 变换
//st表示数值 x表示第几个
int change(int st, int x){
	st ^= (1 << x);
	if (x + 4 < 16)
		st ^= (1 << (x + 4));
	if (x - 4 >= 0)
		st ^= (1 << (x - 4));
	//两边界不能变
	if (x % 4 < 3 && x + 1 < 16)
		st ^= (1 << (x + 1));
	if (x % 4 > 0 && x - 1 >= 0)
		st ^= (1 << (x - 1));
	return st;
}
//bfs 因为是翻任意点,所以16个方向
//queue存储的整个状态，而不是point,因为最终看的是整体状态
int solve(int st){
	while (!q.empty())q.pop();
	if (st == 0 || st == 65535)
		return 0;
	q.push(make_pair(st, 0));
	while (!q.empty()){
		st = q.front().first;
		int t = q.front().second;
		q.pop();
		for (int i = 0; i < 16; ++i){
			int now = change(st, i);
			if (now == 0 || now == 65535)
				return t + 1;
			if (!used[now]){
				used[now] = true;
				q.push(make_pair(now, t + 1));
			}
		}
	}
	return -1;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	int num = 6;
	while (num--){
		int st = 0;
		char s[7];
		//char ch;
		memset(used, 0, sizeof(used));
		for (int i = 0; i < 4; ++i){
			scanf("%s", s);
			for (int k = 0; k < 4; ++k){
				//cin >> ch;
				if (s[k] == 'b')
					st = st | (1 << (i * 4 + k));
			}
		}
		used[st] = true;
		int ans = solve(st);
		ans == -1 ? puts("Impossible") : printf("%d\n", ans);
	}
	return 0;
}
