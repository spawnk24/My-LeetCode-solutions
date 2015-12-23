/*48. Rotate Image My Submissions Question
Total Accepted: 54995 Total Submissions: 165496 Difficulty: Medium
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
		vector<vector<int>> tmp = matrix;
		int n = matrix.size();
		for (int i = 0 ; i < n ; ++i)
			for(int j = 0 ; j < n ; ++j)
				tmp[i][j] = matrix[n-j-1][i];
		for (int i = 0 ; i < n ; ++i)
			for(int j = 0 ; j < n ; ++j)
			matrix[i][j] = tmp[i][j];
    }
};