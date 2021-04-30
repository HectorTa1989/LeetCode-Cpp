/*Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]*/

//To skip duplicates, sort nums.

//Recursive (Backtracking)
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subs;
        vector<int> sub;
        subsets(nums, 0, sub, subs);
        return subs;
    }
private:
    void subsets(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& subs) {
        subs.push_back(sub);
        for (int j = i; j < nums.size(); j++) {
            if (j == i || nums[j] != nums[j - 1]) {
                sub.push_back(nums[j]);
                subsets(nums, j + 1, sub, subs);
                sub.pop_back();
            }
        }
    }
};

//Iterative
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subs = {{}};
        for (int i = 0, n = 0; i < nums.size(); i++) {
            int j = !i || nums[i] != nums[i - 1] ? 0 : n;
            n = subs.size();
            for (; j < n; j++) {
                subs.push_back(subs[j]);
                subs.back().push_back(nums[i]);
            }
        }
        return subs;
    }
};