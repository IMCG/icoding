//Div 2-250
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
class EllysSubstringSorter{
public:
	string getMin(string S, int L){
		int len = S.length() - L;
		string result(S);
		for (int i = 1; i <= len; ++i){
			string t = S;
			sort(t.begin() + i, t.begin() + i + L);
			//the point 字典序比较
			result = min(result, t);
		}
		return result;
	}
};
int main()
{
	EllysSubstringSorter ss;
	cout << ss.getMin("ESPRIT", 3);
}

