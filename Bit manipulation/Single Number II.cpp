/*Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. 
Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int t1 = 0;
        int t2 = 0;
        int t3 = 0;
        
        for (int i = 0; i < n; i++){
            t1 = t1 ^ nums[i];
            t2 = t2 | ((t1^nums[i]) & nums[i]);
            t3 = ~(t1 & t2);	// not threes
            t1 = t1 & t3;		// clear 
            t2 = t2 & t3;		// clear
        }
        
        return t1;
    }
};
//
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        auto r = 0, k = 3;
        for (auto i = 0; i < 32; ++i) {
            auto mask = 1 << i, cnt = 0;

            for (auto num : nums)
                cnt += bool(num & mask);

            if (cnt % k)
                r |= mask;
        }
        return r;
    }
};
//Suppose given "every element appears k times except for one", we just need an array cnt[k], where every cnt[i] shows 
//the bits on which (mk+i) 1 bits have been found (m∈N).
//Besides, the single number may appear once, twice, ...(k-1) times, using "return ~cnt[0]" can well solve this.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size()<3) return nums[0];
        int cnt[3]={~0,0,0};
        int cntTemp[3];
        for (int n:nums) {
            cntTemp[0]=(cnt[0]&(~n))|(cnt[2]&n); //3m+0 = (3m+0)+0 or (3m+2)+1
            cntTemp[1]=(cnt[1]&(~n))|(cnt[0]&n); //3m+1 = (3m+1)+0 or (3m+0)+1
            cntTemp[2]=(cnt[2]&(~n))|(cnt[1]&n); //3m+2 = (3m+2)+0 or (3m+1)+1
            swap(cnt,cntTemp);
        }
        return cnt[1]; //bits that have (3m+1) 1bits
    }
};


// Method 2
/*
class Solution {
public:
    int singleNumber(int nums[], int n) {
        int count[32] = {0};
        int result = 0;
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < n; j++) {                 
                if ((nums[j] >> i) & 1) {
                    count[i]++; // sum up the bits
                }
            }
            result |= ((count[i] % 3) << i); // restore
        }
        return result;
    }
}; */

