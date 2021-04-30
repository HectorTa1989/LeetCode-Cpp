https://leetcode.com/problems/remove-element/solution/

int removeElements(vector<int> nums, int val)
{
	int i = 0;
	for(int j = 0; j < nums.size(); j++)
	{
		if(nums[j] != val)
		{
			nums[i] = nums[j];
			i++;
		}
	}
	return i;
}

//Method 2 : Two Pointers - when elements to remove are rare
int removeElements(vector<int> nums, int val)
{
	int i = 0;
	int n = nums.size();
	while(i < n)
	{
		if(nums[i] == val)
		{
			nums[i] = nums[n - 1];
			n--;
		}
		else
			i++;
	}
	return n;
}

//Method 3
int removeElement(vector<int>& nums, int val) {
    return std::distance(nums.begin(), std::remove(nums.begin(), nums.end(), val));
}

//Method 4
int removeElement(vector<int>& nums, int val) {
        auto itr = nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size();
    }