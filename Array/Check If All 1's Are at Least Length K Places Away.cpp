//Given an array nums of 0s and 1s and an integer k, return True if all 1's are at least k places away from each other, otherwise return False.
//Input: nums = [1,0,0,0,1,0,0,1], k = 2
//Output: true
//Explanation: Each of the 1s are at least 2 places away from each other.

// 
class Solution {
public:
  bool kLengthApart(vector<int>& nums, int k) {
    int d = k + 1; // distant enough
    for (int n : nums) {
      if (n == 0) {
        ++d;
      } else {
        if (d < k) return false;
        d = 0;
      }
    }
    return true;
  }
};

//
bool kLengthApart(vector<int>& nums, int k) {
	int start = -1;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == 1) {
			if (start == -1)
				start = i;
			else if (i - start <= k)
				return false;

			start = i;
		}
	}
	return true;
}

//
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prev=-1,pos; // prev stores previous occcuring 1s index and pos stores current 1s index
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                pos=i;
                if((pos-prev)<=k && prev!=-1) // prev=-1 takes care for the first encountered one
                    return false;
                prev=pos;
            }
        }
        return true;
    }
};