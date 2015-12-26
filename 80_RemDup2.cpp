/*80. Remove Duplicates from Sorted Array II My Submissions Question
Total Accepted: 60999 Total Submissions: 193841 Difficulty: Medium
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		int length = 0;
		int last;
		int count = 0;
		for (int i = 0 ; i < nums.size() ; ++i){
			if (i == 0 || nums[i] == last && count != 2){
				nums[length] = nums[i];
				length++;
				count++;
				last = nums[i];
			}
			else if (nums[i] == last){
				continue;
			}
			else{
				nums[length] = nums[i];
				length++;
				count = 1;
				last = nums[i];
			}
		}
		return length;
    }
};