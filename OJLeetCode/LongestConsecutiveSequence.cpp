/*Given an unsorted array of integers, find the length of the longest consecutive elements sequence. 

For example,
 Given [100, 4, 200, 1, 3, 2],
 The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4. 

Your algorithm should run in O(n) complexity. 

*/
//Sort O(nlog(n)) --->AC
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if (num.size() < 1)return 0;
		sort(num.begin(), num.end());
		int result = 1, cur = 1;
		for (size_t i = 1; i < num.size(); i++)
		{
			if (num[i] == num[i - 1] + 1)
				cur++;
			else if (num[i] == num[i - 1])	//考虑相等的情况
				continue;
			else{
				result = max(result, cur);
				cur = 1;
			}
		}
		return result>cur ? result : cur;
    }
};
//unordered_map 
class Solution{
public:
	int longestConsecutive(vector<int> const&num){
		unordered_map<int,bool>used;
		for(auto&i:num)used[i]=false;
		int longest=0;
		for(auto i:num){
			if(used[i]) continue;
			int length=1;
			used[i]=true;
			for(int j=i+1;used.find(j)!=used.end();j++){
				used[j]=true;
				++length;
			}
			for(int j=i-1);used.find(j)!=used.end();j--){
				used[j]=true;
				++length;
			}
			longest=max(longest,length);
		}
		return longest;
	}
};