//杭电资料 input 以及output
//分清 是以空格还是以回合为分隔符的。
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string solve(string&str){
	for (int i = 0; i < (int)str.size();++i){
		if (!isalpha(str[i]))
			continue;
		str[i] = (str[i] - 5 >= 'A') ? str[i] - 5 : str[i] - 5 + 26;
	}
	return str;
}
int main()
{
	//ifstream in("E:\\in.txt");
	string s, t, e;
	while (getline(cin, s) && s != "ENDOFINPUT"){
		getline(cin, t);
		cout << solve(t) << "\n";
		getline(cin, e);
	}
	return 0;
}