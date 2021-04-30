/*Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].*/

//https://www.cnblogs.com/grandyang/p/4367569.html
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size(), cur = 0;
        while (cur < n && intervals[cur][1] < newInterval[0]) {
            res.push_back(intervals[cur++]);
        }
        while (cur < n && intervals[cur][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[cur][0]);
            newInterval[1] = max(newInterval[1], intervals[cur][1]);
            ++cur;
        }
        res.push_back(newInterval);
        while (cur < n) {
            res.push_back(intervals[cur++]);
        }
        return res;
    }
};
//
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size(), cur = 0;
        for (int i = 0; i < n; ++i) {
            if (intervals[i][1] < newInterval[0]) {
                res.push_back(intervals[i]);
                ++cur;
            } else if (intervals[i][0] > newInterval[1]) {
                res.push_back(intervals[i]);
            } else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        res.insert(res.begin() + cur, newInterval);
        return res;
    }
};
//
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size(), cur = 0, i = 0;
        while (i < n) {
            if (intervals[i][1] < newInterval[0]) {
                res.push_back(intervals[i]);
                ++cur;
            } else if (intervals[i][0] > newInterval[1]) {
                res.push_back(intervals[i]);
            } else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
            ++i;
        }
        res.insert(res.begin() + cur, newInterval);
        return res;
    }
};

//http://bangbingsyb.blogspot.com/2014/11/leetcode-insert-interval.html
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> ret;
        bool isInsert = false;
        for(int i=0; i<intervals.size(); i++) {
            // already insert newInterval
            if(isInsert) {  
                ret.push_back(intervals[i]);
                continue;
            }
            
            // insert newInterval before current interval
            if(newInterval.end < intervals[i].start) {  
                ret.push_back(newInterval);
                ret.push_back(intervals[i]);
                isInsert = true;
                continue;
            }
            
            // combine newInterval with current interval
            if(newInterval.start<=intervals[i].end && intervals[i].start<=newInterval.end) {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
                continue;
            }
            
            // newInterval after current interval
            ret.push_back(intervals[i]);
        }
        
        if(!isInsert) ret.push_back(newInterval);
        return ret;
    }
};