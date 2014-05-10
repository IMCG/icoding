//http://community.topcoder.com/stat?c=problem_statement&pm=11801
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int minimumFaces(vector<string> rolls){
	for (auto& str : rolls){
		sort(str.begin(), str.end());
	}
	int res = 0;
	for (int i = 0; i < (int)rolls[0].size(); ++i){
		int temp = 0;
		for (int j = 0; j < (int)rolls.size(); ++j){
			//char to int
			temp = max(temp, rolls[j][i] - '0');
		}
		res += temp;
	}
	return res;
}
int main()
{
	vector<string>str{ "931", "821", "156", "512", "129", "358", "555" };
	cout << minimumFaces(str);
	cout << "\n";
}