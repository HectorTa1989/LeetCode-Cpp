/*Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.*/

//Sol 1
int maxProduct(vector<int>& nums) {
    if(nums.empty()) {
        return 0;
    }
    int currentMax = nums[0];
    int currentMin = nums[0];
    int maxProduct = nums[0];
    
    for(size_t i = 1; i < nums.size(); ++i) {
        //calculate our new possibilities for this round
        int p1 = currentMax * nums[i];
        int p2 = currentMin * nums[i];
        //our currentMax will be either p1 or p2 or nums[i] whichever is bigger
        currentMax = max(nums[i], max(p1, p2));
        //our currentMin will be either p1 or p2 or nums[i] whichever is smaller
        currentMin = min(nums[i], min(p1, p2));
        //our maxProduct will be our currentMax or our maxProduct, whichever is bigger.
        maxProduct = currentMax > maxProduct ? currentMax : maxProduct;
    }
    return maxProduct;
}
So all you care about is keeping track of the highest possible max so far.

Apart from that you need to keep track of your highest possible in the subarray. Lookup kadanes algorithm for this.

Since we can have negative numbers you need to keep track of your lowest possible in the subarray.
This is because your lowest which might be negative can become your highest when multiplied by a negative number.

By keeping track of these both you have your highest and lowest which can invert themselves.

//Sol 2 
class Solution {
public:
    //min can turn max when encountering another negative number
    //so we have to record all the min and max values;
	int maxProduct(vector<int>& nums) 
    {
        int size = nums.size(), maxProduct = nums[0];
        int maxProducts[size]{0}, minProducts[size]{0};
        maxProducts[0] = minProducts[0] = nums[0];
        for(int i = 1; i < size; ++i)
        {
            maxProducts[i] = max(maxProducts[i-1]*nums[i], max(minProducts[i-1]*nums[i], nums[i]));
            minProducts[i] = min(maxProducts[i-1]*nums[i], min(minProducts[i-1]*nums[i], nums[i]));
            maxProduct = max(maxProduct, maxProducts[i]);
        }
        return maxProduct;
    }

    //actually we only need two variables to record the
    //previous min and max products;
	int maxProduct(vector<int>& nums) 
    {
        int size = nums.size();
        int minProduct = nums[0], maxProduct = nums[0], ret = nums[0];
        for(int i = 1; i < size; ++i)
        {
            if(nums[i] < 0) swap(minProduct, maxProduct);
            maxProduct = max(maxProduct*nums[i], nums[i]);
            minProduct = min(minProduct*nums[i], nums[i]);
            ret = max(ret, maxProduct);
        }
        return ret;
    }
	
//Sol 3
    //another solution using constant space too;
    //traversing from left to right and meantime from right to left
    //to calculate the possible max products since the subsequence will be 
    //from left to right or right to left anyway but in two directions 
    //in case of neglecting the other half;
    int maxProduct(vector<int>& nums) 
    {
        int lProduct = 1, rProduct = 1;
        int size = nums.size(), maxProduct = nums[0];
        for(int i = 0; i < size; ++i)
        {
            lProduct *= nums[i];
            rProduct *= nums[size-i-1];
            maxProduct = max(maxProduct, max(lProduct, rProduct));
            if(lProduct == 0) lProduct = 1;
            if(rProduct == 0) rProduct = 1;
        }
        return maxProduct;
    }
};
//Sol 4
The idea is similar to this article, which is a variation of Kadane's Algorithm
Each element can make the min consinuous product to be the max one and vice versa.
So just easily track the current 'end_here' max value and min value, and the subproblem can be viewed as:
[ <- maximum product subarray -> ][Use this element or not?]
[ <- minimum product subarray -> ][Use this element or not?] and compare with the current element nums[i] to check whether or not to restart an new array.
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        int max_endhere = nums[0], max_endhere_bk = 0;
        int min_endhere = nums[0];
        
        for(int i = 1; i < n; i++){
            res = max(nums[i], max(res, max(max_endhere * nums[i], min_endhere * nums[i])));
            max_endhere_bk = max_endhere; // don't forget this one!
            max_endhere = max(nums[i], max(max_endhere * nums[i], min_endhere * nums[i]));
            min_endhere = min(nums[i], min(max_endhere_bk * nums[i], min_endhere * nums[i]));
        }
        
        return res;
    }
};
//Sol 5
class Solution {
public:
int maxProduct(vector<int>& a) {

    int i,n=a.size();
    
    int mini[n];
    int maxi[n];
    
    mini[0]=a[0];
    maxi[0]=a[0];
    
    int maxpro = a[0];
    for(i=1;i<n;i++) 
    {
        if(a[i]>0)
        {
            maxi[i] = max(maxi[i-1]*a[i], a[i]);
            mini[i] = min(mini[i-1]*a[i], a[i]);
        }
        else
        {
            maxi[i] = max(mini[i-1]*a[i], a[i]);
            mini[i] = min(maxi[i-1]*a[i], a[i]);
        }
        maxpro = max(maxpro, maxi[i]);
    }

    return maxpro;
}
};