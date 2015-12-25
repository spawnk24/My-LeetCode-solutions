/*53. Maximum Subarray My Submissions Question
Total Accepted: 89378 Total Submissions: 251748 Difficulty: Medium
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

click to show more practice.*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int sum=0;
		int max=0;
		for(int i=0 ; i<nums.size() ; ++i){
			sum += nums[i];
			if ( sum < 0 ){
				sum = 0;
			}
			else if ( sum > max ){
				max = sum;
			}
		}
		
		int maxneg;
		if (max == 0){
			for (int i=0 ; i<nums.size() ; ++i){
				if (i == 0 || nums[i] > maxneg)
					maxneg = nums[i];
			}
			max = maxneg;
		}
		return max;
    }
};