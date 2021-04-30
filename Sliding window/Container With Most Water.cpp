/*Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, 
which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.*/

//Two pointers
//Time complexity: O(n)
//Space complexity: O(1)
class Solution {
public:
    int maxArea(const vector<int>& height) {
        int ans = 0;
        int l = 0;
        int r = height.size() - 1;
        while (l < r) {
            int h = min(height[l], height[r]);
            ans = max(ans, h * (r - l));
            if (height[l] < height[r]) 
                ++l;
            else
                --r;
        }
        return ans;
    }
};