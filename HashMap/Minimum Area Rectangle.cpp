/*Given a set of points in the xy-plane, determine the minimum area of a rectangle formed from these points, with sides parallel to the x and y axes.
If there isn't any rectangle, return 0.

Example 1:
Input: [[1,1],[1,3],[3,1],[3,3],[2,2]]
Output: 4

Example 2:
Input: [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
Output: 2

Note:

1 <= points.length <= 500
0 <= points[i][0] <= 40000
0 <= points[i][1] <= 40000
All points are distinct.
*/

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int res = INT_MAX, n = points.size();
        unordered_map<int, unordered_set<int>> m;
        for (auto point : points) {
            m[point[0]].insert(point[1]);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (points[i][0] == points[j][0] || points[i][1] == points[j][1]) continue;
                if (m[points[i][0]].count(points[j][1]) && m[points[j][0]].count(points[i][1])) {
                    res = min(res, abs(points[i][0] - points[j][0]) * abs(points[i][1] - points[j][1]));
                }   
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
//Sol 2
/*Basic property of rectangle
Given diagonal coordinates x1,y1 and x2,y2 , the rest 2 points that form that rectangle are
x2,y1 and x1,y2.
Draw it on paper if still not sure.
Algorithm:
1.Create a set of all the points.
Notice that I've used 40001*x1 + y1. I tried set of vector , it showed Time Limit Exceeded.
This hashing is inspired from the 'Solution' and this brought down time drastically.
2. For every select another point (2 for loops ) check if for point[i] and point[j] corresponding point exits as per condition mentioned above 
using the created set.
3. Calculate area .*/

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        
        unordered_set<int> allp;
        for(int i=0;i<points.size();i++){            
            allp.insert(40001*points[i][0] + points[i][1]);    // Set of all points using custom hash
        }
        int min_area = INT_MAX,loc_area;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                if(points[i][0] != points[j][0] && points[i][1] != points[j][1]){
                    int x1 = points[i][0],
                        x2 = points[j][0],
                        y1 = points[i][1],
                        y2 = points[j][1];                    
                    if(allp.find(x2*40001+y1)!=allp.end() && allp.find(x1*40001+y2)!=allp.end()){ // Checking if such a point exists
                        loc_area = abs(x1-x2) * abs(y1-y2);
                        min_area = min(min_area,loc_area);
                    }
                }
            }
        }
        return min_area==INT_MAX?0:min_area;
        
    }
};