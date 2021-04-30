/*Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:

Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation: 
The repeated subarray with maximum length is [3, 2, 1].*/

//DP1
class Solution {
public:
	int findLength(vector<int>& A, vector<int>& B) {
		vector<int> dp(B.size() + 1, 0);
		int res = 0;
		for (int i = 1; i <= A.size(); i++)
			for (int j = B.size(); j > 0; j--) {
				if (A[i - 1] == B[j - 1]) {
					dp[j] = dp[j - 1] + 1;					
					if (dp[j] > res)
						res = dp[j];
				}
				else
					dp[j] = 0;
			}
		return res;
	}
};
//DP2
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        // dp[i][j] is the maximum length of subarray ending with A[i] and B[j]
        // dp[i][j] = (A[i] == B[j]) ? dp[i - 1][j - 1] + 1 : 0;
        int m = A.size(), n = B.size();
        vector<vector<int>>dp(m, vector<int>(n));
        int maxlen = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0) dp[i][j] = (A[i] == B[j]);
                else dp[i][j] = (A[i] == B[j]) ? dp[i - 1][j - 1] + 1 : 0;
                maxlen = max(maxlen, dp[i][j]);
            }
        return maxlen;
    }
};
//
It's a O(mn) solution.
Basic idea is create a matrix M and store the max length of repeated subarray which end with A[i] or B[j] in M[i][j].
For example

A: [1,2,3,2,1]
B: [3,2,1,4,7]
Make the below matrix and then find the maximum value in it.

     3   2   1   4   7
1   [0] [0] [1] [0] [0]
2   [0] [1] [0] [0] [0]
3   [1] [0] [0] [0] [0]
2   [0] [2] [0] [0] [0]
1   [0] [0] [3] [0] [0]
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int res = 0;
        vector<vector<int>> v(A.size(), vector<int>(B.size(), 0));
        for (auto i = 0; i < A.size(); i++) {
            for (auto j = 0; j < B.size(); j++) {
                if (A[i] == B[j]) {
                    if (i == 0 || j == 0)
                        v[i][j] = 1;
                    else
                        v[i][j] = v[i - 1][j - 1] + 1;
                    
                    res = max(res, v[i][j]);
                }
            }
        }
        
        return res;
    }
};