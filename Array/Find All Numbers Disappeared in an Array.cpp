/*Mark the numbers that have appeared to be negative. Examples
[4,3,2,7,8,2,3,1]

[4,3,2,-7,8,2,3,1], index=0
[4,3,-2,-7,8,2,3,1], index=1
[4,-3,-2,-7,8,2,3,1], index=2
[4,-3,-2,-7,8,2,-3,1], index=3
[4,-3,-2,-7,8,2,-3,-1], index=4
[4,-3,-2,-7,8,2,-3,-1], index=5
[4,-3,-2,-7,8,2,-3,-1], index=6
[-4,-3,-2,-7,8,2,-3,-1], index=7
Finally, 8 and 2 are positive, and the numbers are 5 and 6.*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int index, size;
        vector<int> res;
        
        size = nums.size();
        for(index = 0;index < size;index++){
            int val = abs(nums[index]) - 1;
            if(nums[val] > 0) nums[val] = - nums[val];
        }
        
        for(index = 0;index < size;index++)
            if(nums[index] > 0)
                res.push_back(index + 1);
        
        return res;
    }
};
//Since the number is between 1 and n, the repeated number will occupy part of the space. Therefore, exchange the number and the value of the corresponding position, 
//and then visit the array again to find all the values ​​that do not match the position index value. for example
//[4,3,2,7,8,2,3,1]，4 will be exchanged with 7
//[7,3,2,4,8,2,3,1]，7 will be exchanged with 1 
//[1,3,2,4,8,2,3,7]，1 has been put to the correct position 
//exchange [3,2,4,8,2,3,7] in sequence
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int index, size;
        vector<int> res;
        
        size = nums.size();
        for(index = 0;index < size;index++)
            while(nums[index] != index + 1 && nums[index] != nums[nums[index] - 1])
                swap(nums[index], nums[nums[index] - 1]);
        
        for(index = 0;index < size;index++)
            if(nums[index] != index + 1)
                res.push_back(nums[index]);
            
        return res;
    }
};
//
vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> res;
        
        for(int i=0; i<n; i++)
        {
            if(nums[abs(nums[i]) - 1] < 0) continue;
            nums[abs(nums[i]) - 1] =  -nums[abs(nums[i]) - 1];
        }
        
        for(int i=0; i<n; i++)
        {
            if(nums[i] > 0) res.push_back(i+1);
        }
        
        return res;
    }

//Algorithm
//We know that all the values are between 1 and the size of the array, so the idea is to use the indices of the original array to represent the values that are found in the array.
//We know that all the values in the array are positive, so we can signal the presence of a value by changing its index 
(or better still, like in my implementation, the index minus 1, to avoid the 'special case' of values that equal n, which has no vector element) to be negative.
//We then loop over the vector, and any positive index indicates that the value (index + 1) does not appear in the vector, so we add it to the list to return.
//Complexity
//We loop over the array twice, so the running time is O(2N), which is O(N).
//We use the original vector for keeping count of which values appear in the array, so we use O(1) space.
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> results;
        
        // Set contents of all indices (minus 1) that appear in the array to be negative
        for (int i = 0; i < nums.size(); ++i)
        {
			// Note that we have to use the absolute value in the next 2 lines, to avoid trying to access a negative index in some cases
            if (nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] *= -1;
        }
        
        // A positive element means that the element (index + 1) does not appear in the array, so save it
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] > 0)
                results.push_back(i + 1);
        
        return results;
    }
};