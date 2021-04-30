/*Given a collection of intervals, merge all overlapping intervals.
For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:
Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/

//https://www.cnblogs.com/grandyang/p/4370601.html
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res{intervals[0]};
        for (int i = 1; i < intervals.size(); ++i) {
            if (res.back()[1] < intervals[i][0]) {
                res.push_back(intervals[i]);
            } else {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }   
        return res;
    }
};
//2 pointers
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> res;
        vector<int> starts, ends;
        for (int i = 0; i < n; ++i) {
            starts.push_back(intervals[i][0]);
            ends.push_back(intervals[i][1]);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        for (int i = 0, j = 0; i < n; ++i) {
            if (i == n - 1 || starts[i + 1] > ends[i]) {
                res.push_back({starts[j], ends[i]});
                j = i + 1;
            }
        } 
        return res;
    }
};


//https://zxi.mytechroad.com/blog/geometry/leetcode-56-merge-intervals/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        
        std::sort(intervals.begin(), intervals.end(), 
                  [](const vector<int>& a, const vector<int>& b){
                        return a[0] < b[0];
                    });
        
        vector<vector<int>> ans;        
        for (const auto& interval : intervals) {
            if (ans.empty() || interval[0] > ans.back()[1]) {
                ans.push_back(interval);
            } else {
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }
        
        return ans;
    }
};