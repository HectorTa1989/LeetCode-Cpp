class Solution {
    int missingNumber(vector<int>& nums) {
        int missing = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            missing ^= i ^ nums[i];
        }
        return missing;
    }
};
//
class Solution {
public:
int missingNumber(vector<int>& nums) {

    int sum=0, s=nums.size();
    for(int i=0;i<nums.size();i++)
    {
        sum+=nums[i];
    }
    
    return (s*(s+1)/2)-sum;
    
}
};
//
class Solution {
    int missingNumber(vector<int>& nums) {
        unordered_set<int> numSet;
        for (int num : nums) numSet.insert(num);

        int expectedNumCount = nums.size() + 1;
        for (int number = 0; number < expectedNumCount; number++) {
            if (numSet.find(number) == numSet.end()) {
                return number;
            }
        }
        return -1;
    }
};