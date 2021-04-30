vector<int> twoSum(vector<int> sums, int target)
{
	unordered_map<int, int> dict;
	vector<int> result;
	
	for(int i = 0; i < sums.size(); i++)
	{
		if(dict.find(target - sums[i]) != dict.end())
		{
			result.push_back(dict[target - nums[i]]);
			result.push_back(i);
			break;
		}
		else
			dict[nums[i]] = i;
	}
	return result;
}