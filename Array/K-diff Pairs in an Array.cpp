//Sort and then perform two scans in parallel, maintaining a difference as close to k as possible between the two scan positions. 
//In other words, advance the leading scan when the difference is smaller than k, and advance the lagging scan when the difference is greater. 
//This way we either find a pair or scan through the list and report that no pair exists. Time complexity: O(n log n).

class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		sort(nums.begin(),nums.end());
		int fast=1;
		int slow=0;
		int ans=0;
		while(slow<nums.size() && fast<nums.size()){
			if(nums[fast]-nums[slow]==k){
				ans++;
				fast++;
				slow++;
				while(fast<nums.size() && nums[fast]==nums[fast-1]){
					fast++;
				}
			}
			else if(nums[fast]-nums[slow]>k){
				slow++;  
				if(fast-slow==0){
					fast++;}
			}
			else{      
				fast++;
			}         
		}
		return ans;

	}
};

// Method 2
int findPairs(vector<int> &nums, int k)
{
	int n = nums.size();
	int i = 0, j = 0;
	
	sort(nums.begin(), nums.end());
	
	for(i = 0; i < n; i++)
	{
		j = max(i+1, j);
		while(i < n - 1 && nums[i] == nums[i + 1])
			i++;
			
		if(nums[j] - nums[i] > k)
			i++;
		else if(nums[j] - nums[i] < k)
			j++;
		else
			res++;
	}
	return res;
}

//Hash
int findPairs(vector<int> &nums, int k)
{
	unordered_map<int, int> data;
	int res = 0;
	
	if (k<0) return 0;
	
	for(int x:nums)
		data[x]++;
	for(auto it = data.begin(); it != data.end(); it++)
	{
		if(k == 0)
		{
			int x = it->second;
			if(x>1)
				res++;
		}
		else
		{
			if(data.find(it->first - k) != data.end())
				res++;
		}
	}
	return res;
}