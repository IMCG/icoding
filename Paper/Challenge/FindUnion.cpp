#include <iostream>
using namespace std;
#define MAX_N 100

int par[MAX_N];//父亲
int high[MAX_N];//树的高度

//初始化
void init(int n){
	for (int i = 0; i < n; i++){
		par[i] = i;//都是根
		high[i] = 0;
	}
}
//查询树的根
int find(int x){
	if (par[x] == x)
		return x;
	else
		return par[x] = find(par[x]);
}
//合并x y所在的集合
void unite(int x, int y){
	x = find(x);
	y = find(y);
	if (x == y)return;

	if (high[x] < high[y])
		par[x] = y;
	else{
		par[y] = x;
		if (high[x] == high[y])
			high[x]++;
	}
}
//判断是否属于同一集合
bool same(int x, int y){
	return find(x) == find(y);
}