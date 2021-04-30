/*Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true

Example 2:
Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false*/

//Compare with the previous version, the difference is duplicates are allowed.
//nums[left] <= nums[mid] could not be used as the condition to claim the ascending in this range.
//We should break the previous condition into two conditions: nums[left] == nums[mid] and nums[left] < nums[mid].
//If nums[left] < nums[mid], we can still claim the ascending trend.
//Otherwise, left++ to see the next step.

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            if(nums[mid] == target)
                return true;
            
            if(nums[left] < nums[mid])
            {
                if(nums[left] <= target && target < nums[mid])
                    right = mid-1;
                else
                    left = mid+1;
            }
            else
            {
                if(nums[left] > nums[mid])
                {
                    if(nums[mid] < target && target <= nums[right])
                        left = mid+1;
                    else
                        right = mid-1;
                }
                else
                    left++;
            }
        }
        return false;
    }
};