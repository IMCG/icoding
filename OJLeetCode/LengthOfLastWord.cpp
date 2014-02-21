/*Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/

//注意"          "的情况。
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        const string str(s);
        if (str == ""|| str==" ")
			 return 0;
		stringstream ss(str);
		string temp;
		vector<string>cache;
		while (ss >> temp)
			cache.push_back(temp);
		if (cache.empty())
			return 0;
		temp = cache.back();
		
		return temp.length();
    }
};

//STL
class Solution{
public:
	int lengthOfLastWord(const char *s){
		const string str(s);
		auto first=find_if(str.rbegin(),str.rend(),::isalpha);
		auto last=find_if_not(str.first,str.rend(),::isalpha);
		return distance(first,last);
	}
};
//顺序扫描
class Solution{
public:
	int lengthOfLastWord(const char *s){
		int len=0;
		while(*s){
			if(*s++ != ' ')
				++len;
			else if(*s && *s != ' ')
				len=0;
		}
		return len;
	}
};