/*3Sum Closest My Submissions Question
Total Accepted: 60531 Total Submissions: 217818 Difficulty: Medium
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        for (int i = 0 ; i < nums.size() ; ++i){
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            int j = i + 1;
            int k = nums.size() - 1;
            while ( j < k ){
                if ( j > i+1 && nums[j] == nums[j-1]){
                    j++;
                    continue;
                }
                if ( k < nums.size() - 1 && nums[k] == nums[k+1]){
                    k--;
                    continue;
                }
                int tmpres = nums[i] + nums[j] + nums[k];
                if (abs(tmpres - target) < abs(res - target))
                    res = tmpres;
                if (tmpres < target){
                    j++;
                    continue;
                }
                else if (tmpres > target){
                    k--;
                    continue;
                }
                else
                    return target;
            }
        }
        return res;
    }
};