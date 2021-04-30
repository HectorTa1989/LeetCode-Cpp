/*Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]*/

//Solution 1
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int> (n, 1));
    int left, right, top, down, index;
    left = top = index = 0, right = down = n-1;
    while (left <= right && top <= down) {
        for (unsigned int j = left; j <= right; j++)
            res[top][j] = ++index;
        top++;
        for (unsigned int i = top; i <= down; i++)
            res[i][right] = ++index;
        right--;
        for (int j = right; j >= left; j--)
            res[down][j] = ++index;
        down--;
        for (int i = down; i >= top; i--)
            res[i][left] = ++index;
        left++;
    }
    return res;
}
//Solution 2
//The idea is just to generate the matrix in the spiral order. First the up-most row (u), then the right-most column (r), 
//then the down-most row (d), and finally the left-most column (l). After generating a row or a column, update the corresponding variable to continue the generation.

The code is as follows.

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) { 
        vector<vector<int> > mat(n, vector<int>(n));
        int u = 0, d = n - 1, l = 0, r = n - 1, num = 1;
        while(true) {
            // up
            for(int col = l; col <= r; col++) mat[u][col] = num++;
            if(++u > d) break;
            // right
            for(int row = u; row <= d; row++) mat[row][r] = num++;
            if(--r < l) break;
            // down
            for(int col = r; col >= l; col--) mat[d][col] = num++;
            if(--d < u) break;
            // left
            for(int row = d; row >= u; row--) mat[row][l] = num++;
            if(++l > r) break;
        }
        return mat;
    }
};

//O(n^2)
class Solution {
public:
    vector<vector<int>> generateMatrix(int A) {
        vector<vector<int>> matrix(A, vector<int> (A, 0));
    
        int c1=0, c2=A-1, r1=0, r2=A-1, val=1;
        while(c1<=c2 && r1<=r2){
            for(int c=c1; c<=c2; c++){
                matrix[r1][c]=val;
                val++;
            }
        
            for(int r=r1+1; r<=r2; r++){
                 matrix[r][c2]=val;
                 val++;
            }
        
            if(c1<c2 && r1<r2){
                for(int c=c2-1; c>c1; c--){
                    matrix[r2][c]=val;
                    val++;
                }
        
                for(int r=r2; r>r1; r--){
                    matrix[r][c1]=val;
                    val++;
                }
            }
        
            r1++;
            c1++;
            r2--;
            c2--;
        }
        return matrix;
    }
};