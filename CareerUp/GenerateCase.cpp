/*http://www.careercup.com/question?id=5761652767064064
 	Write code to generate all possible case combinations of a given 
 	lower-cased string. (e.g.


	"0ab" -> ["0ab", "0aB", "0Ab", "0AB"])
*/

#include <iostream>
#include <string>
#include <vector> 
#include <set>
using namespace std;
class Solution{
public:
	vector<string> GenerateCase(string &str)
	{
		set<string>result;
		if (str.length() == 0)return vector<string>();
		this->selected=vector<int>(str.size(), 0);
		string cur;
		dfs(result, cur, 0, str);
		return vector<string>(result.begin(),result.end());
	}
private:
	vector<int>selected;
	void dfs(set<string>&result, string &cur, int start, string &str)
	{
		const int m = str.length();
		if (start == m){
			string sub;
			for (int i = 0; i < m; i++)
			{
				if (isdigit(str[i])||!selected[i])
					sub.push_back(str[i]);
				else if (selected[i])
					sub.push_back(str[i] ^ 32);
			}
			result.insert(result.begin(), sub);
			return;
		}
		selected[start] = 0;
		dfs(result, cur, start + 1, str);
		selected[start] = 1;
		dfs(result, cur, start + 1, str);
	}
};
void print(vector<string>&result)
{
	for (auto& i : result) {
		cout << i << endl;
	}
}
int main()
{
	Solution s;
	string str = "0ab";
	vector<string>result = s.GenerateCase(str);
	print(result);

	return 0;
}

//a simple recursion
#include <iostream>
#include <vector>
#include <string>
using namespace std;
void printString(string s, int i){
	if (i == s.length()){
		cout << s << endl;
		return;
	}
	if (isdigit(s[i])){
		printString(s, i + 1);
	}
	else{
		printString(s, i + 1);
		s[i] = s[i] ^ 32;
		printString(s, i + 1);
		/*if (s[i] >= 'A' && s[i] <= 'Z'){
			s[i] = s[i] + 0x20;
			printString(s, i + 1);
		}
		else{
			s[i] = s[i] - 0x20;
			printString(s, i + 1);
		}*/
	}
}
int main(){
	string s = "0ab";
	printString(s, 0);
	return 0;
}