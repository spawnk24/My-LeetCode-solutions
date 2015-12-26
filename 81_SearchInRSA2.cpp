/*81. Search in Rotated Sorted Array II My Submissions Question
Total Accepted: 52422 Total Submissions: 166855 Difficulty: Medium
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.*/

class Solution {
public:
	int bsearch(vector<int>& nums, int begin, int end, int target){
		if (begin > end)
			return -1;
		else if (begin == end){
			return (nums[begin] == target) ? begin : -1;
		}
		else if ( begin < end ){
			int mid =  (begin + end) /2;
			if ( nums[mid] < target ){
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
	}

    bool search(vector<int>& nums, int target) {
		
		int count = 0;
		for (int i = 0 ; i < nums.size() ; ++i){
			if (i == 0)
				count++;
			else{
				if (nums[i] != nums[i-1]){
					nums[count]=nums[i];
					count++;
				}
			}
		}
		
        int i = 0;
        for ( ; i+1 < count ; ++i){
            if (nums[i+1] < nums[i])
                break;
        }
        if (target == nums[i]){
           return true;
        }
        else if (target < nums[i] && target >= nums[0]){
            int x = bsearch(nums, 0, i-1, target);
			if (x >= 0 && x <= i-1)
				return true;
			else
				return false;
        }
        else{
            int x = bsearch(nums, i+1, count-1, target);
			if (x >= i+1 && x <= count-1)
				return true;
			else
				return false;
        }
		return false;
    }
};