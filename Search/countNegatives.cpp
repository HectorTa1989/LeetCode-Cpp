/*Given a m * n matrix grid which is sorted in non-increasing order both row-wise and column-wise. 
Return the number of negative numbers in grid.

Example 1:
Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.

Example 2:
Input: grid = [[3,2],[1,0]]
Output: 0
*/
class Solution {
public:
    static int countNegativesHelper(const vector<int>& vec) {
        int low = 0;
        int high = vec.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (vec[mid] >= 0) {
                // discard everything before mid which is non-negative
                low = mid + 1;
            } else {
                // discard everything after high which is negative
                high = mid - 1;
            }
        }
        // high is the index for the last non-negative number
        // high + 1 is the number of non-negative numbers
        // size - (high + 1) is the number of negative numbers
        return vec.size() - high - 1;
    }

    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for (int i=0; i<grid.size(); i++) {
            count += countNegativesHelper(grid[i]);
        }
        return count;
    }
};

// Method 2: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/discuss/546557/C%2B%2B-O(n)-0ms
namespace
{
	class Solution {
    public:
        static int countNegatives(const vector<vector<int>>& grid)
        {
            const auto height = grid.size();        
            const auto width  = grid[0].size();

            // Scan each row in whole grid:
            unsigned pos_count = 0;
            for(unsigned y = 0; y < height; ++y){
                // These rows are too short to make a binary search
                // worthwhile so we just linearly scan along the cachelines:
                for(unsigned x = 0; x < width; ++x){
                    if(grid[y][x] >= 0) ++pos_count;
                    else break;
                }
            }
			return  width * height - pos_count;
        }
    };
    
    static const auto fast=[](){ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return nullptr;}();
}