//https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/discuss/347871/6-lines-C%2B%2B-clean-solution.

// Method 1
int removeDuplicates(vector<int>& nums) {
    int n = nums.size(), count = 0;
    for (int i = 2; i < n; i++)
        if (nums[i] == nums[i - 2 - count]) count++;
        else nums[i - count] = nums[i];
    return n - count;
}


//Method 2
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (auto e : nums) {
            if (i < 2 || e > nums[i - 2])
                nums[i++] = e;
        }
        return i;
    }
};

// Method 3
int removeDuplicates(vector<int> nums)
{
	int n = nums.size();
	if(n == 0 || n == 1)
		return n;
	int j = 0;
	for(int i = 0; i < n - 1; i++)
		if(arr[i] != arr[i+1])
			arr[j++] = arr[i];
		
	arr[j++] = arr[n - 1];
	
	return j;
}

//Method 4
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 3) return nums.size();
        int i = 2, j = 2;
        while(j < nums.size())
            if(nums[j] > nums[i - 2]) nums[i++] = nums[j++];
            else j++;
        return i;
    }
};