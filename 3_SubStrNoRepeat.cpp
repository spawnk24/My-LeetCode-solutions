/*
Longest Substring Without Repeating Characters My Submissions Question
Total Accepted: 112810 Total Submissions: 538511 Difficulty: Medium
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        map<char,int> locs;
        
        int idx = -1, max = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (locs.find(s[i]) != locs.end())
            {
                idx = std::max(idx, locs[s[i]]);
            }

            if (i - idx > max)
            {
                max = i - idx;
            }

            locs[s[i]] = i;
        }
        return max;
    }
};