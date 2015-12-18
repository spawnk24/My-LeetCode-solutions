/*Remove Element My Submissions Question
Total Accepted: 90608 Total Submissions: 279375 Difficulty: Easy
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int begin = 0;
        int end = nums.size() - 1;
        int length = nums.size();
        while (begin <= end){
            if (nums[end] == val){
                end--;
                length--;
                continue;
            }
            if (nums[begin] == val){
                nums[begin] = nums[end];
                nums[end] = val;
                begin++;
                continue;
            }
            begin++;
        }
        return length;
    }
};