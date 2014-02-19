/*Given a matrix of m x n elements (m rows, n columns), 
return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/
//考虑不是正方形的特殊情况。{{2,3,4}}  && {{2},{3},{4}}
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		if (matrix.size() == 0)
			return vector<int>();
		vector<int>result;
		int m = matrix.size() - 1;
		int n = matrix[0].size() - 1;
		//注意m,n的范围
		spiral(matrix, result, 0, 0, m, n);
		return result;
	}
private:
	void spiral(vector<vector<int>>&matrix, vector<int>&result,int a, int b, int m, int n)
	{
		if (a > m || b > n)
			return;
		if (a == m){
			for (int i = b; i <= n; i++)
				result.push_back(matrix[a][i]);
			return;
		}
		if (b == n){
			for (int j = a; j <= m; j++)
				result.push_back(matrix[j][n]);
			return;
		}
		for (int i = b; i <= n; i++)
			result.push_back(matrix[a][i]);
		for (int j = a + 1; j <= m; j++)
			result.push_back(matrix[j][n]);
		for (int p = n - 1; p >= b; p--)
			result.push_back(matrix[m][p]);
		for (int q = m - 1; q >= a + 1; q--)
			result.push_back(matrix[q][b]);
		spiral(matrix, result, a + 1, b + 1, m - 1, n - 1);
	}
};

//
class Solution{
public:
	vector<int> spiralOrder(vector<vector<int>>&matrix){
		vector<int>result;
		if(matrix.empty())return result;
		int beginX = 0,endX = matrix[0].size()-1;
		int beginY = 0,endY = matrix.size()-1;
		while(true){
			//From left to right
			for(int j = beginX;j <= endX,j++){
				result.push_back(matrix[beginY][j]);
			if(++beginY>endY)
				break;
			}
			//From top to bottom
			for (int i = beginY; i <= endY; ++i){ 
				result.push_back(matrix[i][endX]);
			if (beginX > --endX) 
				break;
		    }
			// From right to left
			for (int j = endX; j >= beginX; --j){
				result.push_back(matrix[endY][j]);
			if (beginY > --endY) 
				break;
			}
			// From bottom to top
			for (int i = endY; i >= beginY; --i){
				result.push_back(matrix[i][beginX]);
			if (++beginX > endX) 
				break;
			}
		}
		return result;
	}
};
