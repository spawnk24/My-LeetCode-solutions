/*35. Search Insert Position My Submissions Question
Total Accepted: 85427 Total Submissions: 235441 Difficulty: Medium
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 ¡ú 2
[1,3,5,6], 2 ¡ú 1
[1,3,5,6], 7 ¡ú 4
[1,3,5,6], 0 ¡ú 0*/
//[begin, end]
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

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return bSearch(nums, 0, nums.size() -1, target);
    }
};