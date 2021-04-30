class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i=0; i<matrix.size(); i++)
            for (int j=0; j<i; j++) swap(matrix[i][j], matrix[j][i]);
        
        for (auto& row: matrix) reverse(row.begin(), row.end());
    }
};

//Method 2: Transpose the matrix initially, and then reverse rows of the matrix.
class Solution {
public:
void rotate(vector<vector<int>>& matrix) 
{
    int n = matrix.size();
    
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    
    for(int i=0; i<n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
};
//1,2,3    7,8,9    7,4,1
//4,5,6 => 4,5,6 => 8,5,2 
//7,8,9    1,2,3    9,6,3
//(1)swap row i and row n-1-i
//(2)swap elements in symmetrical position
class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            int n = matrix.size();
            if (n < 2)
                return;
                
            int i = 0, j = 0, temp = 0;
            int mid = (n - 1) / 2;
            
            for (i = 0; i <= mid; i++)
            {
                for (j = 0; j < n; j++)
                {
                    temp = matrix[i][j];
                    matrix[i][j] = matrix[n-1-i][j];
                    matrix[n-1-i][j] =temp;
                }
            }
            
            for (i = 1; i < n; i++)
            {
                for (j = 0; i > j; j++)
                {
                    temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
            }
        }
    };