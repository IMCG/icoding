//K Best  POJ 3111  Good
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;

#pragma warning(disable:4996)
#define forn(i,n) for(int i=0;i<int(n);++i)
const int mx = 100005;
int n, k;
double s;
//结构体排序 加入id
struct jewel{
	int v, w;
	int id;
	bool operator<(const jewel&other)const{
		return v - s*w>other.v - s*other.w;
	}
};
jewel ve[mx];
int ids[mx];

bool judge(double mid){
	s = mid;
	sort(ve, ve + n);
	double tv = 0, tw = 0;
	forn(i, k){
		tv += ve[i].v;
		tw += ve[i].w;
	}
	return tv / tw > mid;
}
void solve(double l,double r){
	double m;
	//选100超时了，选50
	for (int i = 0; i < 100; ++i){
		judge(m = (l + r) / 2) ? l = m : r = m;
	}
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE

	cin >> n >> k;
	double l = 0, r = 0;
	forn(i, n){
		cin >> ve[i].v >> ve[i].w;
		ve[i].id = i + 1;
		r = max(r, (double)ve[i].v / ve[i].w);
	}
	//ve[mx]已经排好
	solve(l, r);
	forn(i, k)
		ids[i] = ve[i].id;
	sort(ids, ids + k);
	forn(i, k)
		cout << ids[i] << " ";
	cout << "\n";
	return 0;
}