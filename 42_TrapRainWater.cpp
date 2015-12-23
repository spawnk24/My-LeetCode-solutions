/*42. Trapping Rain Water My Submissions Question
Total Accepted: 55283 Total Submissions: 177978 Difficulty: Hard
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!*/

class Solution {
public:
    int trap(vector<int>& height) {
		int secHight = 0;
		int left = 0;
		int right = height.size()-1;
		int area = 0;
		while (left < right){
			if (height[left] < height[right]){
				secHight = max(height[left], secHight);
				area += secHight-height[left];
				left++;
			} else {
				secHight = max(height[right], secHight);
				area += secHight-height[right];
				right--;
			}
		}
		return area;
	}
};