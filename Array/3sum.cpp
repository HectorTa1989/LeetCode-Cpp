class Solution {
public:

	vector<vector<int>> threeSum(vector<int>& nums)	{
		std::sort(nums.begin(), nums.end());
		vector<vector<int>> ret;
		int len = nums.size();
		if(len<3) return ret;

		for (int i = 0; i < len - 2; ++i){
			if (i>0 && nums[i] ==nums[i-1]) continue;//to avoid duplicates through first value
			if(nums[i]+nums[i+1]+nums[i+2]>0) break;//no solution
			if(nums[i]+nums[len-2]+nums[len-1]<0) continue;//"i" is too small

			int left = i + 1, right = len - 1;
			while(left < right){
				int sum = nums[i] + nums[left] + nums[right];
				if (sum > 0) --right;
				else if (sum < 0) ++left;
				else 
				{
					ret.push_back({ nums[i], nums[left], nums[right] });
					do{ left++; }while(nums[left] == nums[left-1] && left < right);//to avoid duplicates through second value
					do{ right--; }while(nums[right] == nums[right+1] && left < right);//to avoid duplicates through third value
				}
			}
		}
		return ret;
	}
};