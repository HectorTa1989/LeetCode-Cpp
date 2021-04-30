/*Given m arrays, and each array is sorted in ascending order. Now you can pick up two integers from two different arrays (each array picks one) 
and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a-b|. Your task is to find the maximum distance.

Example 1:

Input: 
[[1,2,3],
 [4,5],
 [1,2,3]]
Output: 4
Explanation: 
One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.*/

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res = 0, start = arrays[0][0], end = arrays[0].back();
        for (int i = 1; i < arrays.size(); ++i) {
            res = max(res, max(abs(arrays[i].back() - start), abs(end - arrays[i][0])));
            start = min(start, arrays[i][0]);
            end = max(end, arrays[i].back());
        }
        return res;
    }
};

//
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        priority_queue<pair<int, int>> mx, mn;
        for (int i = 0; i < arrays.size(); ++i) {
            mn.push({-arrays[i][0], i});
            mx.push({arrays[i].back(), i});
        }
        auto a1 = mx.top(); mx.pop();
        auto b1 = mn.top(); mn.pop();
        if (a1.second != b1.second) return a1.first + b1.first;
        return max(a1.first + mn.top().first, mx.top().first + b1.first);
    }
};