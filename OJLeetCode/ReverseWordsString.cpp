/*Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".
*/
class Solution {
public:
    void reverseWords(string &s) {
        if (s.empty())return;
		stringstream ss(s);
		vector<string> v;
		string tmp;
		string result;
		while (ss >> tmp){
			if (v.empty())
				v.insert(v.begin(), tmp);
			else{
				tmp += " ";
				v.insert(v.begin(), tmp);
			}
		}
		for (auto& i : v){
			result += i;
		}
		s = result;
    }
};