//感知机
//感知机W=0,b=0,μ=1
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef pair<int, int>p2;
map<p2, int>training{ { p2(3, 3), 1 }, { p2(4, 3), 1 }, { p2(1, 1), -1 } };

vector<int>w{ 0, 0 };
int b = 0;
//update item
//w<--w+μxy
//b<--b+μy
void update(p2 x, int y){
	w[0] = w[0] + 1 * y*x.first;
	w[1] = w[1] + 1 * y*x.second;
	b = b + 1 * y;
}
//y(wx+b)
int cal(p2 x, int y){
	int res = 0;
	res = x.first*w[0] + x.second*w[1];
	res += b;
	return res*y;
}
void check(){
	bool flag = false;
	for (auto& k : training){
		if (cal(k.first, k.second) <= 0){
			flag = true;
			update(k.first, k.second);
		}
	}
	if (!flag){
		printf("Result: w:[%d,%d],b:%d", w[0], w[1], b);
		exit(0);
	}
	flag = false;
}
//结果[1,1] -3
int main(){
	for (int i = 0; i < 16; ++i)
		check();
	return 0;
}
