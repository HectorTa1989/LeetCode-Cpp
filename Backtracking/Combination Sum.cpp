/*Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]*/

//Sol 1
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target, int fm = 0) {
        if (target == 0){
            return {{}};
        }
        vector<vector<int>> res;
        for (int i = fm; i < candidates.size(); i++){
            if (target < candidates[i])
                continue;

            for (vector<int> &b : combinationSum(candidates, target - candidates[i], i)){
                b.push_back(candidates[i]);
                res.push_back(b);
            }

        }
        return res;
    }
};

//Sol 2: DP
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    int size = candidates.size();
    if (size == 0) return result;
    sort(candidates.begin(), candidates.end());
    vector<vector<vector<int>>> dp(target + 1, vector<vector<int>>());
    dp[0].push_back(vector<int>());
    
    for (int i = 1; i <= target; ++i) {
        for (int j = 0; j < size && candidates[j] <= i; ++j) {
            for (int k = 0; k < dp[i - candidates[j]].size(); ++k) {
                vector<int> temp = dp[i - candidates[j]][k];
                if (temp.size() && (temp[temp.size() - 1] > candidates[j])) continue;
                temp.push_back(candidates[j]);
                dp[i].push_back(temp);
            }
        }
    }
    return dp[target];
}

//Sol 3: backtracking
//There are just 2 cases:
a) Include the element
b) Exclude the element

Trick is that, if you are including the element, you can include it again.

combinationSumUtil(candidates, target-candidates[size-1], size); //Include the element but do not decrement the index(i.e variable "size") because we can include it again.
result.pop_back(); // We have to start new recursion branch in next step, so backtrack and remove previous result.
combinationSumUtil(candidates, target, size-1); // Exclude the element. Of course, when you are excluding, you have to decrement index(i.e variable "size").

class Solution {
    vector<vector<int>> finalResult;
    vector<int> result;
public:
    void combinationSumUtil(const vector<int>& candidates, int target, int size)
    {
        if(target == 0)
        {
            finalResult.push_back(result);
            return;
        }
        if(target<0) return;
        if(size<=0 && target>=1) return;
        result.push_back(candidates[size-1]);
        combinationSumUtil(candidates, target-candidates[size-1], size);
        result.pop_back();
        combinationSumUtil(candidates, target, size-1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        combinationSumUtil(candidates,target,candidates.size());
        return finalResult;
    }
};