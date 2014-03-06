/*Given a string containing just the characters '(' and ')', find the length of 
the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses 
substring is "()()", which has length = 4.
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        const int len = s.length();
		if (len < 2)return 0;
		stack<int>st;//存储'('的位置。
		int result = 0;
		int left = -1;//')'位置  
		for (int i = 0; i < len; i++){
			if (s[i] == '(')
				st.push(i);
			else{
				if (st.empty())
					left = i;
				else{
					//find a matching pair
					st.pop();
					if (st.empty())
						result = max(result, i - left);
					else
						result = max(result, i - st.top());
				}
			}
		}
		return result;
    }
};