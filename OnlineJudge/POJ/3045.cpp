/*ti=sigama(W)-si，
使得max(ti)最小 按照w+s排序
*/
#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)
const int mx = 50005;
int N;
//w+s 排序最大的在最底下
struct p2{
	//w ,h
	int a, b;
	p2(int a = 0, int b = 0) :a(a), b(b){}
	bool operator<(const p2&p)const {
		return p.a + p.b < a + b;
	}
};
p2 vec[mx];
int main(){
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt","r",stdin);
#endif // !ONLINE_JUDGE
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N;
	int total = 0;
	for (int i = 0; i < N; ++i){
		cin >> vec[i].a >> vec[i].b;
		total += vec[i].a;
	}
	sort(vec, vec + N);
	int risk = -1000000001;
	//分别计算
	for (int i = 0; i < N; ++i){
		total -= vec[i].a;
		risk = max(risk, total - vec[i].b);
	}
	cout << risk << "\n";
	return 0;
}