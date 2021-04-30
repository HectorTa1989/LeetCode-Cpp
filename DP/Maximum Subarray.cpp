/*Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
Example:
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Follow up:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.*/

//Solution 1: Sliding window: 20ms
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if(nums.size()==0) return 0;
		int n=nums.size();
		int cur=0;
		int res=INT_MIN;
		for(int i=0;i<n;i++){

			cur+=nums[i];
			if(cur<nums[i]){
				cur=nums[i];
			}
			res=max(cur,res);

		}
		return res;

	}
};
//Kadane's Algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum=nums[0], sum=nums[0];
        for(int i=1; i<nums.size(); i++) {
            sum = max(nums[i], sum+nums[i]);
            if(sum>max_sum) {
                max_sum=sum;
            }
        }
        
        return max_sum;
    }
};

//DP: 28ms
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp[nums.size()];
        int sum = dp[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
            if(dp[i] > sum) sum = dp[i];
        }
        return sum;
    }
};

//Declare 2 variables ,one which gives final result and the other(temporary) to store the sum . So start traversing when the sum of temporary variable 
//and the element is >0 then it means this give +ve result and store the result in final by finding max of previous result and the current sum and 
//if sum(temporary) is <0 then make sum(temporary)=0 and if there are all negative elements in array then we return the max negative(single) element.

int maxSubArray(vector<int>& nums) {
        int sum=0,f=0;
        bool fe=0;
        for(int i=0;i<nums.size();i++)
        {
            if(sum+nums[i]>0)
            {
                sum+=nums[i];
                f=max(sum,f);
                fe=1;
            }
            else
            {   
                sum=0;
            }
        }
        if(!fe)
        {f=nums[0];
            for(int i=1;i<nums.size();i++)
            {   f=max(nums[i],f);
                
            }
        }
        return f;
        
    }
	
/*O(n) divide and conquer solution
For each subarray, calculate four attributes:

mx (largest sum of this subarray), 
lmx(largest sum starting from the left most element), 
rmx(largest sum ending with the right most element), 
sum(the sum of the total subarray). 
The recurrence is: T(n) = 2T(n / 2) + O(1). So the running time of this algorithm is O(n).
*/
class Solution {
public:
    void maxSubArray(vector<int>& nums, int l, int r, int& mx, int& lmx, int& rmx, int& sum) {
        if (l == r) {
            mx = lmx = rmx = sum = nums[l];
        }
        else {
            int m = (l + r) / 2;
            int mx1, lmx1, rmx1, sum1;
            int mx2, lmx2, rmx2, sum2;
            maxSubArray(nums, l, m, mx1, lmx1, rmx1, sum1);
            maxSubArray(nums, m + 1, r, mx2, lmx2, rmx2, sum2);
            mx = max(max(mx1, mx2), rmx1 + lmx2);
            lmx = max(lmx1, sum1 + lmx2);
            rmx = max(rmx2, sum2 + rmx1);
            sum = sum1 + sum2;
        }
    }
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int mx, lmx, rmx, sum;
        maxSubArray(nums, 0, nums.size() - 1, mx, lmx, rmx, sum);
        return mx;
    }
};