/*66. Plus One My Submissions Question
Total Accepted: 77967 Total Submissions: 244501 Difficulty: Easy
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

Subscribe to see which companies asked this question*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
		if (digits.size() == 0)
			return vector<int>();
		int carry = 0;
		vector<int> res;
		int num;
        for (int i = digits.size() - 1  ; i >= 0 ; --i){
			if (i == digits.size() - 1){
				num = (digits[i] + 1) % 10;
				carry = (digits[i] + 1) / 10;
			}
			else{
				num = (digits[i] + carry) % 10;
				carry = (digits[i] + carry) / 10;
			}
			res.insert(res.begin(),num);
		}
		if (carry == 1)
			res.insert(res.begin(),1);
		
		return res;
    }
};