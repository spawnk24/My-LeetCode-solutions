/*75. Sort Colors My Submissions Question
Total Accepted: 79825 Total Submissions: 237669 Difficulty: Medium
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int colors[3] = {0};
		for (int i = 0 ; i < nums.size() ; ++i)
			colors[nums[i]]++;
		int index = 0;
		for (int i = 0 ; i < 3 ; ++i){
			while (colors[i] > 0){
				nums[index++] = i;
				colors[i]--;
			}
		}
		return;
    }
};