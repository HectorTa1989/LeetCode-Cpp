/*Given an array of integers nums, write a method that returns the "pivot" index of this array.

We define the pivot index as the index where the sum of the numbers to the left of the index is equal to the sum of the numbers to the right of the index.

If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index.

Example 1:

Input: 
nums = [1, 7, 3, 6, 5, 6]
Output: 3
Explanation: 
The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the sum of numbers to the right of index 3.
Also, 3 is the first index where this occurs.*/

//Prefix sum
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0, leftSum=0, i;
        for(int x:nums)
            sum += x;
        for(i=0; i<nums.size(); i++)
        {
            if(leftSum == sum - nums[i] - leftSum)
                return i;
            leftSum += nums[i];
        }
        return -1;
    }
};
// another prefix sum
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0;
        for(int x: nums) right += x;
        for(int i = 0; i < n; left += nums[i], right -= nums[i], i++) 
            if(left == right - nums[i]) return i;
        return -1;
    }
};
//
int pivotIndex(vector<int>& nums) {
	for (int i = 0, left = 0, right = accumulate(begin(nums), end(nums), 0); i < nums.size(); left += nums[i++])
		if (left == (right -= nums[i])) return i;
	return -1;
}
//// Recursive, O(n), O(n)
class Solution { 
public:
int pivotIndex(vector& nums,int i, int leftSum, int totalSum){
if(i>=nums.size()) return -1;

if(leftSum==(totalSum-leftSum-nums[i])) return i;
return pivotIndex(nums,i+1,leftSum+nums[i],totalSum);
}
int pivotIndex(vector& nums) {
if(nums.size()==0) return -1;
if(nums.size()==1) return 0;

int totalSum(0);
for(int x: nums) totalSum+=x;

return pivotIndex(nums,0,0,totalSum);
}
};
//
class Solution { // Dynamic Programming, O(n), O(n)
public:
int pivotIndex(vector& nums) {
if(nums.size()==0) return -1;
if(nums.size()==1) return 0;

vector<int> dp(nums.size());
dp[0]=nums.at(0);
for(int i(1);i<nums.size();i++) dp[i]=nums.at(i)+dp[i-1];

for(int i(0);i<nums.size();i++){
    if((dp[i]-nums.at(i))==dp[nums.size()-1]-dp[i])
        return i;
}
return -1;
}
};