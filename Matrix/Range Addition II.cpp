/*Given an m * n matrix M initialized with all 0's and several update operations.

Operations are represented by a 2D array, and each operation is represented by an array with two positive integers a and b, 
which means M[i][j] should be added by one for all 0 <= i < a and 0 <= j < b.

You need to count and return the number of maximum integers in the matrix after performing all the operations.

Example 1:
Input: 
m = 3, n = 3
operations = [[2,2],[3,3]]
Output: 4
Explanation: 
Initially, M = 
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]

After performing [2,2], M = 
[[1, 1, 0],
 [1, 1, 0],
 [0, 0, 0]]

After performing [3,3], M = 
[[2, 2, 1],
 [2, 2, 1],
 [1, 1, 1]]

So the maximum integer in M is 2, and there are four of it in M. So return 4.*/
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for(auto x:ops)
        {
            m = min(m,x[0]);
            n = min(n,x[1]);
        }
        return m*n;
    }
};
//Sol 2
int maxCount(int m, int n, vector<vector<int>>& ops) {
        
        int minRow = INT_MAX;
        int minCol = INT_MAX;
        
        if(ops.size() == 0)
            return m*n;
        
        for(int i=0; i<ops.size(); i++)
        {
            minRow = min(minRow, ops[i][0]);
            minCol = min(minCol, ops[i][1]);
        }
        
        return minRow*minCol;
    }