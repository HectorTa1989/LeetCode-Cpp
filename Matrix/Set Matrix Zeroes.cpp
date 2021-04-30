class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int Rsize = matrix.size(), Csize = matrix[0].size();
        bool firstRow = false, firstCol = false;
        int c, r;
        
        for(r = 0; r < Rsize; r++)
        {
            if(matrix[r][0] == 0)
                firstCol = true;
        } 
        for(c = 0; c < Csize; c++)
            
        {if(matrix[0][c] == 0)
                firstRow = true;
        }
        for(r=1; r<Rsize; r++)
            for(c=1; c< Csize; c++)
                if(matrix[r][c] == 0) 
                    matrix[r][0] = matrix[0][c] = 0;
        
        for(c=1; c<Csize; c++)
            if(matrix[0][c] == 0)
                for(r=1; r<Rsize; r++)
                    matrix[r][c] = 0;
        
        for(r = 1; r<Rsize; r++)
            if(matrix[r][0] == 0)
                for(c=1; c<Csize; c++)
                    matrix[r][c] = 0;
        if(firstRow) 
            for(c=0; c<Csize; c++)
                matrix[0][c] = 0;
        if(firstCol)
            for(r=0; r<Rsize; r++)
                matrix[r][0] = 0;
        
    }
};

//http://bangbingsyb.blogspot.com/2014/11/leetcode-set-matrix-zeroes.html
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if(matrix.empty() || matrix[0].empty()) return;
        int m = matrix.size(), n = matrix[0].size();
        
        // find if the 1st row/col needs to be set as zero
        bool isFirstRowZero = false;
        bool isFirstColZero = false;
        for(int j=0; j<n; j++) {
            if(matrix[0][j]==0) {
                isFirstRowZero = true;
                break;
            }
        }
        for(int i=0; i<m; i++) {
            if(matrix[i][0]==0) {
                isFirstColZero = true;
                break;
            }
        }
        
        // use 1st row/col to record whether to set each col/row as zero
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(matrix[i][j]==0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
        // set rows & cols
        for(int i=1; i<m; i++) {
            if(matrix[i][0]==0) setRowCol(matrix, i, true);
        }
        for(int j=1; j<n; j++) {
            if(matrix[0][j]==0) setRowCol(matrix, j, false);
        }
        
        // set first row & col
        if(isFirstRowZero) setRowCol(matrix, 0, true);
        if(isFirstColZero) setRowCol(matrix, 0, false);
    }
    
    void setRowCol(vector<vector<int>> &matrix, int index, bool isSetRow) {
        if(matrix.empty() || matrix[0].empty() || index<0) return;
        int m = matrix.size(), n = matrix[0].size();
        if((isSetRow && index>=m) || (!isSetRow && index>=n)) return;
        
        if(isSetRow) {
            for(int j=0; j<n; j++)
                matrix[index][j] = 0;
        }
        else {
            for(int i=0; i<m; i++)
                matrix[i][index] = 0;
        }
    }
};