/*Given an array S of n integers, are there elements a, b, c, and d in S such that 
a + b + c + d = target? Find all unique quadruplets in the array which gives t
he sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/
 //用map加个缓存。
class Solution{
public:
	vector<vector<int>>fourSum(vector<int>&sum, int target){
		if (sum.size() < 4)return vector<vector<int>>();
		sort(begin(sum), end(sum));
		//一个和对应多对
		map<int, vector<pair<int, int> > >cache;
		for (size_t a = 0; a < sum.size(); a++){
			for (size_t b = a + 1; a < sum.size(); b++){
				cache[sum[a] + sum[b]].push_back(pair<int, int>(a, b));
			}
		}

		set<vector<int>>result;//去重复
		for (size_t c = 2; c < sum.size(); c++){
			for (size_t d = c + 1; d < sum.size(); d++){
				const int key = target - sum[c] - sum[d];
				if (cache.find(key) != cache.end()){
					for (size_t k = 0; k < cache[key].size(); k++){
						if (c <= cache[key][k].second)
							continue;//有重叠
						result.insert(vector<int>{cache[key][k].first, 
							cache[key][k].second,sum[c], sum[d]});
					}
				}
			}
		}
		return vector<vector<int>>(result.begin(), result.end());
	}
};
 //Time Limit Exceeded
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>>result;
		if (num.size() < 4)
			return result;
		sort(num.begin(), num.end());
		for (auto i = num.begin(); i < prev(num.end(), 3); 
			i = upper_bound(i, prev(num.end(), 3), *i))
		{
			for (auto j = next(i); j < prev(num.end(), 2);
				j = upper_bound(j, prev(num.end(), 2), *j))
			{
				for (auto k = next(j); k < prev(num.end());
					k = upper_bound(k, prev(num.end()), *k))
				{
					int tmp = target - *i - *j - *k;
					if (binary_search(next(k), num.end(), tmp))
					{
				
						vector<int>cur={*i,*j,*b,*c};
						//要避免重复。
						if(find(result.begin(),result.end(),cur)==result.end())
						    result.push_back(cur);
					}
				}
			}
		}
		return result;
    }
};
//超时 TLE
class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		vector<vector<int>>result;
		if (num.size() < 4)
			return result;
		sort(num.begin(), num.end());
		for (auto i = num.begin(); i < prev(num.end(), 3); 
			i = upper_bound(i, prev(num.end(), 3), *i))
		{
			for (auto j = next(i); j < prev(num.end(), 2);
				j = upper_bound(j, prev(num.end(), 2), *j))
			{
				auto b = next(j);
				auto c = prev(num.end());
				while (b < c)
				{
					const int sum = *i + *j + *b + *c;
					 if (sum>target)
						c = prev(lower_bound(b, c, *c));
					 else if (sum<target)
						b = upper_bound(b, c, *b);
					 else{
						vector<int>cur={*i,*j,*b,*c};
						if(find(result.begin(),result.end(),cur)==result.end())
						    result.push_back(cur);
						 b++;
					 }
				}
			}
		}
		return result;
	}
};

//最后两个数字， twosum            AC
class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		vector<vector<int>>result;
		if (num.size() < 4)
			return result;
		sort(num.begin(), num.end());
		for (auto i = num.begin(); i < prev(num.end(), 3); 
			i = upper_bound(i, prev(num.end(), 3), *i))
		{
			for (auto j = next(i); j < prev(num.end(), 2);
				j = upper_bound(j, prev(num.end(), 2), *j))
			{
			int twosum = target - *i - *j;
				auto b = next(j);
				auto c = prev(num.end());
				while (b < c)
				{
					int sum = *b + *c;
					if (sum>twosum)
						c--;
					else if (sum<twosum)
						b++;
					else{
					    vector<int>cur={*i,*j,*b,*c};
						if(find(result.begin(),result.end(),cur)==result.end())
						    result.push_back(cur);
						b++;c--;
					}
				}
			}
		}
		return result;
	}
};