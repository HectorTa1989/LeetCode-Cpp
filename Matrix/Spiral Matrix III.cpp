/*On a 2 dimensional grid with R rows and C columns, we start at (r0, c0) facing east.
Here, the north-west corner of the grid is at the first row and column, and the south-east corner of the grid is at the last row and column.
Now, we walk in a clockwise spiral shape to visit every position in this grid. 
Whenever we would move outside the boundary of the grid, we continue our walk outside the grid (but may return to the grid boundary later.) 
Eventually, we reach all R * C spaces of the grid.
Return a list of coordinates representing the positions of the grid in the order they were visited.

Example 1:
Input: R = 1, C = 4, r0 = 0, c0 = 0
Output: [[0,0],[0,1],[0,2],[0,3]]8?
*/
class Solution
{
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0)
    {
        //1 1 2 2 3 3 4 4 5 5 6 6
        //0 1 2 3 4 5 6 8 7 8 9 10* increase if it is in the odd number
        int rpos = r0, cpos = c0, dir = 0, go = 1;
        int cnt = 0, ans_cnt = 0;
        int dr[4] = {0, 1, 0, -1};
        int dc[4] = {1, 0, -1, 0};
        vector<vector<int>> res;

        //push back the start position
        res.push_back({rpos, cpos});
        ans_cnt++;
        while(ans_cnt < R * C)
        {
            for(int i = 1;i <= go; i++)
            {
                rpos += dr[dir];
                cpos += dc[dir];
                if(rpos >= 0 && rpos < R && cpos >=0 && cpos < C) //push back th eanswer if it is in the grid
                {
                    res.push_back({rpos, cpos});
                    ans_cnt++;
                }
            }

            if(cnt & 1) //to make  1 1 2 2 3 3 4 4 5 5 sequence
            {
                go++;
            }
            cnt++;

            dir++;
            dir %= 4; //change direction
        }
        return res;
    }
};