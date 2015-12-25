/*56. Merge Intervals My Submissions Question
Total Accepted: 53859 Total Submissions: 226134 Difficulty: Hard
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
 
class Solution {
public:
    static bool cmp(const Interval& lhs,const Interval& rhs){
        return lhs.start < rhs.start;
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        int count = intervals.size();
        if(count <= 1){
            return intervals;
        }
		
		vector<Interval> result;

        sort(intervals.begin(), intervals.end(), cmp);

        result.push_back(intervals[0]);

        for(int i = 1;i < count;i++){
            Interval preIn = result.back();
            Interval curIn = intervals[i];
            // [1,3] [2,4]
            if(curIn.start <= preIn.end && curIn.end > preIn.end){
                   preIn.end = curIn.end;
                   result.pop_back();
                   result.push_back(preIn);
            }
            // [1,2] [3,4]
            else if(curIn.start > preIn.end){
                result.push_back(curIn);
            }
            // [1,4] [2,3] do nothing
        }
        return result;
    }
};