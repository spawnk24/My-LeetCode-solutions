/*Remove Duplicates from Sorted Array My Submissions Question
Total Accepted: 99264 Total Submissions: 309965 Difficulty: Easy
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = 0;
        int lastvalue;
        for ( int i = 0 ; i < nums.size() ; ++i ){
            if (i!= 0 && nums[i] == lastvalue){
                nums.erase(nums.begin()+i);
                i--;
                continue;
            }
            else{
                lastvalue = nums[i];
                length++;
                continue;
            }
        }
        return length;
    }
};