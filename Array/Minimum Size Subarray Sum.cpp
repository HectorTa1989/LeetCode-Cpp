class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        if(nums.size() < 1) return 0;
        int sum = 0, minLen = INT_MAX, n = nums.size();
        int start=0, end=0;
        
        while(end < n)
        {
            sum += nums[end++];
            while(sum >= s)
            {
                minLen = min(minLen, end - start);
                sum -= nums[start++];
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
        
    }
};
//Sliding window
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int num_len= nums.size();
        int left=0, right=0, total=0, min_len= num_len+1;
        while (right < num_len) {
            // move right silder forward till total >= s
            do { total += nums[right++]; } while (right<num_len && total< s);
            // move left slider forward while maintaining total >= s
            while (left<right && total-nums[left]>=s) total -= nums[left++];
            // record if it's the minimum
            if (total>=s && min_len> right- left) 
                min_len= right- left;
        }
        return min_len<=num_len ? min_len: 0;
    }
};

/*Then comes the O(nlogn) solution. This less efficient one turns out to be more difficult to come up with.

First, we maintain an array of accumulated sums of elements in nums according to the following two equations.

sums[0] = 0
sums[i] = nums[0] + ... + nums[i - 1] for i > 0
Then, for each sums[i] >= s, we search for the first sums[j] > sums[i] - s (j < i) using binary search. 
In this case, we also have sums[j - 1] <= sums[i] - s. If we plug in the definition for sums, we have

nums[0] + ... + nums[j - 1] > nums[0] + ... + nums[j - 1] + nums[j] + ... + nums[i - 1] - s
nums[0] + ... + nums[j - 2] <= nums[0] + ... + nums[j - 2] + nums[j - 1] + ... + nums[i - 1] - s
If we minus the left-hand side from both inequalities, we have

0 > nums[j] + ... + nums[i - 1] - s
0 <= nums[j - 1] + ... + nums[i - 1] - s
So, we have nums[j - 1] + ... + nums[i - 1] >= s but nums[j] + ... + nums[i - 1] < s. So nums[j-1..i-1] 
is the shortest subarray with sum not less than s ending at i - 1. After traversing all possible i, 
we will find out the shortest subarray with sum not less than s.

By the way, a 0 is added to the head of sums to account for cases like nums = [3], s = 3.*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(), len = INT_MAX;
        vector<int> sums(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        for (int i = n; i >= 0 && sums[i] >= s; i--) {
            int j = upper_bound(sums.begin(), sums.end(), sums[i] - s) - sums.begin();
            len = min(len, i - j + 1);
        }
        return len == INT_MAX ? 0 : len;
    }
};