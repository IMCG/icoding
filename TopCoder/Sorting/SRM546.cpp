//ContestWinner
#include "algostuff.h"
using namespace std;
//可以把次数相等的都放到一个vector中
int getWinner(vector<int>events){
	map<int, int>mapping;
	vector<int>res;
	for (auto& e : events){
		mapping[e]++;
	}
	int count = 0;
	for (auto& e : mapping){
		count = max(e.second, count);
	}
	for (auto& e : mapping){
		if (e.second == count)
			res.push_back(e.first);
	}
	if (res.size() == 1)
		return res[0];
	//find_end
	int len = 0;
	int num = res[0];
	for (int i = 0; i < (int)res.size(); i++){
		auto m = find(events.rbegin(), events.rend(), res[i]);
		int dis = distance(events.rbegin(), m);
		//cout << dis << " " << res[i] << "\n";
		if (dis>len){
			len = dis;
			num = res[i];
		}
	}
	return num;
}
int main()
{
	vector<int>events{ 123, 123, 456, 456, 456, 123 };

	cout << getWinner(events);
}
