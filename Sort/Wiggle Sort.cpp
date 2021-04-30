//Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....
//Example:
//Input: nums = [3,5,2,1,6,4]
//Output: One possible answer is [3,5,1,6,2,4]*/

//https://www.cnblogs.com/grandyang/p/5177285.html
//O(nlogn)
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() <= 2) return;
        for (int i = 2; i < nums.size(); i += 2) {
            swap(nums[i], nums[i - 1]);
        }
    }
};
//O(n)
//When i is odd，nums[i] >= nums[i - 1]
//When i is even，nums[i] <= nums[i - 1]
//As long as each number is compared with its corresponding condition according to its parity, if it does not match, it can be exchanged with the previous number
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.size() <= 1) return;
        for (int i = 1; i < nums.size(); ++i) {
            if ((i % 2 == 1 && nums[i] < nums[i - 1]) || (i % 2 == 0 && nums[i] > nums[i - 1])) {
                swap(nums[i], nums[i - 1]);
            }
        }
    }
};