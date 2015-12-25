/*57. Insert Interval My Submissions Question
Total Accepted: 48517 Total Submissions: 213891 Difficulty: Hard
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> res;
		bool bInsert = false;
		for (int i = 0 ; i < intervals.size() ; ++i){
			//[1,2];[6,8]
			//[1,4];[2,3],[1,4]
			//[10,14];[5,8]
			if (newInterval.start > intervals[i].end
			|| newInterval.start >= intervals[i].start && newInterval.end <= intervals[i].end
			|| newInterval.end < intervals[i].start){
				if (newInterval.start >= intervals[i].start && newInterval.end <= intervals[i].end)
					bInsert = true;
				else if (!bInsert && newInterval.end < intervals[i].start){
					bInsert = true;
					res.push_back(newInterval);
				}
				res.push_back(intervals[i]);
				continue;
			}
			//[4,9] overlaps with [3,5],[6,7],[8,10]
			else{
				newInterval.start = min(intervals[i].start,newInterval.start);
				newInterval.end = max(intervals[i].end,newInterval.end);
			}
		}
		if (!bInsert)
			res.push_back(newInterval);
		return res;
    }
};