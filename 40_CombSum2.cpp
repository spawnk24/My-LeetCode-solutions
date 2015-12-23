/*40. Combination Sum II My Submissions Question
Total Accepted: 55053 Total Submissions: 209055 Difficulty: Medium
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] */

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
		vector<int> curr;
		combination(candidates, 0, curr, target);
		return m_vres;
    }
private:
	void combination(vector<int>& candidates, int index, vector<int>& curr, int target){
		if (target < 0){
			return;
		}
		else if (target == 0){
			m_vres.push_back(curr);
		}
		else{
			for (int i = index ; i < candidates.size() ; ++i){
				curr.push_back(candidates[i]);
				combination(candidates, i + 1, curr, target - candidates[i]);
				curr.pop_back();
				while(i < candidates.size() - 1 && candidates[i] == candidates[i+1]){
					++i;
				}
			}
		}
		return;
	}

private:
	vector<vector<int>> m_vres;
};