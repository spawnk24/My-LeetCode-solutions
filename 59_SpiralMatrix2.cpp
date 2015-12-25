/*59. Spiral Matrix II My Submissions Question
Total Accepted: 43562 Total Submissions: 130844 Difficulty: Medium
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[[ 1, 2, 3 ],[ 8, 9, 4 ],[ 7, 6, 5 ]]*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res;
		if(n == 0)
			return res;
		
		for (int i = 0 ; i < abs(n) ; ++i){
			vector<int> tmp(abs(n),0);
			res.push_back(tmp);
		}

		
		int x1 = 0;
        int y1 = 0;
        int x2 = abs(n)-1;
        int y2 = abs(n)-1;
		int count = 1;
        while(x1 <= x2 && y1 <= y2)
        {
            //up row
            for(int i = y1; i <= y2; ++i)
				res[x1][i] = count++;
            //right column
            for(int i = x1+1; i <= x2; ++i)
				res[i][y2] = count++;
            //bottom row
            if(x2 != x1)
				for(int i = y2-1; i >= y1; --i)
					res[x2][i] = count++;
            //left column
            if(y1 != y2)
				for(int i = x2-1; i > x1; --i)
					res[i][y1] = count++;
            x1++, y1++, x2--, y2--;
        }
        return res;
    }
};