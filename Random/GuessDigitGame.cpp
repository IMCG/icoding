//赖炜海关于小王小李猜数字
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int>high, low;
int n;
string str;
bool judge(int n){
	for (auto& i : high){
		if (i < n)return true;
	}
	for (auto& i : low){
		if (i > n)return true;
	}
	return false;
}
int main(){
	//freopen("E:\\in.txt", "r", stdin);
	while (cin>>n&&n){
		high.clear();
		low.clear();
		getchar();//吸收回车
		getline(cin, str);
		if (str == "too high")high.push_back(n);
		else if (str == "too low")low.push_back(n);
		else if (str == "correct"){ judge(n) ? puts("yes") : puts("maybe"); continue; }
		while (cin >> n){
			getchar();
			getline(cin,str);
			if (str == "too high")high.push_back(n);
			else if (str == "too low")low.push_back(n);
			else if (str == "correct"){
				judge(n) ? puts("yes") : puts("maybe"); break;
			}
		}
	}
	return 0;
}