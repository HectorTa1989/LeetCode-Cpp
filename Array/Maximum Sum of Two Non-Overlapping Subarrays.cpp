/*Given an array A of non-negative integers, return the maximum sum of elements in two non-overlapping (contiguous) subarrays, which have lengths L and M.  
(For clarification, the L-length subarray could occur before or after the M-length subarray.)
Formally, return the largest V for which V = (A[i] + A[i+1] + ... + A[i+L-1]) + (A[j] + A[j+1] + ... + A[j+M-1]) and either:
0 <= i < i + L - 1 < j < j + M - 1 < A.length, or
0 <= j < j + M - 1 < i < i + L - 1 < A.length.
 
Example 1:
Input: A = [0,6,5,2,2,5,1,9,4], L = 1, M = 2
Output: 20
Explanation: One choice of subarrays is [9] with length 1, and [6,5] with length 2.

Example 2:
Input: A = [3,8,1,3,2,1,8,9,0], L = 3, M = 2
Output: 29*/


//The approach here is based on sliding a window by fixing L sized and M sized subarrays.

Keep a prefix sum array to get the sums in O(1) when answer is calculated.
Loop from i = (L + M) to Array.size()
Fix an M sized subarray at index i - 1. Find the maximum sized L sized subarray before the fixed subarray.
Fix an L sized subarray at index i - 1. Find the maximum sized M sized subarray before the fixed subarray.
Update result with maximum sum of L and M sized subarray uptil now.

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
		// maximum sum of L sized, maximum sum of M sized, maximum of (L sized + M sized) 
        int lMax, mMax, result;
        vector<int> prefixSum(A.size());
        
		// fill the prefix sum array
        for(int i = 0; i < A.size(); i++) {
            prefixSum[i] = (i == 0) ? A[i] : prefixSum[i - 1] + A[i];
        }
        
        lMax = mMax = result = INT_MIN;
        
        for(int i = (L + M); i <= A.size(); i++) {
			// fix M sized subarray, and find maximum sum of L sized subarray uptil now
            lMax = (i == (L + M)) ? prefixSum[L - 1] : max(lMax, prefixSum[i - M - 1] - prefixSum[i - L - M - 1]);
			// fix L sized subarray, and find maximum sum of M sized subarray uptil now
            mMax = (i == (L + M)) ? prefixSum[M - 1] : max(mMax, prefixSum[i - L - 1] - prefixSum[i - L - M - 1]);
            
			// update maximum of (L sized + M sized) uptil now
            result = max({result, 
                          prefixSum[i - 1] - prefixSum[i - L - 1] + mMax,
                          prefixSum[i - 1] - prefixSum[i - M - 1] + lMax
                         });
        }
        
        return result;
    }
};

//Solution 2
int findMaxSum3(vector<int>& A,int n,int L,int M,int start,int end){
    int maxSum = INT_MIN;
    int left = start-1;
    for(int i=M-1+start;i<=end;i++){
        int temp = 0;
        temp = A[i] - A[left];
        left++;
        if(temp > maxSum){
            maxSum = temp;
        }
    }
    return maxSum;
}

int findMaxSum(vector<int>& A,int n,int L,int M){
    //care about the bound also
    int left = -1;
    int maxSum = INT_MIN;
    for(int i=L-1;i<n;i++){
        int temp = 0;
        if(left != -1){
            temp = A[i] - A[left]; 
        }else{
            temp = A[i];
        }
        left++;
        
        int opt = findMaxSum3(A,n,L,M,i+1,n-1);
        if(opt == INT_MIN)  break;
        maxSum = max(maxSum,temp+opt);
    }
    return maxSum;
}



class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int n = A.size();
        
        for(int i=1;i<n;i++){
            A[i] += A[i-1];
        }
        return max(findMaxSum(A,n,L,M),findMaxSum(A,n,M,L));
    }
};