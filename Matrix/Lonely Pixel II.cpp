/*Given a picture consisting of black and white pixels, and a positive integer N, find the number of black pixels located at some specific row R and column C that align with all the following rules:

Row R and column C both contain exactly N black pixels.
For all rows that have a black pixel at column C, they should be exactly the same as row R
The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively.

Example:
Input:                                            
[['W', 'B', 'W', 'B', 'B', 'W'],    
 ['W', 'B', 'W', 'B', 'B', 'W'],    
 ['W', 'B', 'W', 'B', 'B', 'W'],    
 ['W', 'W', 'B', 'W', 'B', 'W']] 

N = 3
Output: 6
Explanation: All the bold 'B' are the black pixels we need (all 'B's at column 1 and 3).
        0    1    2    3    4    5         column index                                            
0    [['W', 'B', 'W', 'B', 'B', 'W'],    
1     ['W', 'B', 'W', 'B', 'B', 'W'],    
2     ['W', 'B', 'W', 'B', 'B', 'W'],    
3     ['W', 'W', 'B', 'W', 'B', 'W']]    
row index

Take 'B' at row R = 0 and column C = 1 as an example:
Rule 1, row R = 0 and column C = 1 both have exactly N = 3 black pixels. 
Rule 2, the rows have black pixel at column C = 1 are row 0, row 1 and row 2. They are exactly the same as row R = 0.

Note:
The range of width and height of the input 2D array is [1,200].*/

class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        if (picture.empty() || picture[0].empty()) return 0;
        int m = picture.size(), n = picture[0].size(), res = 0;
        vector<int> colCnt(n, 0);
        unordered_map<string, int> u;
        for (int i = 0; i < m; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B') {
                    ++colCnt[j];
                    ++cnt;
                }
            }
            if (cnt == N) ++u[string(picture[i].begin(), picture[i].end())];
        }
        for (auto a : u) {
            if (a.second != N) continue;
            for (int i = 0; i < n; ++i) {
                res += (a.first[i] == 'B' && colCnt[i] == N) ? N : 0;
            }
        }
        return res;
    }
};

//
class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        if (picture.empty() || picture[0].empty()) return 0;
        int m = picture.size(), n = picture[0].size(), res = 0, k = 0;
        vector<int> rowCnt(m, 0), colCnt(n, 0);
        vector<string> rows(m, "");
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rows[i].push_back(picture[i][j]);
                if (picture[i][j] == 'B') {
                    ++rowCnt[i];
                    ++colCnt[j];
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rowCnt[i] == N && colCnt[j] == N) {
                    for (k = 0; k < m; ++k) {
                        if (picture[k][j] == 'B') {
                            if (rows[i] != rows[k]) break;
                        }
                    }
                    if (k == m) {
                        res += colCnt[j];
                        colCnt[j] = 0;
                    }
                }
            }
        }
        return res;
    }
};