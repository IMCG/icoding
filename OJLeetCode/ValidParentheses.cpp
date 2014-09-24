/*update:2014/9/24
Given a string containing just the characters 
'(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 The brackets must close in the correct order, 
 "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
class Solution {
public:
	bool isValid(string s) {
		string left = "[{(";
		string right = "]})";
		stack<char> t;
		for (auto& i : s)
		{
			//left.find(i) != string::npos
			if (left.find(i) != left.npos)
				t.push(i);
			else
			{
				//st.top()!=left[right.find(c)]  ok..
				if (t.empty() || right.find(i) != left.find(t.top()))
					return false;
				else
					t.pop();
			}
		}
		return t.empty();
	}
};