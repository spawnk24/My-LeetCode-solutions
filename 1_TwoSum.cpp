/*Two Sum
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int, int> numhash;
        for (int i = 0 ; i < nums.size() ; ++i)
            numhash[nums[i]] = i;
        for (int i = 0 ; i < nums.size() ; ++i){
            map<int, int>::iterator it = numhash.find(target - nums[i]);
                if (it != numhash.end() && it->second != i){
                    int index1 = i < it->second ? i : it->second;
                    int index2 = i + it->second - index1;
                    res.push_back(index1+1);
                    res.push_back(index2+1);
                    return res;
                }
            }
        return res;
        }
};