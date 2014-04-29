//SRM 604 Div2-250
//Date :2014/4/29
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class FoxAndWord{
public:
	bool isPairs(string a, string b){
		int len = a.length();
		while (len--){
			rotate(a.begin(), a.begin() + 1, a.end());
			if (a == b)
				return true;
		}
		return false;
	}
	int howManyPairs(vector <string> words){
		int count = 0;
		const int len = words.size();
		vector<bool>used(len, false);
		for (int i = 0; i < len; ++i){
			used[i] = true;
			for (int j = 0; j < len; ++j){
				if (!used[j]){
					if (isPairs(words[i], words[j]))
						count++;
				}
			}
		}
		return count;
	}
};
int main()
{
	vector<string>words{ "eel", "ele", "lee" };
	FoxAndWord ss;
	cout << ss.howManyPairs(words);
}

//S=A+b
bool interesting(string s, string t)
{
    for (int i = 0; i < s.size(); i++) {
        string a = s.substr(0,i); //first i characters of s
        string b = s.substr(i);   //characters of s after the first i ones
        if (b+a == t) {
            return true;
        }
    }
    return false;
}
 
int howManyPairs(vector<string> words)
{
    int c = 0;
    for (string a: words) {
        for (string b: words) {
            if (a < b) {
                if (interesting(a,b)) {
                    c++;
                }
            }
        }
    }
    return c;
}

//Python
class FoxAndWord:
 def howManyPairs(self, words):
     
    # Does  any index i make a valid prefix and suffix ?
    def interesting(s,t):
        return any( s[i:]+s[0:i] == t for i in range(len(s)) )
     
    # iterate through pairs of words   
    def unorderedPairs(words):
        for s in words:
            for t in words:
                if s < t:
                    yield (s,t) # we could do it in one line but this might be easier to read
    # main:
    return sum( interesting(s,t) for (s,t) in unorderedPairs( words) )