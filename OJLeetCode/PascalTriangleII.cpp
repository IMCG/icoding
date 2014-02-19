/*Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>result;
		result.push_back(1);
		if (rowIndex == 0)return result;
		if (rowIndex == 1)return vector<int>{1, 1};
		if (rowIndex == 2)return vector<int>{1, 2, 1};
		vector<int>cur = getRow(rowIndex - 1);
		for (size_t i = 0; i < cur.size()-1; i++){
			result.push_back(cur[i] + cur[i + 1]);
		}
		result.push_back(1);
		return result;
    }
};