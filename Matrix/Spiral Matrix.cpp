/*Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
Example 1:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]*/

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.empty())
        return {};
    vector<int> res;
    int left, right, top, down, index;
    left = top = 0, down = matrix.size()-1, right = matrix[0].size()-1;
    while (left <= right && top <= down) {
        for (unsigned int j = left; j <= right; j++)
            res.push_back(matrix[top][j]);
        top++;
        for (unsigned int i = top; i <= down; i++)
            res.push_back(matrix[i][right]);
        right--;
        if (top <= down) {
            for(int j = right; j >= left; j--)
                res.push_back(matrix[down][j]);
            down--;
        }
        if (left <= right) {
            for (int i = down; i >= top; i--)
                res.push_back(matrix[i][left]);
            left++;
        }
    }
    return res;
}
//
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> res;
        int row = matrix.size();
        
        if(row == 0) return {};
        int col = matrix[0].size();
        
        int r = 0;
        int c = 0;
        
        while(r < row && c < col)
        {
            for(int i=c; i<col; i++)
                res.push_back(matrix[r][i]);
            r++;
            
            for(int i=r; i<row; i++)
                res.push_back(matrix[i][col-1]);
            col--;
            
            if(r < row)
            {
                for(int i=col-1; i>=c; i--)
                    res.push_back(matrix[row-1][i]);
                row--;
            }
            
            if(c < col)
            {
                for(int i=row-1; i>=r; i--)
                    res.push_back(matrix[i][c]);
                c++;
            }
        }
        return res;
    }
};

//Traverse the matrix in the spiral order by keeping four variables: u for the uppermost row, d for the downmost row, l for the leftmost column and r for the rightmost column.

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0, u = 0, d = m - 1, l = 0, r = n - 1, p = 0;
        vector<int> order(m * n);
        while (u <= d && l <= r) {
            for (int col = l; col <= r; col++) {
                order[p++] = matrix[u][col];
            }
            if (++u > d) {
                break;
            }
            for (int row = u; row <= d; row++) {
                order[p++] = matrix[row][r];
            }
            if (--r < l) {
                break;
            }
            for (int col = r; col >= l; col--) {
                order[p++] = matrix[d][col];
            }
            if (--d < u) {
                break;
            }
            for (int row = d; row >= u; row--) {
                order[p++] = matrix[row][l];
            }
            if (l++ > r) {
                break;
            }
        }
        return order;
    }
};