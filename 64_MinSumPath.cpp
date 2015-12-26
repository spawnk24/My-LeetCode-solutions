/*64. Minimum Path Sum My Submissions Question
Total Accepted: 58019 Total Submissions: 173386 Difficulty: Medium
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Subscribe to see which companies asked this question*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
		if (rows == 0)
			return 0;
		int cols = grid[0].size();
		if (cols == 0)
			return 0;
		vector<vector<int>> vminsum(rows, vector<int>(cols,0));
		
		vminsum[0][0] = grid[0][0];
		for (int i = 1 ; i < cols ; ++i)
			vminsum[0][i] = vminsum[0][i-1] + grid[0][i];
		for (int i = 1 ; i < rows ; ++i)
			vminsum[i][0] = vminsum[i-1][0] + grid[i][0];
		
		for (int i = 1 ; i < rows ; ++i){
			for (int j = 1 ; j < cols ; ++j){
				vminsum[i][j] = min(vminsum[i-1][j],vminsum[i][j-1]) + grid[i][j];
			}
		}
		
		return vminsum[rows-1][cols-1];
    }
};