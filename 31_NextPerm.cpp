/*
Next Permutation My Submissions Question
Total Accepted: 53179 Total Submissions: 208402 Difficulty: Medium
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 ¡ú 1,3,2
3,2,1 ¡ú 1,2,3
1,1,5 ¡ú 1,5,1*/

void reverse(vector<int>& nums, int begin, int end){
    while (begin < end){
        int tmp = nums[begin];
        nums[begin] = nums[end];
        nums[end] = tmp;
        begin++;
        end--;
    }
}

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        for (; i >= 1 ; --i){
            if (nums[i] > nums[i-1])
            {
                break;
            }
        }
        if ( i == 0 )
            reverse(nums, 0 , nums.size()-1);
        else{
            int j = nums.size() -1;
            --i;
            for ( ; j>i ; --j){
                if (nums[j] > nums[i]){
                    int tmp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tmp;
                    break;
                }
            }
            reverse(nums, i+1, nums.size()-1);
        }
        return;
    }
};