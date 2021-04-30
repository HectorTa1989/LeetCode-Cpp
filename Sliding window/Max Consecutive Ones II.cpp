/*Given a binary array, find the maximum number of consecutive 1s in this array if you can flip at most one 0.
Example 1:
Input: [1,0,1,1,0]
Output: 4
Explanation: Flip the first zero will get the the maximum number of consecutive 1s.
After flipping, the maximum number of consecutive 1s is 4.*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, cur = 0, cnt = 0;
        for (int num : nums) {
            ++cnt;
            if (num == 0) {
                cur = cnt;
                cnt = 0;
            } 
            res = max(res, cnt + cur);
        }
        return res;
    }
};

//Solution 2: Sliding window
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, count = 0, left = 0, k = 1;		
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) ++count;
            while (count > k) {
                if (nums[left++] == 0) --count;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};

//Solution 3
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, left = 0, k = 1;
        queue<int> q;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) q.push(right);
            if (q.size() > k) {
                left = q.front() + 1; q.pop();
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};