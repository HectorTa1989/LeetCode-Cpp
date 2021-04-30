vector<int> Numbersofsmaller(vector<int> nums)
{
	vector<int> arr(nums.begin(), nums.end());
	unordered_map<int, int> m;
	
	sort(arr.begin(), arr.end());
	for(int i = 0; i < arr.size(); i++)
	{
		if(m.find(arr[i]) == m.end())
			m[arr[i]] = i;
	}
	for(int i = 0; i < nums.size(); i++)
		nums[i] = m[nums[i]];
		
	return nums;
}