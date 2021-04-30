//https://github.com/haoel/leetcode/blob/master/algorithms/cpp/minCostClimbingStairs/MinCostClimbingStairs.cpp
// Method 1: A straightforward solution is:

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < n; i++)
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        return min(dp[n - 2], dp[n - 1]);
    }
};
If we take a look at the solution above, we can see the result dp[i] only depends on previous 2 steps(dp[i - 1] and dp[i - 2]). So we can replace the dp array with 2 variables.

Here is the final solution:
// Method 2
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(), a = cost[0], b = cost[1], c;
        for(int i = 2; i < n; i++, a = b, b = c)
            c = min(a, b) + cost[i];
        return min(a, b);
    }
};

// Method 3
class Solution {
public:
int minCostClimbingStairs(vector<int>& cost) 
{
    int len = cost.size();
    
    if(len == 0 || len == 1)
        return 0;
    if(len == 2)
        return min(cost[0], cost[1]);
    
    vector<int> dp(len+1, 0);
    
    dp[0] = 0; //Base cases for recursion
    dp[1] = 0;
    dp[2] = min(cost[0], cost[1]);
    
    for(int i=3; i<=len; i++)
    {
        dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
		//Minimum of either the cost required to reach (i-1) or (i-2) step + the cost of climbing that step particular step
    }
  
    return dp[len];
}
};

// Method 4
class Solution {
    public:
        int minCostClimbingStairs(vector<int>& cost) {
            return minCostClimbingStairs02(cost); 
            return minCostClimbingStairs01(cost); 
        }
        int minCostClimbingStairs01(vector<int>& cost) {
            vector<int> dp(cost.size() , 0);
            dp[0] = cost[0];
            dp[1] = cost[1];
            for (int i=2; i<cost.size(); i++) {
                dp[i] = min( dp[i-1], dp[i-2] ) + cost[i];
            }
            return min(dp[dp.size()-1], dp[dp.size()-2]);
        }

        int minCostClimbingStairs02(vector<int>& cost) {
            int dp1 = cost[0], dp2 = cost[1];
            for (int i=2; i<cost.size(); i++) {
                int dp = min( dp1, dp2 ) + cost[i];
                dp1 = dp2;
                dp2 = dp;
            }
            return min (dp1, dp2);
        }
};