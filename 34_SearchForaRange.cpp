/*34. Search for a Range My Submissions Question
Total Accepted: 67118 Total Submissions: 239215 Difficulty: Medium
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].*/
//[begin, end]
const int CINT_FINDSMALL    = 0;
const int CINT_FINDBIG      = 1;

int findmargin(vector<int>& nums, int begin, int end, int target, int type){
        if (begin > end || (begin == end && nums[begin] != target))
            return -1;
        int mid = (begin + end) / 2;
        if (begin == end && nums[begin] == target){
            return begin;
        }
        else if (nums[mid] == target){
            if ((type == CINT_FINDSMALL && mid == begin)
            || (type == CINT_FINDBIG && mid == end))
                return mid;
            else
            {
                int x;
                if (type == CINT_FINDSMALL)
                    x = findmargin(nums, begin, mid - 1, target, type);
                else
                    x = findmargin(nums, mid + 1, end, target, type);
                if (x == -1)
                    return mid;
                else
                    return x;
            }
        }
        else if (nums[mid] < target){
            if (mid == end)
                return -1;
            else
                return findmargin(nums, mid+1, end, target, type);
        }
        else{
            if (mid == begin)
                return -1;
            else
                return findmargin(nums, begin, mid-1, target, type);
        }
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
		small = findmargin(nums, 0, nums.size() - 1, target, CINT_FINDSMALL);
		big = findmargin(nums, 0, nums.size() - 1, target, CINT_FINDBIG);
		res.push_back(small);
		res.push_back(big);
        return res;
    }
};