/*Your are given an array of positive integers nums.

Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.

Example 1:
Input: nums = [10, 5, 2, 6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1 || nums.size() == 0) return 0;
        
        int left=0, right=0, product = 1, n = nums.size();
        int res=0;
        for(right = 0; right<n; right++)
        {
            product *= nums[right];
            while(left < n && product >= k)	// Make sure left never passes right.
            {
                product /= nums[left++];
            }
            res += right - left + 1;	// Captures numbers within the range that otherwise would have been left out. For instance in 10, 5, 2, 6, two would
        }							// never have been counted individually.
        return res;
    }
};
/* A longer, more tricker, accepted answer. The reason in the comment. */
    // 15 lines, without comment.
    int longer(vector<int>& nums, int k) {
        if (k == 0) return 0;
        
        int left = 0, right = 0, subProduct = 1, count = 0;
        while(right < nums.size()) {
            subProduct *= nums[right];
            while(subProduct >= k && left <= right) {
                /*
                Whenever 'left' is incremented, add the number
                of subarrays starting at 'left':
                [left, left], [left, left+1], ..., [left, right].
                */
                count += subProduct >= k ? (right - left) : (right - left + 1);
                subProduct /= nums[left++];
            }
            ++right;
        }
		 /*
        Because we are counting subarray starting at index left, if
        left < right = nums.size(), we have not count all subarrays yet.
        Count remaining subarrays.
        */
        while(left < right) { 
            // Cannot use count += (right-left)*(right-left + 1)/2. Overflow.
            count += (right - left);
            ++left;
        }
        
        return count;
    }