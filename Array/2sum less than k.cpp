int 2SumlessthanK(vector<int> nums, int k)
{
	int n = nums.size(), l = 0, r = n-1;
	int ans = 0;
	while(l<r)
	{
		int sum=nums[l] + nums[r];
		if(sum < k)
		{
			ans = max(ans, sum);
			l++;
		}
		else
			r--;
	}
	return ans;
}