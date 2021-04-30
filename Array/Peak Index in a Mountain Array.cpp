/*Let’s call an array A a mountain if the following properties hold:

A.length >= 3
There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].

Example 1:

Input: [0,1,0]
Output: 1
Example 2:

Input: [0,2,1,0]
Output: 1
*/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        for(int i=1; i < A.size()-1; i++)
            if(A[i-1] < A[i] && A[i] > A[i+1]) return i;
        return 0;
    }
};
//Binary Search
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int lo = 0, hi = A.size() - 1;
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (A[mi] < A[mi + 1])
                lo = mi + 1;
            else
                hi = mi;
        }
        return lo;       
    }
};
//
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int l = 0;
        int r = A.size() - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(A[mid] > A[mid+1] && A[mid] > A[mid-1])
                return mid;
            if(A[mid] < A[mid+1])
                l = mid + 1;
            if(A[mid] > A[mid+1])
                r = mid - 1;
        }
        return -1;
    }
};