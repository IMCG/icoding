/*You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
 Could you do this in-place?

*/
 class Solution {
  public:
    void rotate(vector<vector<int> > &matrix) {
        int m = matrix.size();
		int n = matrix[0].size();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m / 2; j++)
				swap(matrix[j][i], matrix[m - j - 1][i]);
		for (int i = 0; i < m; i++)
			for (int j = i + 1; j < n; j++)
				swap(matrix[i][j], matrix[j][i]);
    }
};