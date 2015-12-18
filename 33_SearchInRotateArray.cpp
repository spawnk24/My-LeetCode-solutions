/*
Search in Rotated Sorted Array My Submissions Question
Total Accepted: 82405 Total Submissions: 281002 Difficulty: Hard
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Subscribe to see which companies asked this question*/

//return index in [begin, end]
int bsearch(vector<int>& nums, int begin, int end, int target){
    if (begin == end){
         return (nums[begin] == target) ? begin : -1;
    }
    else if ( begin < end ){
        int mid =  (begin + end) /2;
        if ( nums[mid] < target){
            begin = mid + 1;
            return bsearch(nums, begin, end, target);
        }
        else if ( nums[mid] > target){
            end = mid - 1;
            return bsearch(nums, begin, end, target);
        }
        else
            return mid;
    }
    else
        return -1;
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        for ( ; i < nums.size() - 1 ; ++i){
            if (nums[i+1] < nums[i])
                break;
        }
        if (target == nums[i]){
           return i;
        }
        else if (target < nums[i] && target >= nums[0]){
            return bsearch(nums, 0, i-1, target);
        }
        else{
            return bsearch(nums, i+1, nums.size()-1, target);
        }
        //return point
    }
};