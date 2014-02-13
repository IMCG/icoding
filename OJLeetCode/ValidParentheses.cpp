/*Given a string containing just the characters 
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
		char tmp;
		for (auto& i : s)
		{
			if (left.find(i) != left.npos)
				t.push(i);
			else
			{
				if (t.empty() || right.find(i) != left.find(t.top()))
					return false;
				else
					t.pop();
			}
		}
		return t.empty();
	}
};