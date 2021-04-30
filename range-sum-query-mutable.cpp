

class NumArray
{
	vector<int> cur;
	
	public:
		NumArray(vector<int> nums)
		{
			int n = nums.size();
			for(int i = 0; i<n; i++)
				cur.push_back(nums[i]);
		}
		void Update(int i, int val)
		{
			cur[i] = val;
		}
		int sumRange(int i, int j)
		{
			int sum = 0;
			for(int a = i; a <= j; a++)
				sum += cur[a];
			return sum;
		}
};