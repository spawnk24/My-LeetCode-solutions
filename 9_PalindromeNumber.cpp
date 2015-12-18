/*Palindrome Number My Submissions Question
Total Accepted: 95562 Total Submissions: 318768 Difficulty: Easy
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Subscribe to see which companies asked this question*/
int reverse(int x) {
        if (x == INT_MIN)
            return 0;
        if (x < 0)
            return -reverse(-x);
        int rst = 0;
        
        while(x != 0){
            int next_rst = rst * 10 + x % 10;
            x = x / 10;
            if(next_rst/10 != rst) {
                rst  = 0;
                break;
            }
            rst = next_rst;
        }
        return rst;
}

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        return x == reverse(x);
    }
};