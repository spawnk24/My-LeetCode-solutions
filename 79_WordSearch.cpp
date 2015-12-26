/*79. Word Search My Submissions Question
Total Accepted: 59634 Total Submissions: 275302 Difficulty: Medium
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.*/

class Solution {
public:
bool dfs(vector<vector<char> >& board, string target, int index, int x, int y, vector<pair<int,int> >& vused) {
	vused.push_back(pair<int,int>(x,y));
	if (index == target.length() - 1 && target[index] == board[x][y])
		return true;
	else if (target[index] != board[x][y]){
		vused.pop_back();
		return false;
	}

	vector<pair<int,int> > vbefore(vused);

	if (x - 1 >= 0 && find(vused.begin(), vused.end(), pair<int,int>(x-1, y)) == vused.end()){
		if (dfs(board, target, index+1, x-1, y, vused))
			return true;
		vused = vbefore;
	}

	if (x + 1 < board.size() && find(vused.begin(), vused.end(), pair<int,int>(x+1, y)) == vused.end()){
		if (dfs(board, target, index+1, x+1, y, vused))
			return true;
		vused = vbefore;
	}

	if (y - 1 >= 0 && find(vused.begin(), vused.end(), pair<int,int>(x, y-1)) == vused.end()){
		if (dfs(board, target, index+1, x, y-1, vused))
			return true;
		vused = vbefore;
	}

	if (y + 1 < board[0].size() && find(vused.begin(), vused.end(), pair<int,int>(x, y+1)) == vused.end()){
		if (dfs(board, target, index+1, x, y+1, vused))
			return true;
		vused = vbefore;
	}
	return false;
}

bool exist(vector<vector<char> >& board, string word) {
	int rows = board.size();
	if (rows == 0)
		return false;
	int cols = board[0].size();
	if (cols == 0)
		return false;
	vector<pair<int,int> > vused;
	for (int i = 0 ; i < rows ; ++i)
		for (int j = 0 ; j < cols ; ++j){
			vused.clear();
			if (dfs(board, word, 0, i, j, vused))
				return true;
		}
	return false;
}
};