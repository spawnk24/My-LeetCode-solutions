/*73. Set Matrix Zeroes My Submissions Question
Total Accepted: 54467 Total Submissions: 168019 Difficulty: Medium
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
		if (rows == 0)
			return;
		int cols = matrix[0].size();
		if (cols == 0)
			return;
		
		vector<int> markedrows(rows, 0);
		vector<int> markedcols(cols, 0);
		for (int i = 0 ; i < rows ; ++i){
			for (int j = 0 ; j < cols ; ++j){
				if (matrix[i][j] == 0){
					markedrows[i] = 1;
					markedcols[j] = 1;
				}
			}
		}
		
		for (int i = 0 ; i < rows ; ++i){
			for (int j = 0 ; j < cols ; ++j){
				if (markedrows[i] || markedcols[j])
					matrix[i][j] = 0;
			}
		}
		return ;
    }
};