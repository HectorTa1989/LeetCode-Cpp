//https://leetcode.com/problems/create-target-array-in-the-given-order/

vector<int> createTargetArray(vector<int> nums, vector<int> index)
{
	vector<int> ans;
	
	int n = nums.size();
	if(n == 1)
		return nums;
		
	for(int i = 0; i < n; i++)
	{
		ans.insert(ans.begin() + index[i], nums[i]);
	}
	return ans;
}