/*Given a digit string, return all possible letter combinations that the 
number could represent.
Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].*/
//dfs 
class Solution {
public:
    const vector<string> keyboard{ " ", "", "abc", "def", // '0','1','2',...
		"ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    vector<string> letterCombinations(string digits) {
        vector<string>result;
		dfs(result,"", digits, 0);
		return result;
    }
private:
	void dfs(vector<string>&result, string cur, 
		string digits, int start)
	{
		if (start == digits.length()){
			result.push_back(cur);
			return;
		}
		//good
		for (auto& c : keyboard[digits[start]-'0']){
			dfs(result, cur+c, digits, start + 1);
		}
	}
};