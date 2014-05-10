//Recursion
/*
	for (auto& ch : "wolf")
	{
		//output 5's ch
		cout << ch << " ....\n";
	}
*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
//string & stringstream
string wolf(int r){
	stringstream ss;
	string t("wolf");
	for (auto& ch : t){
		//for (int i = 0; i < r; ++i)
			//ss << ch;
		ss << string(r, ch);
	}
	return ss.str();
}
string wolf1(int r){
	string res="";
	string t("wolf");
	for (auto& ch : t){
		//注意string构造函数
		res += string(r, ch);
		
	}
	return res;
}
string check(string &str){
	if (str=="")
		return "VALID";
	int r = 1;
	while (4 * r <= (int)str.length()){
		if (wolf(r) == str.substr(0, 4 * r)){
			return check(str.substr(4 * r));
		}
		r += 1;
	}
	return "INVALID";
}
int main()
{
	/*int r = 1;
	string str("wolfwolf");
	string tmp = wolf(r);
	string ab = str.substr(0, 4 * r);
	cout << tmp << " " << tmp.length() << " \n";
	cout << ab << " " << ab.length() << " \n";
	cout << boolalpha << (ab == tmp) ? true : false;*/
	string str;
	while (cin >> str){
		cout << check(str) << "\n";
	}

	return 0;
}
//string parsing
//Count the number of initial ws, let it be r. The following letters 
//must be r 'o' characters, then r 'l' characters and r 'f' characters.
string check(string str)
{
    int i = 0;
    int len = str.length();
    while ( i < len ) {
        if (str[i] != 'w') {
            return "INVALID";
        }
        int r = 0;
        // Count the number of times w repeats as we move the pointer (i):
        while ( (i < len) && (str[i] == 'w') ) {
            r++;
            i++;
        }
        // repeat for o, l and f: (in that order):
        char chars[3] = { 'o', 'l', 'f' }; 
        for (char ch: chars) {
            // repeat r times:
            for (int k = 0; k < r ; k++) {
                // next character must a) exist b) be equal to ch
                if ( (i >= len) || ( str[i] != ch) ) {
                    return "INVALID";
                }
                // move pointer:
                i++;
            }
        }
    }
    return "VALID";
}
