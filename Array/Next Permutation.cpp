//Method 1: According to Wikipedia, a man named Narayana Pandita presented the following simple algorithm to solve this problem in the 14th century.
/*
Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just reverse nums and done.
Find the largest index l > k such that nums[k] < nums[l].
Swap nums[k] and nums[l].
Reverse the sub-array nums[k + 1:].*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	int n = nums.size(), k, l;
    	for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
    	if (k < 0) {
    	    reverse(nums.begin(), nums.end());
    	} else {
    	    for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k]) {
                    break;
                }
            } 
    	    swap(nums[k], nums[l]);
    	    reverse(nums.begin() + k + 1, nums.end());
        }
    }
}; 

// Method 2: swap
void nextPermutation(vector<int>& nums) {
    int i = nums.size() - 1, k = i, tmp;
    while (i > 0 && nums[i-1] >= nums[i])
        i--;
    for (int j=i; j<k; j++, k--)
        tmp = nums[j], nums[j] = nums[k], nums[k] = tmp;
    if (i > 0) {
        k = i--;
        while (nums[k] <= nums[i])
            k++;
        tmp = nums[i], nums[i] = nums[k], nums[k] = tmp;
    }
}