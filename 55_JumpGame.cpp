/*55. Jump Game My Submissions Question
Total Accepted: 64474 Total Submissions: 234228 Difficulty: Medium
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
For example:
A = [2,3,1,1,4], return true.
A = [3,2,1,0,4], return false.*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
		if (nums.size() == 0)
            return false;
        int nowmax = 0, begin = 0;
		int end = nums[0];
        while ( end < nums.size() - 1 ) {
            int index = begin;
            for (; index <= end; index++) {
                nowmax = max(nowmax, index + nums[index]);
            }
			if (nowmax > end){
				begin = index;
				end = nowmax;				
			}
			else
				return false;
        }
		return true;
    }
};