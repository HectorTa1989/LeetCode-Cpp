/*Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Note:
The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.

Example 1:

Input: nums = [1, -1, 5, -2, 3], k = 3
Output: 4 
Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
Example 2:

Input: nums = [-2, -1, 2, 1], k = 1
Output: 2 
Explanation: The subarray [-1, 2] sums to 1 and is the longest.*/
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int sum = 0, res = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum == k) res = i + 1;
            else if (m.count(sum - k)) res = max(res, i - m[sum - k]);
            if (!m.count(sum)) m[sum] = i;
        }
        return res;
    }
};

//We found that the first and second numbers of the cumulative sum array are both 1
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        int res = 0;
        unordered_map<int, vector<int>> m;
        m[nums[0]].push_back(0);
        vector<int> sum = nums;
        for (int i = 1; i < nums.size(); ++i) {
            sum[i] += sum[i - 1];
            m[sum[i]].push_back(i);
        }
        for (auto it : m) {
            if (it.first == k) res = max(res, it.second.back() + 1);
            else if (m.find(it.first - k) != m.end()) {
                res = max(res, it.second.back() - m[it.first - k][0]);
            }
        }
        return res;
    }
};