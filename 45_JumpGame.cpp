/*45. Jump Game II My Submissions Question
Total Accepted: 54513 Total Submissions: 221157 Difficulty: Hard
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Subscribe to see which companies asked this question*/

class Solution {
public:
    int jump(vector<int>& nums) {
		if (nums.size() == 1)
            return 0;
        int nowmax = 0, count = 1, begin = 0, end = nums[0];
        while (end < nums.size() - 1) {
            count++;
            int index = begin;
            for (; index <= end; index++) {
                nowmax = max(nowmax, index + nums[index]);
            }
            begin = index;
            end = nowmax;
        }
        return count;
    }
};