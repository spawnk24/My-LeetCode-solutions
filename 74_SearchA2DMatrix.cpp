/*74. Search a 2D Matrix My Submissions Question
Total Accepted: 64636 Total Submissions: 197766 Difficulty: Medium
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,
Consider the following matrix
[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.*/

class Solution {
public:
	int bSearch(vector<int>& nums, int begin, int end, int target){
    while (begin <= end){
			int mid = (begin + end) / 2;
			if (nums[mid] == target){
				return mid;
			}
			else if (nums[mid] < target){
				if (mid == end)
					return end + 1;
				else
					begin = mid + 1;
			}
			else{
				if (mid == begin)
					return begin;
				else
					end = mid -1;
			}
		}
	}
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int rows = matrix.size();
		if (rows == 0)
			return false;
		int cols = matrix[0].size();
		if (cols == 0)
			return false;
		
		vector<int> vfirstcol;
		for (int i = 0 ; i < rows ; ++i)
			vfirstcol.push_back(matrix[i][0]);
		
		int index = bSearch(vfirstcol, 0, vfirstcol.size() - 1, target);
		if (vfirstcol[index] == target)
			return true;
		else if (index == 0)
			return false;
		else if (find(matrix[index - 1].begin(), matrix[index - 1].end(), target) != matrix[index - 1].end())
			return true;
		else
			return false;
    }
};