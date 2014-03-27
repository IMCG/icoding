/*Given two words (start and end), and a dictionary, find all shortest transformation 
sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
*/
//好难呀
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
	vector<vector<string>> findLadders(string start, string end,
		unordered_set<string> &dict) {
		unordered_set<string>visited;//判重
		unordered_map<string, vector<string>>father;//树
		unordered_set<string>current, next;//用集合判重
		bool found = false;
		current.insert(start);
		while (!current.empty() && !found)
		{
			//本层全部置为已访问
			for (auto word : current)
			{
				visited.insert(word);
			}
			for (auto word : current)
			{
				for (size_t i = 0; i < word.length(); i++)
				{
					string new_word = word;
					for (char c = 'a'; c <= 'z'; c++)
					{
						if (c == new_word[i])continue;
						swap(new_word[i], c);

						if (new_word == end)
						{
							found = true;
						}
						if (visited.count(new_word) == 0
							&& dict.count(new_word) > 0
							|| new_word == end)
						{
							next.insert(new_word);
							father[new_word].push_back(word);
						}
						swap(c, new_word[i]);
					}
				}
			}
			current.clear();
			swap(next, current);
		}
		vector<vector<string>>result;
		if (found)
		{
			vector<string>path;
			bulidPath(father, path, start, end, result);
		}
		return result;
	}
private:
	void bulidPath(unordered_map<string, vector<string>>&father,
		vector<string>&path, string&start, string&word,
		vector<vector<string>>&result)
	{
		path.push_back(word);
		if (word == start){
			result.push_back(path);
			reverse(result.back().begin(), result.back().end());
		}
		else{
			for (auto f : father[word])
			{
				bulidPath(father, path, start, f, result);
			}
		}
		path.pop_back();
	}
};
int main()
{
	Solution s;
	string start = "hit";
	string end = "cog";
	unordered_set<string>dict{ "hot", "dot", "dog", "lot", "log" };
	vector<vector<string>>result = s.findLadders(start, end, dict);
	for (auto& ab : result)
	{
		for (auto& st : ab)
		{
			cout << st << " ";
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}