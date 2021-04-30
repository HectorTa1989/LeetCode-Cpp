//Runtime: 8 ms, faster than 89.81% of C++ online submissions for 3Sum Closest.
//Memory Usage: 6.4 MB, less than 100.00% of C++ online submissions for 3Sum Closest.

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff;
        int min_diff = INT_MAX;
        int n = nums.size();
        int res;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n-2; i++)
        {
            int left = i+1, right = n-1;
            while(left<right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == target)   return target;
                if(sum > target)
                    right--;
                else
                    left++;
                
                diff = abs(sum - target);
                
                if(diff < min_diff)                    
                {
                    min_diff = diff;
                    res = sum;
                }
                
            }
        }
        return res;
        
    }
};

//
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX, res = 0;
        for(int i = 0; i < nums.size() - 2; i++){
            int lo = i + 1, hi = nums.size() - 1;
            while(lo < hi){
                int sum = nums[i] + nums[lo] + nums[hi];
                if(sum == target) return target;
                if(abs(sum - target) < diff) diff = abs(sum - target), res = sum;
                (sum > target) ? hi-- : lo++;
            }
        }
        return res;
    }
};

//
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int i = 0;
        int n = nums.size();
        int left = 0;
        int right = 0;
        int ret = 0;
        int sum = 0;
        int diff = 0;
        int minDiff = INT_MAX;
    
        sort(nums.begin(), nums.end());
        
        ret = nums[0] + nums[1] + nums[2];
        minDiff = abs(ret - target);
        
        for (i = 0; i < n-2; i++)
        {
            left = i + 1;
            right = n - 1;
            
            while (left < right)
            {
                sum = nums[i] + nums[left] + nums[right];
                diff = abs(sum - target);

                if (diff == 0)
                    return sum;

                if (diff < minDiff)
                {
                    minDiff = diff;
                    ret = sum;
                }
                
                if (sum - target > 0)
                    right--;
                else
                    left++;
            }
        }
        
        return ret;
    }
};