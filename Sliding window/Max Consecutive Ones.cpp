/*Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.*/

//Runtime: 120 ms, faster than 5.79% of C++ online submissions for Max Consecutive Ones.
//Memory Usage: 36.2 MB, less than 6.06% of C++ online submissions for Max Consecutive Ones.
class Solution {
public:
int findMaxConsecutiveOnes(vector<int>& nums) {
	int max = 0, i = 0;
	while (i < nums.size())
	{
		while (i < nums.size() && nums[i] == 0)i++;
		int subMax = 0;
		while (i < nums.size() && nums[i] == 1)
		{
			subMax++;
			i++;
		}
		if (subMax > max) max = subMax;
	}
	return max;
}
};

//Runtime: 104 ms, faster than 5.79% of C++ online submissions for Max Consecutive Ones.
//Memory Usage: 36.3 MB, less than 6.06% of C++ online submissions for Max Consecutive Ones.
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curWindow = 0, maxWindow = 0;
        for(auto x:nums)
        {
            if(x == 1)
                curWindow++;
            else
            {
                if(curWindow > maxWindow)
                    maxWindow = curWindow;
                curWindow=0;             
            }
        }
        maxWindow = max(curWindow, maxWindow);
        return maxWindow;
    }
};