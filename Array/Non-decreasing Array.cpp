/*Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.
We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).

Example 1:
Input: nums = [4,2,3]
Output: true
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.

Example 2:
Input: nums = [4,2,1]
Output: false
Explanation: You can't get a non-decreasing array by modify at most one element.

Constraints:
1 <= n <= 10 ^ 4
- 10 ^ 5 <= nums[i] <= 10 ^ 5*/

bool checkPossibility(vector<int>& nums) {
	if (nums.size() < 2) return true;

	for (int i = 0, mods = 0; i <= nums.size()-2; ++i) {
		if (nums[i] > nums[i+1]) {
			++mods; // we need to modify either the current element or the next element
			
			if (mods > 1) return false;
			
			if ((i == 0 or nums[i-1] <= nums[i+1]) and (i == nums.size()-2 or nums[i+1] <= nums[i+2])) {
				// if these conditions hold, we make the current element as small as the next element
				// i.e., if before, the array was: w, x, y, z and w < x > y <= z & w < y, then after: w < y = y <= z
				nums[i] = nums[i+1];
			} else { 
				// otherwise, we make the next element as big as current element, and we will see in the next iteration if there is an issue
				nums[i+1] = nums[i];
			}
		}
	}
	return true;
}

//
class Solution {   
public:
    bool checkPossibility(vector<int>& n)
    {
        bool flg = true;
        
        for (auto i=1; i<n.size(); i++)
            if (n[i]<n[i-1])
            {               
                auto res = (i==1 || n[i-2]<=n[i]) && (i==n.size()-1 || n[i]<=n[i+1]); 
                res |= i==n.size()-1 || n[i-1]<=n[i+1];
                
                if (!flg || !res)
                    return false;
                flg = false;
            }
        return true;
    }
};
//count1 is the number of modifications needed for changing the higher value with lower index. for example: 1,2,3,2,4. when 3>2, you have to modify 3 to 2 to keep one modification.
//count2 is the number of modifications needed for changing the lower value with higher index. for example: 1,2.3,1,4, when 3>1, you have to modify 1 to (3 or 4) 
//to keep only on modification.
//the algorithm below is to test for both cases, and return true if any type of modification works, and false if neither way works.

    bool checkPossibility(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        for(int i = 1; i<nums.size() && (count1<2 || count2<2); ++i)
        {
            if(nums[i-1] > nums[i])
            {
                count1++;
                count1 += (i > 1) && nums[i-2] > nums[i];
                count2++;
                count2 += (i+1 < nums.size()) && nums[i+1] < nums[i-1];
            }
        }
        return count1 < 2 || count2 < 2;
    }
/*
basic idea : we only have ONE chance to modify! 
Two cases: we may need to modify the previous larger number nums[i-1], or the latter smaller number nums[i](current number)
3 examples:
4，2，3
-1，4，2，3
2，3，3，2，4

Rule is : (1) if nums[i-2] doesn't exist, modify previous number nums[i-1] to nums[i]
              (2) else if nums[i-2] exists, and nums[i-2] < nums[i], nums[i-1] is too large, modify nums[i-1] to nums[i+1], --chance
              (3) else if nums[i-2] exists, and nums[i-2] > nums[i], nums[i] is too small, modify nums[i] to nums[i-1]

Once ctr == 0 but we need to modify, return false
*/
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int chance = 1;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i-1] <= nums[i]) {
                continue;
            }
            else {
                // nums[i-1] > nums[i]
                if(chance == 0) {
					// we have used our chance, return false
                    return false;
                } 
                else {
                    // we have one chance! now we know that nums[i-2](may exsit) <= nums[i-1] > nums[i]
                    if(i-2 < 0) {
                        // nums[i-2] doesn't exist, modify nums[i-1] and makes nums[i-1] == nums[i]
                        nums[i-1] = nums[i];
                    }
                    else {
                        // i-2 >= 0, nums[i-2] exists!
                        if(nums[i-2] < nums[i]) {
                            // nums[i-1] is too large
                            nums[i-1] = nums[i];
                        }
                        else {
                            // nums[i] is too small
                            nums[i] = nums[i-1];
                        }
                    }
                    --chance;
                }
            }
        }
        return true;
    }
};

//
bool checkPossibility(std::vector<int>& nums) 
{
    int idx = 0;
    bool flg = false;
    
    for(size_t i = 0; i < nums.size() - 1; i++)
    {
        if(nums[i] > nums[i+1])
        {
            idx = i;
            flg = true;
            break;
        }
    }
    
    if(flg)
    {
        std::vector<int> tmp1(nums);
        std::vector<int> tmp2(nums);
        
        int x1 = nums[idx];
        int x2 = nums[idx+1];
        
        tmp1[idx] = tmp1[idx+1];
        tmp2[idx+1] = tmp2[idx];
        
        return std::is_sorted(tmp1.begin(), tmp1.end()) ||
            std::is_sorted(tmp2.begin(), tmp2.end());
    }
    
    return std::is_sorted(nums.begin(), nums.end());
}