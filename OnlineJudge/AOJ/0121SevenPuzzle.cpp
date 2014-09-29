//Bfs 7数码问题
//逆向考虑，最后状态总是"01234567"
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int direction[4] = { 1, -1, 4, -4 };
//存放到map中，缓存一下
map<string, int>dp;

void bfs(){
	queue<string>q;
	q.push("01234567");
	while (!q.empty()){
		string cur = q.front();
		q.pop();
		//index 找‘0’的位置
		int index = cur.find('0');
		for (int i = 0; i < 4; ++i){
			int n = index + direction[i];
			if (n >= 0 && n < 8&&
				//右上角左下角 有些没法移动
				!(n == 3 && i == 0) && 
				!(n == 4 && i == 1))  {
				string next(cur);
				swap(next[index], next[n]);
				if (dp.find(next) == dp.end()){
					dp[next] = dp[cur] + 1;
					q.push(next);
				}
			}
		}
	}
}
int main()
{
	bfs();
	string start;
	while (getline(cin,start)){
		//删除空格
		start.erase(remove(start.begin(), start.end(), ' '), start.end());
		cout << dp[start] << endl;
	}
	return 0;
}
//////出错的。。
int direction[4] = { -4, 1, 4, -1 };
map<string, int>dp;

string start;

int bfs(string&start,string&end){
	dp[start] = 0;
	queue<string>q;
	q.push(start);
	while (!q.empty()){
		string cur = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i){
			string temp(cur);
			int index = temp.find('0');
			//3,4点比较特殊
			if (index == 3 && i == 1)
				continue;
			int nindex = index + direction[i];
			if (nindex >= 0 && nindex <= 7){
				swap(temp[index], temp[nindex]);
				q.push(temp);
				dp[temp] = dp[cur] + 1;
			}
			if (!dp.count(end))
				return dp[end];
		}
	}
	return -1;
}
