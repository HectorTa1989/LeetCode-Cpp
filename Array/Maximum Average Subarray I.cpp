/*Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.

Example 1:
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75 */

//Sliding Window
//Instead of creating a cumulative sum array first, and then traversing over it to determine the required sum, we can simply traverse over numsnums just once, 
//and on the go keep on determining the sums possible for the subarrays of length kk. To understand the idea, assume that we already know the sum of elements 
//from index ii to index i+ki+k, say it is xx.
//Now, to determine the sum of elements from the index i+1i+1 to the index i+k+1i+k+1, all we need to do is to subtract the element nums[i]nums[i] from xx and to 
//add the element nums[i+k+1]nums[i+k+1] to xx. We can carry out our process based on this idea and determine the maximum possible average.
class Solution {
public:
    double findMaxAverage(vector<int>& a, int k) {
        long max = 0, sum = 0;
        int i = 0, n = a.size();
        while (i < k) {
            sum += a[i];
            i++;
        }
        int j = 0;
        max = sum;
        for (int i = k; i < n; i++,j++) {
            sum -= a[j];
            sum += a[i];
            if (sum > max) max = sum;
        }
        return max/double(k);
    }
};

//
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0 ;
        
        for(int i=0 ; i<k ; i++){
            sum += nums[i] ;
        }
        double maxm = sum ;
        int n = nums.size() ;
        
        for(int i=k ; i<n ; i++){
            sum = sum + nums[i] - nums[i-k] ;
            maxm = max(maxm,sum) ;
        }
        
        return maxm/k ;
        
    }
};