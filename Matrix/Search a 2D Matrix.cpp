//https://www.tutorialspoint.com/search-a-2d-matrix-in-cplusplus

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // treat the matrix as an array, just taking care of indices
    // [0..n*m]
    // (row, col) -> row*n + col
    // i -> [i/n][i%n]
    if(matrix.empty() || matrix[0].empty())	// or if(matrix.size() == 0) return false;
    {
        return false;
    }
    int m = matrix.size(), n = matrix[0].size();
    int start = 0, end = m*n - 1;
    while(start <= end)
    {
        int mid = start + (end - start)/2;
        int e = matrix[mid/n][mid%n];
        if(target < e)
        {
            end = mid - 1;
        }
        else if(target > e)
        {
            start = mid + 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}
//Method 2
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), x, y;
        int lo = 0, hi = m*n-1, mid;
        if (hi == 0) return (matrix[0][0] == target);	// or if(matrix.size() == 0) return false;
        while (lo <= hi)
        {
            mid = lo + (hi-lo)/2;
            x = mid / n; y = mid % n;
            if (matrix[x][y] == target)
                return true;
            else if (matrix[x][y] > target)
                hi = mid-1;
            else
                lo = mid+1;
        }
        return false;
    }
};

//
typedef long long int lli;
class Solution {
   public:
   bool searchMatrix(vector<vector<int>>& matrix, int target) {
      lli n,m;
      n = matrix.size();
      if(!n)return false;
      m = matrix[0].size();
      if(!m)return false;
      lli low = 0, high = n-1;
      while(low<high){
         lli mid = low + ( high - low +1)/2;
         if(matrix[mid][0]<=target)low = mid;
         else high = mid -1;
      }
      lli rlow = 0, rhigh = m-1;
      lli ans = 0;
      //cout << low << endl;
      while(rlow<=rhigh){
         lli mid = rlow+(rhigh - rlow)/2;
         if(matrix[low][mid] == target){
            ans =1;
            break;
         } else if(matrix[low][mid]<target)rlow=mid+1;
         else rhigh= mid-1;
      }
      return ans;
   }
};