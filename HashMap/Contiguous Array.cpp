/*Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> freq;
        int max_len = 0, count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            count += nums[i] == 1 ? 1 : -1;		// Count increases if element = 1 and reduces if element=0
            if (count == 0) {
                // if the count is 0, the maximum
                // will always be i + 1
                max_len = i + 1;
            } else if (freq.find(count) != freq.end()) {
                // if we already encountered the current count
                // the length between the first encounter and i
                // is a contiguous array of equal count
                max_len = max(max_len, i - freq[count]);
            } else {
                // if we haven't seen this count before
                // add it to the frequncy map
                freq[count] = i;
            }
        }
        
        return max_len;
    }
};

//Runtime: 116 ms, faster than 86.59% of C++ online submissions for Contiguous Array.
//Memory Usage: 20 MB, less than 41.67% of C++ online submissions for Contiguous Array.

int findMaxLength(vector<int>& nums) {
        
        int countOne = 0;
        int maxLen = 0;
        unordered_map<int, int> diff{{0,-1}};
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 1)
                countOne++;
            else
                countOne--;
            
            if(diff.find(countOne) != diff.end()) maxLen = max(maxLen, i - diff[countOne]);
            else diff[countOne] = i;
        }
        return maxLen;
    }