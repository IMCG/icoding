/*The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/
//AC  重点看int to string 的处理方法。
class Solution {
public:
	string countAndSay(int n) {
		if (n == 1)return "1";
		if (n == 2)return "11";
		string tmp = countAndSay(n - 1);
		string result;
		char c_prev = tmp[0];
		//char c_cur = tmp[0];
		for (size_t i = 0; i < tmp.size();){
			int count1 = 0;
			//c_cur = tmp[i];
			while (c_prev==tmp[i] && i<tmp.size()){
				count1++;
				i++;
			}
			if (count1){
				stringstream ss;
				ss << count1;
				string str;
				ss >> str;
				result = result + str + c_prev;
			}
			if (c_prev != tmp[i])
				c_prev = tmp[i];
			else
				break;
		}
		return result;
	}
};
//更精妙的应用。
class Solution{
public:
	string countAndSay(int n){
		string s("1");
		while(--n)
			s=getNext(s);
		return s;
	}
	string getNext(const string &s){
		stringstream ss;
		for(auto i=s.begin();i!=s.end();){
			auto j=find_if(i,s.end(),bind1st(not_equal_to<int>(),*i));
			ss<<distance(i,j)<<*i;
			i=j;
		}
		return ss.str();
	}
};

//思考错误
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)return "1";
		if (n == 2)return "11";
		string tmp = countAndSay(n - 1);
		string result;
		for (size_t i = 0; i < tmp.size();){
			int count1 = 0;
			while (tmp[i] == '1' && i<tmp.size()){
				count1++;
				i++;
			}
			if (count1){
				stringstream ss;
				ss << count1;
				string str;
				ss >> str;
				result = result + str + "1";
			}
			
			int count2 = 0;
			while (tmp[i] == '2' && i < tmp.size())	{
				count2++;
				i++;
			}
			//int to string 的方法。stringstream
			if (count2){
				stringstream ss1;
				ss1 << count2;
				string str1;
				ss1 >> str1;
				result = result + str1 + "2";
			}
		}
		return result;
    }
};