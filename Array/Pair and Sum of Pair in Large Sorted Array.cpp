//Given a very large array of integers (sorted, no duplicates), ouput all the possible combinations (a, b, c) such that a + b = c. No other data storage should be used.
//Example:
//[1, 2, 3, 4, 5, 7, 8, 9, 11, ....]
//Output: [[1, 2, 3], [1, 3, 4], [1, 7, 8], [1, 8, 9], [2, 3, 5],...]

vector<int> PairSum(vector<int> nums)
{
	int i, j = 0, k = i-1;
	int n = nums.size();
	vector<int> ans;
	
	for(i = 2; i < n; i++)
	{
		if(nums[j] + nums[k] > nums[i])
			k--;
		else if(nums[j] + nums[k] < nums[i])
			j++;
		else
		{
			ans.push_back({nums[j], nums[k], nums[i]});
			j++;
			k--:
		}
	}
	return ans;
}

//Binary search:
vector<int> PairSum(vector<int> nums)
{
    vector<int> result;
    for (int i = 0; i < nums.length - 2; i++) {
        for (int j = i + 1; j < nums.length - 1; j++) {
            int target = nums[i] + nums[j];
            int idx = Arrays.binarySearch(nums, j + 1, nums.length, target);
            if (idx >= 0) {
                result.add(Arrays.asList(nums[i], nums[j], nums[idx]));
            }
        }
    }
    return result;
}
