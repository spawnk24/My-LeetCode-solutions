/*41. First Missing Positive My Submissions Question
Total Accepted: 54497 Total Submissions: 234585 Difficulty: Hard
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

Subscribe to see which companies asked this question*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
		int i = 0;
		while (i < nums.size()){
			if (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != i+1 && nums[nums[i]-1] != nums[i])
				swap(nums[i],nums[nums[i]-1]);
			else
				++i;
		}
		for (i=0 ; i < nums.size() ; ++i){
			if (nums[i] != i+1)
				break;
		}
		return i+1;
    }
};