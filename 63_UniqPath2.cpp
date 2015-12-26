/*63. Unique Paths II My Submissions Question
Total Accepted: 53813 Total Submissions: 188068 Difficulty: Medium
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
		if (rows == 0)
			return 0;
		int cols = obstacleGrid[0].size();
		if (cols == 0)
			return 0;
		
		bool bcol = false;
		bool brow = false;
		vector<vector<int>> vcount(rows, vector<int>(cols));
		for (int i = 0 ; i < cols ; ++i){
			if (bcol || obstacleGrid[0][i] == 1){
				vcount[0][i] = 0;
				bcol = true;
			}
			else
				vcount[0][i] = 1;
		}
		for (int i = 0 ; i < rows ; ++i)
			if (brow || obstacleGrid[i][0] == 1){
				vcount[i][0] = 0;
				brow = true;
			}
			else
				vcount[i][0] = 1;
		
		for (int i = 1 ; i < rows ; ++i){
			for (int j = 1 ; j < cols ; ++j){
				if (obstacleGrid[i][j] == 1)
					vcount[i][j] = 0;
				else
					vcount[i][j] = vcount[i-1][j] + vcount[i][j-1];
			}
		}
		return vcount[rows-1][cols-1];
    }
};