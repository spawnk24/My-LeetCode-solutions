/*4Sum My Submissions Question
Total Accepted: 56532 Total Submissions: 250766 Difficulty: Medium
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ¡Ü b ¡Ü c ¡Ü d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)*/

vector<vector<int>> threeSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        std::sort(nums.begin(),nums.end());
        int i = 0;
        for (int i = 0 ; i < nums.size() ; ++i){
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            int j = i+1;
            int k = nums.size() - 1;
            while (j < k){
                if ( j > i+1 && nums[j] == nums[j-1])
                {
                    j++;
                    continue;
                }
                if (k < nums.size() - 1 && nums[k] == nums[k+1])
                {
                    k--;
                    continue;
                }
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < target)
                {
                    j++;
                    continue;
                }
                else if (sum > target)
                {
                    k--;
                }
                else
                {
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[k]);
                    res.push_back(tmp);
                    j++;
                }
            }
        }
        return res;
}

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4)
            return res;
        sort(nums.begin(), nums.end());
        int i = 0;
        for ( ; i <= nums.size() - 4 ; ++i){
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            vector<int> newnums(nums.size() - i - 1);
            copy(nums.begin()+i+1, nums.end(), newnums.begin());
            vector<vector<int>> tmpres = threeSum(newnums, target-nums[i]);
            for ( int k = 0 ; k < tmpres.size() ; ++k){
                tmpres[k].insert(tmpres[k].begin(),nums[i]);
                res.push_back(tmpres[k]);
            }
        }
        return res;
    }
};