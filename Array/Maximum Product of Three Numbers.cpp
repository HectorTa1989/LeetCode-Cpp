class Solution {
public:
    int maximumProduct(vector<int>& nums) {
	
	     // Answer is either made up of two negative number and a positive number
        // or three positive numbers. We can isolate these 5 numbers of interest in O(1)
		// time with a sorted array.

        sort(nums.begin(), nums.end()); // n log(n) time complexity
        return max(nums[0] * nums[1] * nums[nums.size() - 1], nums[nums.size() - 3] * nums[nums.size() - 2] * nums[nums.size() - 1]);
    }
};
//Inspired by solution to Third Maximun number problem.
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = nums[0], max2 = nums[1], max3 = nums[2];
        if (max2 < max1) swap(max2, max1);
        if (max3 < max1) swap(max3, max1);
        if (max3 < max2) swap(max3, max2);
        int min1 = max2, min2 = max1;
        for (int i = 3; i < nums.size(); i++) {
            if (nums[i] > max3) {
                max1 = max2;
                max2 = max3;
                max3 = nums[i];
            } else if (nums[i] > max2) {
                max1 = max2;
                max2 = nums[i];
            } else if (nums[i] > max1) {
                max1 = nums[i];
            }
            
            if (nums[i] < min2) {
                min1 = min2;
                min2 = nums[i];
            } else if (nums[i] < min1) {
                min1 = nums[i];
            }
        }
        
        if (max3 <= 0) return max1 * max2 * max3;
        return max(max1*max2*max3, max3*min1*min2);
    }
};
//
int maximumProduct(vector<int>& nums) {
        
        int max1 = -1000;
        int max2 = -1000;
        int max3 = -1000;
        
        int min1 = 1000;
        int min2 = 1000;
        
        int maxproduct = INT_MIN;
        
        for(int i=0; i<nums.size(); i++){
            
            if(nums[i] < min1){
                min2 = min1;
                min1 = nums[i];       
            }
            else if(nums[i] < min2){
                min2 = nums[i];
            }
            if( nums[i] > max1){
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }
            
            else if(nums[i] > max2){
                max3 = max2;
                max2 = nums[i];

            }
            else if(nums[i] > max3){
                max3 = nums[i];
            }
            maxproduct = max1 * max2 * max3;
        }
		
        return max1*max2*max3 > max1*min1*min2 ? max1*max2*max3 : max1*min1*min2;
    }