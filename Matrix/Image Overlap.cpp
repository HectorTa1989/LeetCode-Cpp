/*Two images A and B are given, represented as binary, square matrices of the same size.  (A binary matrix has only 0s and 1s as values.)

We translate one image however we choose (sliding it left, right, up, or down any number of units), and place it on top of the other image.  
After, the overlap of this translation is the number of positions that have a 1 in both images.
(Note also that a translation does not include any kind of rotation.)
What is the largest possible overlap?

Example 1:
Input: A = [[1,1,0],
            [0,1,0],
            [0,1,0]]
       B = [[0,0,0],
            [0,1,1],
            [0,0,1]]
Output: 3
Explanation: We slide A to right by 1 unit and down by 1 unit.*/

class Solution {
public:
    
    int check(vector<vector<int>> &A, vector<vector<int>> &B) {
        int ans = 0;
        for(int i = 0; i < A.size(); ++i) {
            for(int j = 0; j < A[0].size(); ++j) {
                int sum = 0;
                for(int k = i; k < A.size(); ++k) {
                    for(int l = j; l < A[0].size(); ++l) {
                        if(A[k][l] && A[k][l] == B[k - i][l - j]) ++sum;
                    }
                }
                ans = max(ans, sum);
            }
        }
        return ans;
    }
    
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        return max(check(A, B), check(B, A));
    }
};