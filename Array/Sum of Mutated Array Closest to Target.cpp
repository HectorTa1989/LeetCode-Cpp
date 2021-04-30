class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int low = 0, high = INT_MIN;
        for(int num :arr) {
            if(num > high) high = num;
        }
        // template 3
        int mid = 0;
        while(low + 1 < high) {
            mid = low + (high-low)/2;
            int sum = helper(arr, mid);
            if(sum == target) return mid;
            else if(sum > target) high = mid;
            else low = mid;
        }
        // now low + 1 == high
        return abs(helper(arr, low)-target) <= abs(helper(arr, high)-target) ? low : high;
    }
    int helper(vector<int>& arr, int value) {
        int sum = 0;
        for(int num : arr) {
            sum += (num > value) ? value : num;
        }
        return sum;
    }
};