/*78. Subsets My Submissions Question
Total Accepted: 76209 Total Submissions: 257010 Difficulty: Medium
Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]*/

class Solution {
public:
	void plusOneInBinary(vector<int>& digits, bool& bfin) {
		if ( digits.size() == 0 )
			return;
		int carry = 0;
		vector<int> res;
        for (int i = digits.size() - 1  ; i >= 0 ; --i){
			if (i == digits.size() - 1) {
				int tmp = digits[i];
				digits[i] = (tmp + 1) % 2;
				carry = (tmp + 1) / 2;
			}
			else {
				int tmp = digits[i];
				digits[i] = (tmp + carry) % 2;
				carry = (tmp + carry) / 2;
			}
		}
	
		if (carry == 1){
			bfin = true;
		}
		
		return;
    }
	
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size() == 0)
			return vector<vector<int>>();
		
		vector<vector<int>> res;
		vector<int> mark(nums.size(), 0);
		sort(nums.begin(), nums.end());
		bool bfin = false;
		
		while (bfin == false) {
			vector<int> tmp;
			for (int i = 0 ; i < mark.size() ; ++i){
				if (mark[i])
					tmp.push_back(nums[i]);
			}
			res.push_back(tmp);
			plusOneInBinary(mark, bfin);
		}
		
		return res;
	}
};