/*39. Combination Sum My Submissions Question
Total Accepted: 72463 Total Submissions: 246930 Difficulty: Medium
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] */

class Solution 
{
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) 
    {
        vector<int> vecTmp;
 
        m_vecRet.clear();
        sort(candidates.begin(), candidates.end());
        combination(candidates, 0, vecTmp, target);
 
        return m_vecRet;
    }
 
private:
    void combination(const vector<int> &candidates, size_t idx, vector<int> &curr, int target)
    {
        if (target == 0)
        {
            m_vecRet.push_back(curr);
        }
        else
        {
            // i starts from idx to make sure results are distinct.
            for (size_t i = idx; i < candidates.size(); ++i)
            {
                if (target >= candidates[i])
                {
                    curr.push_back(candidates[i]);
                    combination(candidates, i, curr, target - candidates[i]);
                    curr.pop_back();
                }
            }
        }
    }
 
private:
    vector<vector<int> > m_vecRet;
};