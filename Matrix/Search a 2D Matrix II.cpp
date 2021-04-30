/*This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Start our at a location where we have reduced search space. How do we know our search space
        // is reduced at the bottom left? Because at that location we can either go right, finding greater
        // numbers, or up, finding lower numbers. If we started at the bottom right, regardless of 
        // where we go, (up or left), we are finding lower numbers, the computer would be confused
        // as to which direcction it should take, given that both directions lead to lower numbers.
        // Starting at the bottom left we force the computer to either go to a lower number or higher number.
        int x = matrix.size() - 1;
        int y = 0;
        while (x >= 0 && y >=0 && x != matrix.size() && y != matrix[0].size()) { // Don't go off the grid
            if (matrix[x][y] == target) {
                return true;
            } else if (matrix[x][y] > target) { // If too big, we need to go down.
                x--;
            } else { // Too small? Go right.
                y++;
            }
        }
        return false;
    }
};


/*Search from the top-right element and reduce the search space by one row or column at each time.

[[ 1,  4,  7, 11, 15],
 [ 2,  5,  8, 12, 19], 
 [ 3,  6,  9, 16, 22],
 [10, 13, 14, 17, 24],
 [18, 21, 23, 26, 30]]
Suppose we want to search for 12 in the above matrix. compare 12 with the top-right element nums[0][4] = 15. Since 12 < 15, 12 cannot appear in the column of 15 since all elements in that column are greater than or equal to 15. Now we reduce the search space by one column (the last column).

We further compare 12 with the top-right element of the remaining matrix, which is nums[0][3] = 11. Since 12 > 11, 12 cannot appear in the row of 11 since all elements in this row are less than or equal to 11 (the last column has been discarded). Now we reduce the search space by one row (the first row).

We move on to compare 12 with the top-right element of the remaining matrix, which is nums[1][3] = 12. Since it is equal to 12, we return true.*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0, r = 0, c = n - 1;
        while (r < m && c >= 0) {
            if (matrix[r][c] == target) {
                return true;
            }
            matrix[r][c] > target ? c-- : r++;
        }
        return false;
    }
};

//
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if (row == 0)
            return false;
        int col = matrix[0].size();
        if (col == 0)
            return false;
        if (target < matrix[0][0] || target > matrix[row-1][col-1])
            return false;
        
        int i = 0, j = col - 1;
        while (i < row && j >=0)
        {
            if (target == matrix[i][j])
                return true;
            //if target > matrix[i][j],then target must not appear in row-i
            else if (target > matrix[i][j])
                ++i;
            //if target < matrix[i][j],then target must not appear in column-j
            else
                --j;
        }
        
        return false;
    }
};

// Binary Search
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // check bad input
    int m = matrix.size();
    if(m == 0)
        return false;
    int n = matrix[0].size();
    if(n == 0)
        return false;
    return binarySearch(matrix, target, 0, m-1, 0, n-1);
}

bool binarySearch(vector<vector<int>>& matrix, int target, 
int min_i, int max_i, 
int min_j, int max_j){
    if(min_i > max_i)
        return false;
    if(min_j > max_j)
        return false;
    int i = (min_i + max_i)/2;
    int j = (min_j + max_j)/2;
    
    int value = matrix[i][j];
    if(value == target)
        return true;
    else if(value < target)
    {
        return binarySearch(matrix, target, min_i, max_i, j+1, max_j)
        || binarySearch(matrix, target, i+1, max_i, min_j, j);
    }
    else
    {
        return binarySearch(matrix, target, min_i, max_i, min_j, j-1)
        || binarySearch(matrix, target, min_i, i-1, j, max_j);            
    }
}

// Binary Search 2
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size(), col = row ? matrix[0].size() : 0;
    int start = 0, end = row, mid, endRow, startRow;
    // first we determine the first row the target might occurs.
    // notice that here we implement the lower_bound binary search.
    while (start < end) {
        mid = (start + end) / 2;
        if (matrix[mid][col-1] >= target) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    startRow = start;
    //then we caclulate the end row (not included) the target might occurs
    // here is for upper_bound binary search.
    start = 0, end = row;
    while (start < end) {
        mid = (start + end) / 2;
        if (matrix[mid][0] > target) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    endRow = start;
    //finally, iterate through each row until we find the target
    // and here is also lower_bound binary search.
    for (int i = startRow;i < endRow;++i) {
        start = 0, end = col;
        while (start < end) {
            mid = (start + end) / 2;
            if (matrix[i][mid] >= target) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        if (start < col && matrix[i][start] == target)
            return true;
    }
    return false;
}