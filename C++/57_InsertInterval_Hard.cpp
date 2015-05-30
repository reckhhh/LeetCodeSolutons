/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10]. 

Tags: Array, Sort
*/
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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result;
        for(int i = 0; i < intervals.size(); ++i) {
            if(newInterval.start > intervals[i].end)
                result.push_back(intervals[i]);
            else if(newInterval.end < intervals[i].start) {
                result.push_back(newInterval);
                newInterval = intervals[i]; 
            }
            else {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end   = max(newInterval.end  , intervals[i].end);
            }
        }
        result.push_back(newInterval);
        return result;
    }
};
