//anagram变位词
#include "algostuff.h"
using namespace std;
//map的应用
map<string, vector<string>>mapping;
int getMaximum(vector<string> S){
	for (auto& str : S){
		string temp(str);
		sort(temp.begin(), temp.end());
		mapping[temp].push_back(str);
	}
	return mapping.size();
}
//set去重复
int getMaximum2(vector<string> S){
	set<string> A;                      // Declare a set A, which will contain the sorted strings
	for (int i = 0; i < S.size(); i++)
	{
		sort(S[i].begin(), S[i].end());  // Convert each string into its sorted form...
		A.insert(S[i]);                  // ... and put it into A
	}
	return A.size();                    // Return the number of elements of A

}
int main()
{
	vector<string>S
	{ "creation", "sentence", "reaction", "sneak", "star", "rats", "snake" };
	cout << getMaximum(S) << "\n";
}