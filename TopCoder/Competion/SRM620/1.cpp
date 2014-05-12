#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
//WiKi stable_sort
vector<int> sort(vector<string> score, int x)
{
    int n = score.size();
    vector<int> ids(n);
    for (int i = 0; i < n; i++) {
        ids[i] = i;
    }
    // we can use a custom comparator function using a lambda - new c++11 feature
    std::sort(ids.begin(), ids.end(), [&](int a, int b) {
            return make_pair(score[a][x],a) < make_pair(score[b][x],b);
    });
    return ids;
}
//Me
struct level{
	string str;
	int index;
	level(string s, int b) :str(s), index(b){}
	
};
bool solve(level&a, level&b);
class CandidateSelectionEasy{
public:
	vector<int>sort(vector<string>score, int x){
		int i = 0;
		vector<level>res;
		vector<int>rt;
		for (auto& st : score){
			res.push_back(level(st, i++));
		}
		stable_sort(res.begin(), res.end(),
			[&x](level a, level b){return a.str[x] < b.str[x]; });
		for (auto& i : res){
			rt.push_back(i.index);
		}
		return rt;
	}
};
int main()
{
	vector<string>arr{ "LAX", "BUR", "ONT", "LGB", "SAN", "SNA", "SFO", "OAK", "SJC" };
	CandidateSelectionEasy ss;
	vector<int>res = ss.sort(arr, 2);
	for (auto& i : res)
	{
		cout << i << " ";
	}
	return 0;
}