//Method 1: Binary Search
//Time complexity: O(logn)
//Space complexity: O1)
class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int l = 0, r = nums.size();
    while (l < r) {
      int m = l + (r - l) / 2;      
      if (nums[m] == target)
        return m;
      else if (nums[m] > target)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
};

// Method 2
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};

//Method 3
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        /// return index of first one that comp(item,target)==true, or nums.size() if not found
		/// comp is greater or equal to for lower_bound
		/// comp is greater for upper_bound
        int first=0, last=nums.size(), mid;
        while (first<last) {
            mid=first+((last-first)>>1); // first<=mid, mid<last
			/// if comp(item,target)==false, advance first
			// if(nums[mid]<=target) // for upper_bound
			if (nums[mid]<target) // for lower_bound
				first=mid+1; // first always increases
			else /// else recede last
				last=mid; // last always decreases (even last-first==1)
        }
        return first;
    }
};