/*A subarray A[i], A[i+1], ..., A[j] of A is said to be turbulent if and only if:
For i <= k < j, A[k] > A[k+1] when k is odd, and A[k] < A[k+1] when k is even;
OR, for i <= k < j, A[k] > A[k+1] when k is even, and A[k] < A[k+1] when k is odd.
That is, the subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.
Return the length of a maximum size turbulent subarray of A.

Example 1:
Input: [9,4,2,10,7,8,8,1,9]
Output: 5
Explanation: (A[1] > A[2] < A[3] > A[4] < A[5])

Example 2:
Input: [4,8,12,16]
Output: 2*/


class Solution {
public:
     bool isPosL(vector<int>&arr, int ind, int low)
    {
        bool res = true;
        if(ind-2 >= low)
        {
            return (arr[ind-1] > arr[ind] && arr[ind-1] > arr[ind-2]) ||(arr[ind-1] < arr[ind] && arr[ind-1] < arr[ind-2]);
        }
        else
        {
            return ind>low ? arr[ind] != arr[ind-1] : true;
        }
        return res;
    }
	
    int maxTurbulenceSize(vector<int>& A) {
        if(A.size() == 0 || A.size() == 1)
            return A.size();
        int i=0,j=0;
        int len = 1;
        while(j<A.size())
        {
            while(j<A.size() && isPosL(A,j,i))
            {
                len = std::max(len,j-i+1);
                j++;
            }
            if(i!=j-1)
                i = j-1;
            else
                i = j;
        }
        return len;
    }
};

//Kadane's algorithm
//A subarray is turbulent if the comparison sign alternates between consecutive elements (ex. nums[0] < nums[1] > nums[2] < nums[3] > ... ). 
//Looking at the structure of the array, this means every element of a turbulent subarray must belong to either a peak (A[i-2] < A[i-1] > A[i]) 
//or a valley (A[i-2] > A[i-1] < A[i]) structure.
//The algorithm works as follows. Keep track of the length of the longest run ending at index i. This is tracked in a variable named clen. 
//If the last three elements form a peak or a valley, we can extend the previous run length by 1 (meaning clen += 1). Otherwise, 
//we can no longer extend this run and need to reset clen to the length of the longest run ending at index i. 
//This run length will be 1 if the previous and current elements are the same (Ex: [2,2,2]), or 2 if the previous and current elements differ (Ex: [2,4,6]). 
//The answer is the length of the best run found.
int maxTurbulenceSize(vector<int>& A) {
    int best = 0, clen = 0;

    for(int i = 0; i < A.size(); ++i) {
        if (i >= 2 && ((A[i-2] > A[i-1] && A[i-1] < A[i]) ||
                       (A[i-2] < A[i-1] && A[i-1] > A[i])) ) {
            clen++;
        } else if (i >= 1 && A[i-1] != A[i]) {
            clen = 2;
        } else {
            clen = 1;
        }
        best = max(best, clen);
    }
    return best;
}