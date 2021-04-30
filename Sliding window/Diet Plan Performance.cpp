/*A dieter consumes calories[i] calories on the i-th day.  For every consecutive sequence of k days, they look at T, the total calories consumed during that sequence of k days:

If T < lower, they performed poorly on their diet and lose 1 point; 
If T > upper, they performed well on their diet and gain 1 point;
Otherwise, they performed normally and there is no change in points.
Return the total number of points the dieter has after all calories.length days.

Note that: The total points could be negative.

Example 1:

Input: calories = [1,2,3,4,5], k = 1, lower = 3, upper = 3
Output: 0
Explaination: calories[0], calories[1] < lower and calories[3], calories[4] > upper, total points = 0.
Example 2:

Input: calories = [3,2], k = 2, lower = 0, upper = 1
Output: 1
Explaination: calories[0] + calories[1] > upper, total points = 1.*/

//Time complexity: O(n)
//Space complexity: O(1)
// Author: Huahua
class Solution {
public:
  int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
    int ans = 0;
    int t = accumulate(begin(calories), begin(calories) + k - 1, 0);
    for (int i = k - 1; i < calories.size(); ++i) {
      if (i >= k) t -= calories[i - k];
      t += calories[i];
      if (t > upper) ++ans;
      if (t < lower) --ans;      
    }
    return ans;
  }
};	