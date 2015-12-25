/*54. Spiral Matrix My Submissions Question
Total Accepted: 47480 Total Submissions: 220650 Difficulty: Medium
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        
        if(matrix.size() == 0)
			return vector<int>();
        int x1 = 0;
        int y1 = 0;
        int x2 = matrix.size()-1;
        int y2 = matrix[0].size()-1;
        vector<int> res;
        while(x1 <= x2 && y1 <= y2)
        {
            //up row
            for(int i = y1; i <= y2; ++i)
				res.push_back(matrix[x1][i]);
            //right column
            for(int i = x1+1; i <= x2; ++i)
				res.push_back(matrix[i][y2]);
            //bottom row
            if(x2 != x1)
				for(int i = y2-1; i >= y1; --i)
					res.push_back(matrix[x2][i]);
            //left column
            if(y1 != y2)
				for(int i = x2-1; i > x1; --i)
					res.push_back(matrix[i][y1]);
            
            x1++, y1++, x2--, y2--;
        }
        return res;
    }
};