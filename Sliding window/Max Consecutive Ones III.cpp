/*Given an array A of 0s and 1s, we may change up to K values from 0 to 1.

Return the length of the longest (contiguous) subarray that contains only 1s. 

 

Example 1:

Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
Output: 6
Explanation: 
[1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.*/

//Time - O(n)
//Space - O(1)
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int l=0, r=0, n=A.size(), ans=0, count=0;
        while(r<n)
        {
            if(A[r] == 0) count++;
            while(count > K)
            {
                if(A[l++] == 0) count--;
            }
            ans= max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};

//Similar
class Solution {
public:
	int longestOnes(vector<int>& A, int K) {
		int left=0;
		int ans=0;
		int count=0;
		for(int i=0;i<A.size();i++){
			if(A[i]==0){
				count++;
			}
			while(count>K){
				if(A[left]==0){
					count--;
				}
				left++;
			}
			ans=max(ans,i-left+1);
		}
		return ans;

	}
};