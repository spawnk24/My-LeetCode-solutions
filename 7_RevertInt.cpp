/*Reverse Integer My Submissions Question
Total Accepted: 112031 Total Submissions: 477701 Difficulty: Easy
Reverse digits of an integer.
Example1: x = 123, return 321
Example2: x = -123, return -321*/

class Solution {
public:
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
};