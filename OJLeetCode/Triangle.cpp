/*Given a triangle, find the minimum path sum from top to bottom. Each step you
 may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, 
where n is the total number of rows in the triangle.
*/
//贪心算法，不合适。
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.size() == 0)return -1;
		int sum = triangle[0].at(0);
		for (size_t i = 1; i < triangle.size(); i++)
		{
			size_t j = 0;
			while (j < triangle[i].size())
			{
				if (triangle[i][j]<triangle[i][j + 1]){
					sum += triangle[i][j]; 
				}
				else{
					sum += triangle[i][j + 1];
					j++;
				}
				break;
			}
		}
		return sum;
    }
};
class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		if (triangle.size() == 0)return -1;
		vector<int>f(triangle.size(), -1);
		f[0] = triangle[0][0];
		int j = 0;
		for (size_t i = 1; i < triangle.size(); i++)
		{
			if (triangle[i][j] < triangle[i][j + 1])
				f[i] = f[i - 1] + triangle[i][j];
			else
				f[i] = f[i - 1] + triangle[i][j + 1];
		}
		return f[triangle.size() - 1];
	}
};
//DP  从底层开始算起。
class Solution {
public:
	int minimumTotal1(vector<vector<int> > &triangle) {
		for (int i = triangle.size() - 2; i >= 0; --i)
			for (int j = 0; j < i + 1; ++j)
				triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
		return triangle[0][0];
	}
	//不改变triangle
	int minimumTotal2(vector<vector<int>> &triangle) {
        int N = triangle.size();
        int *dp = new int[N];
        for (int i = 0; i < N; ++i)
            dp[i] = triangle[N-1][i];
        for (int i = N - 2; i >= 0; --i)
            for (int j = 0; j < i + 1; ++j)
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
        int res = dp[0];
        delete [] dp;
        return res;
    }	
};


