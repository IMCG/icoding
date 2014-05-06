//div 2-500
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
class GoodCompanyDivTwo{
public:
	int countGood(vector<int>superior, vector<int>workType){
		int len = superior.size();
		vector<int>a;
		set<int>b;
		int count = 0;
		for (int i = 0; i < len; ++i){
			a.clear();
			b.clear();
			a.push_back(workType[i]);
			for (int j = 0; j < len;++j){
				if (superior[j] == i)
					a.push_back(workType[j]);
			}
			//good idea
			b = set<int>(a.begin(), a.end());
			if (a.size() == b.size())
				count++;
		}
	}
};