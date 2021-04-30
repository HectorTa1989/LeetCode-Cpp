/*Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:

Input:nums = [1,1,1], k = 2
Output: 2*/

//Cumulative Sum: Time O(n^2), Space O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        vector<int> sums = nums;
        for (int i = 1; i < n; ++i) {
            sums[i] = sums[i - 1] + nums[i];
        }
        for (int i = 0; i < n; ++i) {
            if (sums[i] == k) ++res;
            for (int j = i - 1; j >= 0; --j) {
                if (sums[i] - sums[j] == k) ++res;
            }
        }
        return res;
    }
};
//Without Space: Time O(n^2), Space O(1)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            int sum = nums[i];
            if (sum == k) ++res;
            for (int j = i + 1; j < n; ++j) {
                sum += nums[j];
                if (sum == k) ++res;
            }
        }
        return res;
    }
};
//Hashmap
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, sum = 0, n = nums.size();
        unordered_map<int, int> m{{0, 1}};
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            res += m[sum - k];
            ++m[sum]; 
        }
        return res;
    }
};