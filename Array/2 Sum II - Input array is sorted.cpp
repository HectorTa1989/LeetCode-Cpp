/*Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. 
Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution and you may not use the same element twice.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2*/
//Two pointers
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //vector<int> res;
        int l = 0, r = numbers.size()-1;
        while(l <= r)
        {
            int t = numbers[l] + numbers[r];
            if(t > target)
                r--;
            else if(t < target)
                l++;
            else
                return {l+1, r+1};
        }
        return {};
    }
};

//Binary Search
//time complexity: O(NlogN) in worst (if elements are together in right extreme)
//space complexity: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int N = nums.size();
        for(int i=0;i<N-1;i++){
            int lo = i+1;
            int hi = N;
            while(lo<hi){
                int mid = lo + (hi-lo)/2;
                if(nums[mid]==target-nums[i]) return {i+1,mid+1};
                else if(nums[mid]>=target-nums[i]) hi=mid;
                else lo = mid+1;
            }
            if(lo!=nums.size() && nums[lo]==target-nums[i]) return {i+1,lo+1};
        }
        return {}; // not found
    }
};

//Binary Search 2
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        const int n = numbers.size();
        for (int i = 0; i < n; ++i) {
            int l = i + 1;
            int r = n;
            int t = target - numbers[i];
            while (l < r) {
                int m = l + (r - l) / 2;
                if (numbers[m] == t)
                    return {i + 1, m + 1};
                else if (numbers[m] < t)
                    l = m + 1;
                else
                    r = m;
            }
        }
        return {};
    }
};