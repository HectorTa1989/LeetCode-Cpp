//https://leetcode.com/problems/permutations/
/*Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        generatePermutations(0, &nums, &results);
        return results;
    }
private:
    void generatePermutations(int i, vector<int>* nums_ptr, vector<vector<int>>* results) {
        auto& nums = *nums_ptr;
        if (i == nums.size() - 1) {
            results->emplace_back(nums);
            return;
        }
        
        for (int j = i; j < nums.size(); ++j) {
            std::swap(nums[i], nums[j]);
            generatePermutations(i + 1, nums_ptr, results);
            std::swap(nums[i], nums[j]);
        }
    }
};

//
vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> current;
        backtrack(res, nums, current);
        return res;
    }
    
    void backtrack(vector<vector<int>>& res, vector<int>& nums, vector<int>& current){
        if(current.size() == nums.size()){
            res.push_back(current);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(count(current.begin(), current.end(), nums[i]) == 0){
                current.push_back(nums[i]);
                backtrack(res, nums, current);
                current.pop_back();
            }
        }
    }
	
//Simple Recursion, No Swap
class Solution {
private:
    
    vector<vector<int>> ourResult;
    
public:
    
    void createPermutations(const vector<int>& nums, vector<int>& singleIteration)
    {
        if (singleIteration.size() == nums.size())
        {
            ourResult.push_back(singleIteration);
            return;
        }
        
        for (int i{}; i < nums.size(); ++i)
        {
		// Check if the number is already in the vector. If it is, we want o go to the next number ( we don't want duplicates)
            if (!singleIteration.empty() && find(singleIteration.begin(), singleIteration.end(), nums[i]) != singleIteration.end()) continue;
            singleIteration.push_back(nums[i]);
            createPermutations(nums, singleIteration);
            singleIteration.pop_back();
        }
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<int> singleIteration;
        singleIteration.reserve(nums.size());
        createPermutations(nums, singleIteration);
        return ourResult;
    }
};
	
	// For instance. We are at Position 0. Loop 1, Empty Vector: (depth = 0)
	// [1, .. , ..]
	// recurse into permuteTwo (depth = 1)
	// We are at Position 2. Loop 2, Vector with one element. Check if nums[i] is in vector. It is, so move into i = 2 (still in depth = 1).
	// Loop 2, Vector with one element. Check if nums[i+1] is in vector. It isn't so push it in.  Go one level deeper.
	//  We are at Position 3. Loop 3, Vector with two elements. Check if nums[i] is in vector.... (depth = 2)
    // ...
	// Pos = Nums.size(), this iteration is full, copy vector into results.
	// Unwind the stack back to depth = 1. Invoke pop_back continuously as you unwind until you are back at [1, .. , ..]
	// [1, 3, ..] 
	

//No Recursion! 8 Lines, STL
class Solution {
public:
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ourResult;
        vector<int> singleIter = nums;
		ourResult.push_back(singleIter);
        next_permutation(singleIter.begin(), singleIter.end());
        while (singleIter != nums)
        {
            ourResult.push_back(singleIter);
            next_permutation(singleIter.begin(), singleIter.end());
        }
        return ourResult;
    }
};