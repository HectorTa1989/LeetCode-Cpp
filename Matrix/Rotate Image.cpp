/*You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j< i ; j++)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        for(auto& x:matrix)
        {
            reverse(x.begin(), x.end());
        }
    }
};
//
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.empty()) return;
        if(matrix[0].size() != matrix.size()) return;

        int n = matrix.size();        
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < n - i - 1; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][n - 1 - i];
                matrix[n - 1 - j][n - 1 - i] = temp;
            }
        }


        for(int i = 0; i < n / 2; i++){
            for(int j = 0; j < n; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - i][j];
                matrix[n - 1 - i][j] = temp;
            }
        }

        return;
    }
};